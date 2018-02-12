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