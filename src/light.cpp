#include "light.h"

Directional_Light::Directional_Light(vec3 ambient_color, vec3 diffuse_color, vec3 specular_color, float light_intensity, vec3 dir)
{
    // Position doesn't matter for the directional light.
    pos = vec3(0.0f, 0.0f, 0.0f);

    ambient = ambient_color;
    diffuse = diffuse_color;
    specular = specular_color;

    intensity = light_intensity;
    direction = dir;
}

Directional_Light::Directional_Light(float light_intensity, vec3 dir)
{
    // Position doesn't matter for the directional light.
    pos = vec3(0.0f, 0.0f, 0.0f);

    intensity = light_intensity;
    direction = dir;
}

Point_Light::Point_Light(vec3 in_pos, vec3 in_ambient, vec3 in_diffuse, vec3 in_specular, float in_intensity)
{
    pos = in_pos;

    ambient = in_ambient;
    diffuse = in_diffuse;
    specular = in_specular;

    intensity = in_intensity;
}

Point_Light::Point_Light(vec3 in_pos, float in_intensity)
{
    pos = in_pos;

    intensity = in_intensity;
}

Spot_Light::Spot_Light(vec3 in_pos, vec3 in_dir, vec3 in_ambient, vec3 in_diffuse, vec3 in_specular, float in_intensity, float in_inner_cutoff, float in_outer_cutoff)
{
    pos = in_pos;
    direction = in_dir;

    ambient = in_ambient;
    diffuse = in_diffuse;
    specular = in_specular;

    intensity = in_intensity;
    inner_cutoff = cos(to_radians(in_inner_cutoff));
    outer_cutoff = cos(to_radians(in_outer_cutoff));
}

Spot_Light::Spot_Light(vec3 in_pos, vec3 in_dir, float in_intensity, float in_inner_cutoff, float in_outer_cutoff)
{
    pos = in_pos;
    direction = in_dir;

    intensity = in_intensity;
    inner_cutoff = cos(to_radians(in_inner_cutoff));
    outer_cutoff = cos(to_radians(in_outer_cutoff));
}