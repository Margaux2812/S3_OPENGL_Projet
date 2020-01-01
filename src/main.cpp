#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../include/all.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(SCREEN_WIDTH, SCREEN_HEIGHT, "WorldIMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Pour la transparence
    displayCommandes();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Skybox skybox;
    Menu menu;
    Pinceau pinceau;
    FreeflyCamera camera;
    World world;
    Selector selector;

    ///////MAP WORLD///////

    glm::mat4 MVMatrix = glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
    );

    // Application loop:
    bool done = false;
    while(!done) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            switch(e.type){
                case SDL_QUIT :
                    menu.changeTo(quit);
                break;
                case SDL_KEYDOWN : 
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        menu.changeTo(quit);
                    /*Si on appuie sur pause, on met le jeu en pause ou à nouveau en mode play*/
                    }else if(e.key.keysym.sym == SDLK_SPACE && menu != principal){
                        menu.changeState();
                    /*Si on appuie sur entrée, le jeu commence*/
                    }else if(e.key.keysym.sym == SDLK_RETURN && menu != inGame){
                        menu.changeTo(inGame);
                    }else if(menu == inGame){
                        pinceau.handleEvents(e.key.keysym.sym);
                        world.handleEvents(e.key.keysym.sym, selector.getPosition(), pinceau.getType());
                        selector.handleEvents(e.key.keysym.sym);
                        camera.handleKeyboardEventsDown(e.key.keysym.sym);
                    }
                break;
                case SDL_KEYUP:
                    if(menu == inGame)
                        camera.handleKeyboardEventsUp(e.key.keysym.sym);
                break;
                case SDL_MOUSEMOTION:
                    if(menu == inGame)
                        camera.handleMouseEvents(e);
                break;    
                case SDL_MOUSEBUTTONDOWN :
                    menu.handleClicks(e.button.x, e.button.y);
                    if(menu == quit)
                        done = menu.handleInQuit(e.button.x, e.button.y);
                break;
                default: break;
            }
        }

        /*Affichage de la scène selon si on est en jeu ou non*/
        if(menu == inGame){
            camera.updateCameraMovement();

            MVMatrix = camera.getViewMatrix();

            world.draw(MVMatrix);
            selector.draw(MVMatrix);

            skybox.draw(MVMatrix);

        }else{
            menu.draw();
        }
        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}