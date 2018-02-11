#include "draw.h"

void begin_frame()
{
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void draw_mesh(Mesh mesh)
{
    // Bind the buffers.
    glBindVertexArray(mesh.vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ibo);

    // Make a draw call.
    glDrawElements(GL_TRIANGLES, mesh.index_count, GL_UNSIGNED_INT, nullptr);
}

void draw_model(Model model)
{
    // Set the texture.
    glBindTexture(GL_TEXTURE_2D, model.texture_id);

    // Bind the buffers.
    glBindVertexArray(model.mesh.vao);

    // Make a draw call.
    glDrawElements(GL_TRIANGLES, model.mesh.index_count, GL_UNSIGNED_INT, nullptr);
}