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

#include <iostream>
#include "Shader.h"

const GLint WIDTH = 800, HEIGHT = 600;


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
   //Build and compile shaders
    Shader ourShader ("/Users/huantran/Documents/OpenGL/GLFW OpenGL/resources/shaders/core.vs","/Users/huantran/Documents/OpenGL/GLFW OpenGL/resources/shaders/core.frag");
    //Shader ourShader("core.vs","core.frag");
    //set up vertex data
    GLfloat vertices[] =
    {
        // Positions // Colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Top
    };
    
    GLuint VBO,VAO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(GLfloat),(GLvoid *)0);
    glEnableVertexAttribArray(0);
  
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(GLfloat),(GLvoid *)0);
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    
    //gameloop
    while(!glfwWindowShouldClose(window))
    {
        //Events
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Draw
        ourShader.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        //swap the screen buffer
        glfwSwapBuffers(window);
    }
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    
    //terminate
    glfwTerminate();
    return EXIT_SUCCESS;
}
