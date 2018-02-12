#pragma once

#include <string>
#include "math.h"
#include "light.h"

unsigned int create_shader(const std::string& shader_file);

void set_uniform(unsigned int shader, std::string name, bool boolean);

void set_uniform(unsigned int shader, std::string name, float value);

void set_uniform(unsigned int shader, std::string name, float f1, float f2);

void set_uniform(unsigned int shader, std::string name, float f1, float f2, float f3);

void set_uniform(unsigned int shader, std::string name, vec3 v);

void set_uniform(unsigned int shader, std::string name, float f1, float f2, float f3, float f4);

void set_uniform(unsigned int shader, std::string name, vec4 v);

void set_uniform(unsigned int shader, std::string name, mat4 m1);

void set_uniform(unsigned int shader, std::string name, Directional_Light dl);

void set_uniform(unsigned int shader, std::string name, Point_Light pl);