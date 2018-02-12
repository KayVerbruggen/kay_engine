#shader vertex
#version 330 core
layout(location = 0) in vec4 in_pos;
layout(location = 1) in vec2 in_tex_coord;
layout(location = 2) in vec3 in_normal;

out vec2 tex_coord;
out vec3 normal;
out vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    position = vec3(model * in_pos);
    gl_Position = projection * view * vec4(position, 1.0);
    tex_coord = in_tex_coord;
    normal = (transpose(inverse(model)) * vec4(in_normal, 1.0)).xyz;
}

#shader fragment
#version 330 core

in vec2 tex_coord;
in vec3 normal;
in vec3 position;

out vec4 color;

struct Base_Light
{
    vec3 pos;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float intensity;
};

struct Directional_Light
{
    Base_Light base;
    vec3 direction;
};

uniform sampler2D texture_sampler;
uniform Directional_Light dir_light;
uniform vec3 view_pos;

vec4 calc_dir_light(Directional_Light dl)
{
    // Ambient
    float ambient_strength = 0.1;
    vec3 ambient = ambient_strength * dl.base.ambient;

    // Diffuse
    vec4 diffuse_color = texture(texture_sampler, tex_coord);
    vec3 n = normalize(normal); 
    float diff = max(dot(n, -dl.direction), 0.0);
    vec3 diffuse = diff * dl.base.diffuse * dl.base.intensity;

    // Specular
    float specular_strength = 0.3;
    vec3 view_dir = normalize(view_pos - position);
    vec3 reflect_dir = reflect(dl.direction, n);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    vec3 specular = specular_strength * spec * dl.base.specular;

    return diffuse_color * vec4(ambient + diffuse + specular, 1.0);
}

void main()
{
    color = calc_dir_light(dir_light);
}