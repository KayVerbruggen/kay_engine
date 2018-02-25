#include "entity.h"

Entity::Entity(const char* obj_file, const char* texture, vec3 in_pos, vec3 in_rot, vec3 in_scale)
{
    mesh = create_mesh(obj_file);
    texture_id = create_texture(texture);

    pos = in_pos;
    rotation = in_rot;
    mesh_scale = in_scale;

    matrix = rotate(matrix, in_rot.y, vec3(0.0f, 1.0f, 0.0f));
    matrix = translate(matrix, pos);
}