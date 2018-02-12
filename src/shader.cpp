#include "shader.h"

#include <glad\glad.h>

#include <string>
#include <fstream>
#include <sstream>

// Used to specify the type of the shader, so we know what we're dealing with.
enum Shader_Types
{
    NONE = -1, VERTEX = 0, FRAGMENT = 1
};

struct Shader_Sources
{
    std::string vertex_source, fragment_source;
};

unsigned int compile_shader(unsigned int type, const char* source)
{
    // Store the id of the different shaders.
    unsigned int id = glCreateShader(type);
    
    // Give the source of the shader and use that to compile it.
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    // Store the result that we got after compiling.
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    // Check if there are any errors.
    if(result == GL_FALSE)
    {
        // Check how long the error message is.
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        // Allocate the correct amount of memory and save the message there.
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        // Output the error to the cmd.
        printf("Shader Error: %s \n", message);

        return 0;
    }

    return id;
}

Shader_Sources read_shader(const std::string& shader_file)
{
    // Open the shader file.
    std::ifstream stream(shader_file);
    std::string line;
    std::stringstream ss[2];
    
    // Set the default type to none, just to be sure.
    int type = NONE;

    if(!stream.is_open())
    {
        printf("Error: Failed to open shader source file!");
        return {"", ""};
    }

    // Just read the entire file, and put the current line in a string.
    while(getline(stream, line))
    {
        // Check what the type of the shader is and store the data.
        if (line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
                type = VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = FRAGMENT;
        }
        else
        {
            ss[type] << line << '\n';
        }
    }

    // Return the strings from the streams.
    return { ss[0].str(), ss[1].str() };
}

unsigned int create_shader(const std::string& shader_file)
{
    unsigned int shader_program = glCreateProgram();

    // Read the shaders from the source file.
    Shader_Sources source = read_shader(shader_file);
    const char* vs_source = source.vertex_source.c_str();
    const char* fs_source = source.fragment_source.c_str();

    // Compile the shaders
    unsigned int vertex_shader = compile_shader(GL_VERTEX_SHADER, vs_source);
    unsigned int fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fs_source);

    // Attach the vertex and fragment shader to the shader program.
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glValidateProgram(shader_program);  

    // Delete the shaders after they have been linked.
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Activate the shader program.
    glUseProgram(shader_program);

    // Only the id of the shader program is needed, so we return exactly that.
    return shader_program;
}

void set_uniform(unsigned int shader, std::string name, float value)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform1f(location, value);
}

void set_uniform(unsigned int shader, std::string name, float v1, float v2)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform2f(location, v1, v2);
}

void set_uniform(unsigned int shader, std::string name, float v1, float v2, float v3)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform3f(location, v1, v2, v3);
}

void set_uniform(unsigned int shader, std::string name, vec3 v)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform3fv(location, 1, value_ptr(v));
}

void set_uniform(unsigned int shader, std::string name, float v1, float v2, float v3, float v4)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform4f(location, v1, v2, v3, v4);
}

void set_uniform(unsigned int shader, std::string name, vec4 v)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniform4fv(location, 1, value_ptr(v));
}

void set_uniform(unsigned int shader, std::string name, mat4 m1)
{
    int location = glGetUniformLocation(shader, name.c_str());
    glUniformMatrix4fv(location, 1, GL_TRUE, value_ptr(m1));
}

void set_uniform(unsigned shader, std::string name, Directional_Light dl)
{
    set_uniform(shader, name + ".direction", dl.direction);

    set_uniform(shader, name + ".base.ambient", dl.ambient);
    set_uniform(shader, name + ".base.diffuse", dl.diffuse);
    set_uniform(shader, name + ".base.specular", dl.specular);

    set_uniform(shader, name + ".base.intensity", dl.intensity);
    set_uniform(shader, name + ".base.pos", dl.pos);
}

void set_uniform(unsigned int shader, std::string name, Point_Light pl)
{
    set_uniform(shader, name + ".base.pos", pl.pos);
    set_uniform(shader, name + ".base.intensity", pl.intensity);

    set_uniform(shader, name + ".base.ambient", pl.ambient);
    set_uniform(shader, name + ".base.diffuse", pl.diffuse);
    set_uniform(shader, name + ".base.specular", pl.specular);

    set_uniform(shader, name + ".constant", pl.constant);
    set_uniform(shader, name + ".linear", pl.linear);
    set_uniform(shader, name + ".quadratic", pl.quadratic);
}