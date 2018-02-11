#pragma once

#include <glad\glad.h>
#include <glfw3.h>
#include <stdio.h>

extern GLFWwindow *window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

bool create_window();

bool is_window_open();

void update_window();

void window_clean_up();
