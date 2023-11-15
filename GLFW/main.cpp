//
//  main.cpp
//  GLFW OpenGL
//
//  Created by Huan Tran on 11/15/23.
//

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

#include <iostream>

int main(int argc, const char * argv[]) {
    //init glwf
    glfwInit();
    //require options for glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Graphics", nullptr, nullptr);
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    if(nullptr == window)
    {
        std::cout << "Failed to create FLFW Window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    //define the viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);
    
    //gameloop
    while(!glfwWindowShouldClose(window))
    {
        //Events
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Draw
        glfwSwapBuffers(window);
    }
    //terminate
    glfwTerminate();
    return EXIT_SUCCESS;
}
