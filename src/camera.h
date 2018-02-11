#pragma once

#include <vector>
#include "math.h"

struct Camera
{
    vec3 position, target, direction, up, right;
    mat4 view;
};

extern unsigned int active_camera;
extern std::vector<Camera> camera_list;

void create_camera(vec3 pos);

void update_camera();