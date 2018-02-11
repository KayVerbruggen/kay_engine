#include "input.h"
#include "window.h"
#include "timer.h"
#include "camera.h"

float movement_speed = 2.5f;

void handle_input()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera_list[active_camera].position.z += movement_speed * delta_time;

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera_list[active_camera].position.z -= movement_speed * delta_time;

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera_list[active_camera].position.x += movement_speed * delta_time;

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera_list[active_camera].position.x -= movement_speed * delta_time;
       
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        active_camera = 0;

    if((glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) && (camera_list.size() > 1))
        active_camera = 1;
}