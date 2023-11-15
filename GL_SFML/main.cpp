//
//  main.cpp
//  GL_SFML
//
//  Created by Huan Tran on 11/15/23.
//

#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>

const GLint WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    sf::ContextSettings settings;
    settings.depthBits = 24;settings.stencilBits = 8;
    settings.majorVersion = settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;
    sf::Window window(sf::VideoMode(WIDTH,HEIGHT,32), "SFML",sf::Style::Titlebar | sf::Style::Close,settings);
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    bool running = true;
    while(running)
    {
        sf::Event windowEvent;
        while(window.pollEvent(windowEvent))
        {
            switch (windowEvent.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                    
                default:
                    break;
            }
        }
        glClearColor(0.3f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw
        window.display();
    }
    window.close();
    return  EXIT_SUCCESS;
}
