#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // window object
                                        //height and width
    GLFWwindow *window = glfwCreateWindow(800, 600, "Testing Opengl..", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();

        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std:: cout << "Failed to initialize glad" << std:: endl;
        return -1;
    }

    // settin up vertex data 
    float vertices[]= {
        -0.5f, -0.5f, 0.0f, //left
        0.5f, -0.5f, 0.0f,  // right
        0.0f, 0.5f, 0.0f,   // top
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    while(!glfwWindowShouldClose(window)){
        processInput(window);

        glClearColor(1.0f, 0.8f, 0.5f, 2.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}