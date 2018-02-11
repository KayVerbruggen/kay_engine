#include "math.h"

// Some constant variables.
const float pi = 3.1415926;

const float* value_ptr(const vec3& v)
{ return &(v.x); }

void math_print(const vec3& v)
{ printf("%f %f %f \n\n", v.x, v.y, v.z); }

float dot(const vec3& v1, const vec3& v2)
{ return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z); }

vec3 cross(const vec3& v1, const vec3& v2)
{
    return vec3(  v1.y * v2.z - v1.z * v2.y,
                -(v1.x * v2.z - v1.z * v2.x),
                  v1.x * v2.y - v1.y * v2.x);
}

float len(const vec3& v1)
{
    float length = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z);
    return sqrt(length);
}

float len2(const vec3& v1)
{
    return (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z);
}

vec3 normalize(const vec3& v1)
{
    float length = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z);
    return (v1 / sqrt(length));
}

// All the implementations of the different operators with another vec3.
vec3 vec3::operator+(const vec3& v2) const
{ return vec3(x + v2.x, y + v2.y, z + v2.z); }

vec3 vec3::operator-(const vec3& v2) const
{  return vec3(x - v2.x, y - v2.y, z - v2.z); }

vec3 vec3::operator*(const vec3& v2) const
{  return vec3(x * v2.x, y * v2.y, z * v2.z); }

vec3 vec3::operator/(const vec3& v2) const
{  return vec3(x / v2.x, y / v2.y, z / v2.z); }

// All the implementations of the different operators with a float.
vec3 vec3::operator+(const float& f1) const
{  return vec3(x + f1, y + f1, z + f1); }

vec3 vec3::operator-(const float& f1) const
{  return vec3(x - f1, y - f1, z - f1); }

vec3 vec3::operator*(const float& f1) const
{ return vec3(x * f1, y * f1, z * f1); }

vec3 vec3::operator/(const float& f1) const
{ return vec3(x / f1, y / f1, z / f1); }

const float* value_ptr(const vec4& v)
{ return &(v.x); }

void math_print(const vec4& v)
{ printf("%f %f %f %f \n \n", v.x, v.y, v.z, v.w); }

float dot(const vec4& v1, const vec4& v2)
{ return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w); }

float len(const vec4& v1)
{
    float length = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w);
    return sqrt(length);
}

float len2(const vec4& v1)
{
    return (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w);
}

vec4 normalize(const vec4& v1)
{
    float length = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w);
    return (v1 / sqrt(length));
}

// All the implementations of the different operators with another vec4.
vec4 vec4::operator+(const vec4& v2) const
{ return vec4(x + v2.x, y + v2.y, z + v2.z, w + v2.w); }

vec4 vec4::operator-(const vec4& v2) const
{  return vec4(x - v2.x, y - v2.y, z - v2.z, w - v2.w); }

vec4 vec4::operator*(const vec4& v2) const
{  return vec4(x * v2.x, y * v2.y, z * v2.z, w * v2.w); }

vec4 vec4::operator/(const vec4& v2) const
{  return vec4(x / v2.x, y / v2.y, z / v2.z, w / v2.w); }

// All the implementations of the different operators with a float.
vec4 vec4::operator+(const float& f1) const
{  return vec4(x + f1, y + f1, z + f1, w + f1); }

vec4 vec4::operator-(const float& f1) const
{  return vec4(x - f1, y - f1, z - f1, w - f1); }

vec4 vec4::operator*(const float& f1) const
{ return vec4(x * f1, y * f1, z * f1, w * f1); }

vec4 vec4::operator/(const float& f1) const
{ return vec4(x / f1, y / f1, z / f1, w / f1); }

float to_radians(float degrees)
{ return (degrees * pi) / 180.0f; }

float to_degrees(float radians)
{ return (radians * 180.0f) / pi; }

void math_print(const mat4& m)
{
    printf("%f %f %f %f \n", m.r1.x, m.r1.y, m.r1.z, m.r1.w);
    printf("%f %f %f %f \n", m.r2.x, m.r2.y, m.r2.z, m.r2.w);
    printf("%f %f %f %f \n", m.r3.x, m.r3.y, m.r3.z, m.r3.w);
    printf("%f %f %f %f \n \n", m.r4.x, m.r4.y, m.r4.z, m.r4.w);
}


mat4 translate(const mat4& m1, const vec3& v1)
{
    mat4 result = m1;

    result.r1.w = v1.x + m1.r1.w;
    result.r2.w = v1.y + m1.r2.w;
    result.r3.w = v1.z + m1.r3.w;
    result.r4.w = m1.r4.w;

    return result;
}

