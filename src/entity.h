#pragma once

#include "mesh.h"
#include "texture.h"
#include "math.h"

// TODO: Proper constructor so you don't have to
// make the shader and texture beforehand.
// You should eventually be able to pass an OBJ and texture file.

struct Entity
{
    Entity(const char* obj_file, const char* texture, vec3 in_pos, vec3 in_rot, vec3 in_scale);
    Mesh mesh;
    unsigned int texture_id;

    vec3 pos;
    vec3 rotation;
    vec3 mesh_scale;

    mat4 matrix;
};