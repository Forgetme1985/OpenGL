//
//  main.cpp
//  GLSDL
//
//  Created by Huan Tran on 11/15/23.
//

#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_Window* window = SDL_CreateWindow("SDL", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    glViewport(0, 0, WIDTH, HEIGHT);
    SDL_Event windowEvent;
    while(true)
    {
        if(SDL_PollEvent(&windowEvent))
        {
            if(windowEvent.type == SDL_QUIT)break;
        }
        //clear the colorbuffer
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw
        SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