mat4 scale(const mat4& m1, const vec3& v1)
{
    mat4 scaled = m1;

    scaled.r1.x *= v1.x;
    scaled.r2.y *= v1.y;
    scaled.r3.z *= v1.z;

    return scaled;
}

mat4 rotate(const mat4& m1, const float& radians, const vec3& v1)
{
    mat4 rotated = m1;

    float a = radians;
    float s = sin(a);
    float c = cos(a);

    vec3 temp = normalize(v1);

    rotated.r1.x = c + (temp.x*temp.x*(1-c));
    rotated.r1.y = (temp.x * temp.y * (1-c)) - (temp.z * s);
    rotated.r1.z = (temp.x * temp.z * (1-c)) + (temp.y * s);

    rotated.r2.x = (temp.y * temp.x * (1-c)) + (temp.z * s);
    rotated.r2.y = c + (temp.y * temp.y * (1-c));
    rotated.r2.z = (temp.y * temp.z * (1-c)) - (temp.x * s);

    rotated.r3.x = (temp.z * temp.x * (1-c)) - (temp.y * s);
    rotated.r3.y = (temp.z * temp.y * (1-c)) + (temp.x * s);
    rotated.r3.z = c + (temp.z * temp.z * (1-c));

    rotated.r4 = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    return rotated;
}

mat4 perspective_lh(const float& fov, const float& aspect_ratio, const float& near_plane, const float& far_plane)
{
    mat4 projection;

    float tan_half = tan(fov / 2.0f);

    projection.r1.x = 1.0f / (tan_half * aspect_ratio);
    projection.r2.y = 1.0f / tan_half;
    projection.r3.z = (far_plane + near_plane) / (far_plane - near_plane);
    projection.r3.w = (-2.0f * near_plane * far_plane) / (far_plane - near_plane);
    projection.r4.z = 1.0f;
    projection.r4.w = 0.0f;

    return projection;
}

mat4 perspective_rh(const float& fov, const float& aspect_ratio, const float& near_plane, const float& far_plane)
{
    mat4 projection;

    float tan_half = tan(fov / 2.0f);

    projection.r1.x = 1.0f / (tan_half * aspect_ratio);
    projection.r2.y = 1.0f / tan_half;
    projection.r3.z = -(far_plane + near_plane) / (far_plane - near_plane);
    projection.r3.w = (-2.0f * near_plane * far_plane) / (far_plane - near_plane);
    projection.r4.z = -1.0f;
    projection.r4.w = 0.0f;

    return projection;
}

mat4 look_at(const vec3& right, const vec3& up, const vec3& direction, const vec3& position)
{
    mat4 view;

    view.r1.x = right.x;
    view.r2.x = right.y;
    view.r3.x = right.z;

    view.r1.y = up.x;
    view.r2.y = up.y;
    view.r3.y = up.z;

    view.r1.z = direction.x;
    view.r2.z = direction.y;
    view.r3.z = direction.z;

    view.r1.w = -dot(right, position);
    view.r2.w = -dot(up, position);
    view.r3.w = -dot(direction, position);

    return view;
}

const float* value_ptr(const mat4& m1)
{
    return &(m1.r1.x);
}

mat4 mat4::operator+(const mat4& m2) const
{
    return mat4(r1 + m2.r1,
                r2 + m2.r2,
                r3 + m2.r3,
                r4 + m2.r4);
}

mat4 mat4::operator-(const mat4& m2) const
{
    return mat4(r1 - m2.r1,
                r2 - m2.r2,
                r3 - m2.r3,
                r4 - m2.r4);
}

