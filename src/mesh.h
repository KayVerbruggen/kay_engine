#pragma once

#include <glad\glad.h>
#include <vector>
#include "math.h"

struct Mesh 
{
    unsigned int vao, vbo, ibo;
    unsigned int index_count;
};

struct Vertex
{
    float x, y, z;    
};

Mesh create_mesh(const char* mesh_file);

bool read_mesh(const char* mesh_file, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);