#pragma once

#include "math.h"

struct Base_Light 
{
    vec3 pos;
    vec3 color;
    float intensity;
};

struct Directional_Light : public Base_Light
{
    vec3 direction;

    Directional_Light(vec3 position, vec3 light_color, float light_intensity, vec3 dir);
};