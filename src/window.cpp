#include "window.h"
#include "config.h"

const char* window_title = "Test Window";
GLFWwindow *window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // TODO: The projection matrix should change too. Because the aspect ratio
    // might not be correct after resizing.

    // Change the viewport to use the new width and height from the window.
    glViewport(0, 0, width, height);
    
    // Update the width and height from the config file, so the projection matrix
    // can change accordingly.
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
}

bool create_window()
{
    // Initialize GLFW.
    if (glfwInit() == GLFW_FALSE)
    {
        printf("Error: Failed to initialize GLFW!");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  // OpenGL version 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // Use the core profile to prevent using outdated stuff.
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);          // Forward compatible for MacOS, they only have OpenGL 4.1
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);                      // Uses the callback to set correct viewport when resized.

    // Enable MSAA.
    if (MSAA > 0)
        glfwWindowHint(GLFW_SAMPLES, MSAA);

    // Create the window.
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, window_title, nullptr, nullptr);

    // Check if window was made correctly.
    if (!window)
    {
        printf("Error: Failed to create a window!\n");
        glfwTerminate();
        return false;
    }
    // Set the window to the current context, to make it visible.
    glfwMakeContextCurrent(window);

    // Enable v-sync.
    if(V_SYNC)
        glfwSwapInterval(1);

    // Load OpenGL using the context GLFW created for us.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Error: Failed to initialize GLAD!\n");
        return false;
    }

    // Set the viewport according to the window size.
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glfwSetWindowSizeCallback(window, framebuffer_size_callback);

    // Print OpenGL version to check if everything is setup correctly.
    printf("OpenGL: %s\n", glGetString(GL_VERSION));

    return true;
}

bool is_window_open()
{
    return !glfwWindowShouldClose(window);
}

void update_window()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void window_clean_up()
{
    glfwTerminate();
}