mat4 mat4::operator*(const mat4& m2) const
{
    mat4 result;

    result.r1.x = (r1.x * m2.r1.x) + (r1.y * m2.r2.x) + (r1.z * m2.r3.x) + (r1.w * m2.r4.x);
    result.r1.y = (r1.x * m2.r1.y) + (r1.y * m2.r2.y) + (r1.z * m2.r3.y) + (r1.w * m2.r4.y);
    result.r1.z = (r1.x * m2.r1.z) + (r1.y * m2.r2.z) + (r1.z * m2.r3.z) + (r1.w * m2.r4.z);
    result.r1.w = (r1.x * m2.r1.w) + (r1.y * m2.r2.w) + (r1.z * m2.r3.w) + (r1.w * m2.r4.w);

    result.r2.x = (r2.x * m2.r1.x) + (r2.y * m2.r2.x) + (r2.z * m2.r3.x) + (r2.w * m2.r4.x);
    result.r2.y = (r2.x * m2.r1.y) + (r2.y * m2.r2.y) + (r2.z * m2.r3.y) + (r2.w * m2.r4.y);
    result.r2.z = (r2.x * m2.r1.z) + (r2.y * m2.r2.z) + (r2.z * m2.r3.z) + (r2.w * m2.r4.z);
    result.r2.w = (r2.x * m2.r1.w) + (r2.y * m2.r2.w) + (r2.z * m2.r3.w) + (r2.w * m2.r4.w);

    result.r3.x = (r3.x * m2.r1.x) + (r1.y * m2.r2.x) + (r1.z * m2.r3.x) + (r1.w * m2.r4.x);
    result.r3.y = (r3.x * m2.r1.y) + (r1.y * m2.r2.y) + (r1.z * m2.r3.y) + (r1.w * m2.r4.y);
    result.r3.z = (r3.x * m2.r1.z) + (r1.y * m2.r2.z) + (r1.z * m2.r3.z) + (r1.w * m2.r4.z);
    result.r3.w = (r3.x * m2.r1.w) + (r1.y * m2.r2.w) + (r1.z * m2.r3.w) + (r1.w * m2.r4.w);

    result.r4.x = (r4.x * m2.r1.x) + (r1.y * m2.r2.x) + (r1.z * m2.r3.x) + (r1.w * m2.r4.x);
    result.r4.y = (r4.x * m2.r1.y) + (r1.y * m2.r2.y) + (r1.z * m2.r3.y) + (r1.w * m2.r4.y);
    result.r4.z = (r4.x * m2.r1.z) + (r1.y * m2.r2.z) + (r1.z * m2.r3.z) + (r1.w * m2.r4.z);
    result.r4.w = (r4.x * m2.r1.w) + (r1.y * m2.r2.w) + (r1.z * m2.r3.w) + (r1.w * m2.r4.w);

    return result;
}

mat4 mat4::operator/(const mat4& m2) const
{ 
    mat4 result;

    result.r1.x = (r1.x / m2.r1.x) + (r1.y / m2.r2.x) + (r1.z / m2.r3.x) + (r1.w / m2.r4.x);
    result.r1.y = (r1.x / m2.r1.y) + (r1.y / m2.r2.y) + (r1.z / m2.r3.y) + (r1.w / m2.r4.y);
    result.r1.z = (r1.x / m2.r1.z) + (r1.y / m2.r2.z) + (r1.z / m2.r3.z) + (r1.w / m2.r4.z);
    result.r1.w = (r1.x / m2.r1.w) + (r1.y / m2.r2.w) + (r1.z / m2.r3.w) + (r1.w / m2.r4.w);

    result.r2.x = (r2.x / m2.r1.x) + (r2.y / m2.r2.x) + (r2.z / m2.r3.x) + (r2.w / m2.r4.x);
    result.r2.y = (r2.x / m2.r1.y) + (r2.y / m2.r2.y) + (r2.z / m2.r3.y) + (r2.w / m2.r4.y);
    result.r2.z = (r2.x / m2.r1.z) + (r2.y / m2.r2.z) + (r2.z / m2.r3.z) + (r2.w / m2.r4.z);
    result.r2.w = (r2.x / m2.r1.w) + (r2.y / m2.r2.w) + (r2.z / m2.r3.w) + (r2.w / m2.r4.w);

    result.r3.x = (r3.x / m2.r1.x) + (r1.y / m2.r2.x) + (r1.z / m2.r3.x) + (r1.w / m2.r4.x);
    result.r3.y = (r3.x / m2.r1.y) + (r1.y / m2.r2.y) + (r1.z / m2.r3.y) + (r1.w / m2.r4.y);
    result.r3.z = (r3.x / m2.r1.z) + (r1.y / m2.r2.z) + (r1.z / m2.r3.z) + (r1.w / m2.r4.z);
    result.r3.w = (r3.x / m2.r1.w) + (r1.y / m2.r2.w) + (r1.z / m2.r3.w) + (r1.w / m2.r4.w);

    result.r4.x = (r4.x / m2.r1.x) + (r1.y / m2.r2.x) + (r1.z / m2.r3.x) + (r1.w / m2.r4.x);
    result.r4.y = (r4.x / m2.r1.y) + (r1.y / m2.r2.y) + (r1.z / m2.r3.y) + (r1.w / m2.r4.y);
    result.r4.z = (r4.x / m2.r1.z) + (r1.y / m2.r2.z) + (r1.z / m2.r3.z) + (r1.w / m2.r4.z);
    result.r4.w = (r4.x / m2.r1.w) + (r1.y / m2.r2.w) + (r1.z / m2.r3.w) + (r1.w / m2.r4.w);

    return result;
}

vec4 mat4::operator*(const vec4& v1) const
{
    return vec4((r1.x * v1.x) + r1.y + r1.z + r1.w,
                r2.x + (r2.y * v1.y) + r2.z + r2.w,
                r3.x + r3.y + (r3.z * v1.z) + r3.w,
                r4.x + r4.y + r4.z + (r4.w * v1.w));
}