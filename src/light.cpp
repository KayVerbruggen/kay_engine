#include "light.h"

Directional_Light::Directional_Light(vec3 position, vec3 light_color, float light_intensity, vec3 dir)
{
    pos = position;
    color = light_color;
    intensity = light_intensity;
    direction = dir;
}