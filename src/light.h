#pragma once

#include "math.h"

struct Base_Light 
{
    vec3 pos;

    // White is the standard color, but you can specify different colors in the constructor.
    vec3 ambient = vec3(1.0f, 1.0f, 1.0f);
    vec3 diffuse = vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = vec3(1.0f, 1.0f, 1.0f);

    float intensity = 1.0f;
};

struct Directional_Light : public Base_Light
{
    vec3 direction;

    Directional_Light(vec3 ambient_color, vec3 diffuse_color, vec3 specular_color, float light_intensity, vec3 dir);

    // Will default all colors to white.
    Directional_Light(float light_intensity, vec3 dir);
};