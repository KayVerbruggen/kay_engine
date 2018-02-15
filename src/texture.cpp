#include "texture.h"

#include <glad.h>
#include "stb_image.h"

unsigned int create_texture(const char* texture_file)
{
    // Texture ID which will be returned at the end.
    unsigned int texture_id;

    // Bind the texture.
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    
    // Set the options for texture filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load the image and store some information of it.
    int width, height, channel_count;
    unsigned char* data = stbi_load(texture_file, &width, &height, &channel_count, 0);

    if(!data)
    {
        printf("Error: Failed to open texture!");
        return 0;
    }

    printf("Texture: %d x %d\n", width, height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    // Free the data.
    stbi_image_free(data);

    return texture_id;
}