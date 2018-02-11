#pragma once

#include <cmath>
#include <stdio.h>

extern const float pi;

struct vec3
{
    vec3(){}                              // This would create an empty vec3.
    vec3(float ix, float iy, float iz)   // Create vec3 with initial values.
    { x = ix; y = iy; z = iz; }
    float x, y, z;                       // The actual values.

    // All the declarations for the different operators with another vec3.
    vec3 operator+(const vec3& v2) const;
    vec3 operator-(const vec3& v2) const;
    vec3 operator*(const vec3& v2) const;
    vec3 operator/(const vec3& v2) const;

    // All the declarations for the different operators with a float.
    vec3 operator+(const float& f1) const;
    vec3 operator-(const float& f1) const;
    vec3 operator*(const float& f1) const;
    vec3 operator/(const float& f1) const;
};

const float* value_ptr(const vec3& v);

void math_print(const vec3& v);

float dot(const vec3& v1, const vec3& v2);

vec3 cross(const vec3& v1, const vec3& v2);

float len(const vec3& v1);

float len2(const vec3& v1);

vec3 normalize(const vec3& v1);

struct vec4
{
    vec4(){}                                         // This would create an empty vec4.
    vec4(float ix, float iy, float iz, float iw)    // Create vec4 with initial values.
    { x = ix; y = iy; z = iz; w = iw;}
    vec4(vec3 v1, float f)
    { x = v1.x; y = v1.y; z = v1.z; w = f;}

    float x, y, z, w;                               // The actual values.

    // All the declarations for the different operators with another vec4.
    vec4 operator+(const vec4& v2) const;
    vec4 operator-(const vec4& v2) const;
    vec4 operator*(const vec4& v2) const;
    vec4 operator/(const vec4& v2) const;

    // All the declarations for the different operators with a float.
    vec4 operator+(const float& f1) const;
    vec4 operator-(const float& f1) const;
    vec4 operator*(const float& f1) const;
    vec4 operator/(const float& f1) const;
};

const float* value_ptr(const vec4& v);

void math_print(const vec4& v);

float dot(const vec4& v1, const vec4& v2);

float len(const vec4& v1);

float len2(const vec4& v1);

vec4 normalize(const vec4& v1);

struct mat4
{
    mat4(){}
    mat4(vec4 v1, vec4 v2, vec4 v3, vec4 v4)
    {r1 = v1; r2 = v2; r3 = v3; r4 = v4;}

    // Store the for different rows in vec4.
    vec4 r1 = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    vec4 r2 = vec4(0.0f, 1.0f, 0.0f, 0.0f); 
    vec4 r3 = vec4(0.0f, 0.0f, 1.0f, 0.0f);
    vec4 r4 = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    // Declarations of operators.
    mat4 operator+(const mat4& m2) const;
    mat4 operator-(const mat4& m2) const;
    mat4 operator*(const mat4& m2) const;
    mat4 operator/(const mat4& m2) const;

    vec4 operator*(const vec4& v1) const;
};

float to_radians(float degrees);

float to_degrees(float radians);

void math_print(const mat4& m);

mat4 translate(const mat4& m1, const vec3& v1);

mat4 scale(const mat4& m1, const vec3& v1);

mat4 rotate(const mat4& m1, const float& radians, const vec3& v1);

mat4 perspective_lh(const float& fov, const float& aspect_ratio, const float& near_plane, const float& far_plane);

mat4 perspective_rh(const float& fov, const float& aspect_ratio, const float& near_plane, const float& far_plane);

mat4 look_at(const vec3& right, const vec3& up, const vec3& direction, const vec3& position);

const float* value_ptr(const mat4& m1);