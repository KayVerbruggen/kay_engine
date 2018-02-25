#pragma once

#include <glad.h>
#include <glfw3.h>
#include <stdio.h>
#include <vector>

#include "model.h"
#include "entity.h"

void begin_frame();

void draw_mesh(Mesh mesh);

void draw_model(Model model);

void draw_scene(std::vector<Entity*> entities, unsigned int shader);