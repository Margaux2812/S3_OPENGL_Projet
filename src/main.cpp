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
 

    MyShader shaderTextures("shaders/3D.vs.glsl", "shaders/normal.fs.glsl");
    MyShader shaderCouleur("shaders/color.vs.glsl", "shaders/color.fs.glsl");
    Texture tex("assets/textures/grass.png");
    
    glEnable(GL_DEPTH_TEST);
    displayCommandes();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Menu menu;
    Pinceau pinceau;
    FreeflyCamera camera;
    Cube cubesDeTerre(EARTH);
    Cube cubesDeSable(SAND);
    Cube cubesDEau(WATER);
    Cube cubesDHerbe(GRASS);
    Selector selector;

    ////MAP WORLD***////

    const glm::mat4 ProjMatrix = glm::infinitePerspective(
        1.f,
        SCREEN_WIDTH/SCREEN_HEIGHT,
        0.1f);
    glm::mat4 MVMatrix = glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
    );
    const glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


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

                        cubesDeTerre.handleEvents(e.key.keysym.sym, selector.getPosition(), pinceau.getType());
                        cubesDeSable.handleEvents(e.key.keysym.sym, selector.getPosition(), pinceau.getType());
                        cubesDEau.handleEvents(e.key.keysym.sym, selector.getPosition(), pinceau.getType());
                        cubesDHerbe.handleEvents(e.key.keysym.sym, selector.getPosition(), pinceau.getType());

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

            /*********************************
             * HERE SHOULD COME THE RENDERING CODE
             *********************************/
            camera.updateCameraMovement();

            MVMatrix = camera.getViewMatrix();

            shaderTextures.bind();
            shaderTextures.setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*MVMatrix));
            shaderTextures.setUniformMatrix4fv("uMVMatrix", glm::value_ptr(MVMatrix));
            shaderTextures.setUniformMatrix4fv("uNormalMatrix", glm::value_ptr(NormalMatrix));
            shaderTextures.setUniform1i("u_Texture", 0);

            cubesDeSable.draw();
            cubesDEau.draw();
            cubesDHerbe.draw();
            cubesDeTerre.draw();


            /*TODO voir le shader pour le selecteur puis abstraire la texture*/
            tex.bind();
            selector.draw();
            tex.unbind();

            shaderTextures.unbind();
        }else{
            shaderCouleur.bind();
            shaderTextures.setUniform1i("u_Texture", 0);
            menu.draw();
            shaderCouleur.unbind();
        }
        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
