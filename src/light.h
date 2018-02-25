#pragma once

#include "math.h"

// This struct has the basic properties that every light has, other types will inherit from this.
struct Base_Light 
{
    vec3 pos;

    // White is the standard color, but you can specify different colors in the constructor.
    vec3 ambient  = vec3(1.0f, 1.0f, 1.0f);
    vec3 diffuse  = vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = vec3(1.0f, 1.0f, 1.0f);

    float intensity = 1.0f;
};

// Directional light is a type of light that ONLY cares about direction. The position of the light
// doesnt matter, which is also why it can't be set. The intensity and color can be set.
struct Directional_Light : public Base_Light
{
    vec3 direction;

    Directional_Light(vec3 ambient_color, vec3 diffuse_color, vec3 specular_color, float light_intensity, vec3 dir);

    // Will default all colors to white.
    Directional_Light(float light_intensity, vec3 dir);
};

// Point light shines in all directions, but they have a falloff and a maximum theta. Position
// does matter with this type.
struct Point_Light : public Base_Light
{
    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.32f;

    Point_Light(vec3 in_pos, vec3 in_ambient, vec3 in_diffuse, vec3 in_specular, float in_intensity);

    Point_Light(vec3 in_pos, float in_intensity);
};

struct Spot_Light : public Base_Light
{
    vec3 direction;

    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;

    float inner_cutoff;
    float outer_cutoff;

    Spot_Light(vec3 in_pos, vec3 in_dir, vec3 in_ambient, vec3 in_diffuse, vec3 in_specular, float in_intensity, 
               float inner_cutoff, float outer_cutoff);

    Spot_Light(vec3 in_pos, vec3 in_dir, float in_intensity, float inner_cutoff, float outer_cutoff);
};