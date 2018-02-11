#include "window.h"
#include "draw.h"
#include "input.h"
#include "shader.h"
#include "model.h"
#include "math.h"
#include "timer.h"
#include "camera.h"
#include "config.h"
#include "light.h"

// TODO: Have a place to properly save settings like the resolutions, and if v-sync is enabled etc.
// Maybe something like a config.h header file. Or even a text file that we would read, but that would
// be way more complicated than simply having it in a header file.

int main()
{
    // Create a window using GLFW.
    if (!create_window())
        return -1;

    // Start the timer.
    start_timer();

    unsigned int shader = create_shader("../shaders/basic.glsl");

    // TODO: Let this read an OBJ file.
    Model texture_quad("", "../res/grass.png");

    // This matrix wil save rotation, translation and scale of a model.
    mat4 model;
    model = translate(model, vec3(0.0f, 0.0f, 0.0f));
    model = rotate(model, to_radians(0.0f), vec3(0.0f, 1.0f, 0.0f));

    // Create a camera, more cameras can be created.
    create_camera(vec3(0.0f, 0.0f, -5.0f));

    // Create a perspective projection.
    mat4 projection;
    projection = perspective_lh(to_radians(45.0f), WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 1000.0f);
    set_uniform(shader, "projection", projection);

    // Create a sun and set it as a uniform.
    Directional_Light sun(vec3(0.0f, 2.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), 1.0f, vec3(1.0f, 1.0f, 0.0f));
    set_uniform(shader, "dir_light", sun);

    // Run this loop until the window is closed.
    while (is_window_open())
    {
        update_timer();
        handle_input();
        update_camera();

        begin_frame();

        model = rotate(model, glfwGetTime() * to_radians(45.0f), vec3(0.5f, 1.0f, 0.0f));
        
        set_uniform(shader, "model", model);
        set_uniform(shader, "view", camera_list[active_camera].view);
        set_uniform(shader, "view_pos", camera_list[active_camera].position);
        draw_model(texture_quad);

        update_window();
    }

    window_clean_up();

    return 0;
}