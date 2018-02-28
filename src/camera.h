#pragma once

#include <vector>
#include "math.h"

struct Camera
{
    vec3 position, target, direction, up, right;
    mat4 view, projection;
    float fov;
};

extern unsigned int active_camera;
extern std::vector<Camera> camera_list;

void create_camera(vec3 pos, float in_fov);

void update_camera();