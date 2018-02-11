#include "camera.h"

unsigned int active_camera = 0;
std::vector<Camera> camera_list;

void create_camera(vec3 pos)
{
    Camera cam;

    cam.position = pos;
    cam.target = vec3(pos.x, pos.y, pos.z + 1.0f);
    cam.direction = normalize(cam.target - cam.position);
    vec3 up = vec3(0.0f, 1.0f, 0.0f);
    cam.right = normalize(cross(up, cam.direction));
    cam.up = cross(cam.direction, cam.right);

    cam.view = look_at(cam.right, cam.up, cam.direction, cam.position);
    //math_print(cam.view);
    
    camera_list.push_back(cam);
}

void update_camera()
{
    camera_list[active_camera].target = vec3(camera_list[active_camera].position.x, camera_list[active_camera].position.y, camera_list[active_camera].position.z + 1.0f);
    camera_list[active_camera].direction = normalize(camera_list[active_camera].target - camera_list[active_camera].position);
    vec3 up = vec3(0.0f, 1.0f, 0.0f);
    camera_list[active_camera].right = normalize(cross(up, camera_list[active_camera].direction));
    camera_list[active_camera].up = cross(camera_list[active_camera].direction, camera_list[active_camera].right);

    camera_list[active_camera].view = look_at(camera_list[active_camera].right, camera_list[active_camera].up, camera_list[active_camera].direction, camera_list[active_camera].position);
}