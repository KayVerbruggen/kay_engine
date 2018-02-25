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

struct Point_Light
{
    Base_Light base;
    
    float constant;
    float linear;
    float quadratic;
};

struct Spot_Light
{
    Base_Light base;
    vec3 direction;

    float constant;
    float linear;
    float quadratic;

    float inner_cutoff;
    float outer_cutoff;
};

uniform sampler2D texture_sampler;
uniform Spot_Light spot;
uniform vec3 view_pos;

vec4 calc_dir_light(Directional_Light dl)
{
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

    return diffuse_color * vec4(diffuse + specular, 1.0);
}

vec4 calc_point_light(Point_Light pl)
{
    // Diffuse
    vec4 diffuse_color = texture(texture_sampler, tex_coord);
    vec3 n = normalize(normal);
    vec3 light_dir = normalize(pl.base.pos - position);
    float diff = max(dot(n, light_dir), 0.0);
    vec3 diffuse = diff * pl.base.diffuse * pl.base.intensity;

    // Specular
    float specular_strength = 0.3;
    vec3 view_dir = normalize(view_pos - position);
    vec3 reflect_dir = reflect(light_dir, n);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    vec3 specular = specular_strength * spec * pl.base.specular;

    // Attenuation
    float dist = length(pl.base.pos - position);
    float attenuation = 1.0 / (pl.constant + pl.linear * dist + pl.quadratic * (dist*dist));

    // Apply the attenuation.
    diffuse *= attenuation;
    specular *= attenuation;

    return diffuse_color * vec4(diffuse + specular, 1.0);
}

vec4 calc_spot_light(Spot_Light sl)
{
    vec3 dir = normalize(sl.base.pos - position);
    // Check if it is within the maximum range(aka cutoff).
    float theta = dot(dir, normalize(-sl.direction));
    if(theta > sl.outer_cutoff)
    {
        // Diffuse
        vec4 diffuse_color = texture(texture_sampler, tex_coord);
        vec3 n = normalize(normal);
        float diff = max(dot(n, -sl.direction), 0.0);
        vec3 diffuse = diff * sl.base.diffuse * sl.base.intensity;

        // Specular
        float specular_strength = 0.3;
        vec3 view_dir = normalize(view_pos - position);
        vec3 reflect_dir = reflect(sl.direction, n);
        float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
        vec3 specular = specular_strength * spec * sl.base.specular;

        // Attenuation
        float dist = length(sl.base.pos - position);
        float attenuation = 1.0 / (sl.constant + sl.linear * dist + sl.quadratic * (dist*dist));

        // Apply the attenuation.
        diffuse *= attenuation;
        specular *= attenuation;

        // Make the light fade out towards the outer cutoff.
        float theta = dot(dir, normalize(-sl.direction));
        float epsilon = sl.inner_cutoff - sl.outer_cutoff;
        float intensity = clamp((theta - sl.outer_cutoff) / epsilon, 0.0, 1.0);

        // Apply the fade.
        diffuse *= intensity;
        specular *= intensity;

        return diffuse_color * vec4(diffuse + specular, 1.0);
    }
    else
    {
        // Ambient
        float ambient_strength = 0.1;
        vec3 ambient = ambient_strength * sl.base.ambient;
        return texture(texture_sampler, tex_coord) * vec4(ambient, 1.0);
    }
}

void main()
{    
    // Ambient
    float ambient_strength = 0.1;
    vec3 ambient = vec3(1.0, 1.0, 1.0) * ambient_strength;

    color = vec4(ambient.xyz, 1.0) * calc_spot_light(spot);
}