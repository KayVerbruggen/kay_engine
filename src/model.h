#pragma once

#include "mesh.h"
#include "texture.h"
#include "shader.h"

// TODO: Proper constructor so you don't have to
// make the shader and texture beforehand.
// You should eventually be able to pass an OBJ and texture file.

struct Model
{
    Model(const char* obj_file, const char* texture)
    {
        mesh = create_mesh(obj_file);
        texture_id = create_texture(texture);
    }
    Model(){}
    Mesh mesh;
    unsigned int texture_id;
};