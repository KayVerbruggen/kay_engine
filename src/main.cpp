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
#include "entity.h"

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
    Entity cube("", "../res/grass.png", vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, to_radians(45.0f), 0.0f), vec3(1.0f, 1.0f, 1.0f));

    std::vector<Entity*> entities;
    entities.push_back(&cube);

    // Create a camera, more cameras can be created.
    create_camera(vec3(0.0f, 0.0f, -5.0f));

    // Create a perspective projection.
    mat4 projection;
    projection = perspective_lh(to_radians(45.0f), WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 1000.0f);
    set_uniform(shader, "projection", projection);

    Spot_Light sl(vec3(0.0f, 0.0f, -1.5f), vec3(0.0f, 0.0f, 1.0f), 5.0f, 12.5f, 20.0f);
    set_uniform(shader, "spot", sl);

    // Run this loop until the window is closed.
    while (is_window_open())
    {
        update_timer();
        handle_input();
        update_camera();

        begin_frame();
        
        cube.rotation.y += to_radians(delta_time * 5);
        cube.matrix = rotate(cube.matrix, cube.rotation.y, vec3(0.0f, 1.0f, 0.0f));

        set_uniform(shader, "view", camera_list[active_camera].view);
        set_uniform(shader, "view_pos", camera_list[active_camera].position);

        draw_scene(entities, shader);

        update_window();
    }

    window_clean_up();

    return 0;
}