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
    SDLWindowManager windowManager(800, 600, "Test");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    MyShader shader("shaders/3D.vs.glsl", "shaders/normal.fs.glsl");
    Texture textureTerre("assets/textures/cubeTerre.jpg");
    Texture textureSable("assets/textures/sand.jpg");
    Texture textureEau("assets/textures/water.png");
    Texture textureHerbe("assets/textures/grass.png");

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
    Cube cubesDEau(SAND);
    Cube cubesDHerbe(SAND);
    Selector selector;

    ////MAP WORLD***////

    const glm::mat4 ProjMatrix = glm::infinitePerspective(
        1.f,
        800.f/600.f,
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
                    done = true; // Leave the loop after this iteration
                    break;

                case SDL_KEYDOWN : 
                    pinceau.handleEvents(e.key.keysym.sym);
                    if(pinceau == EARTH){
                        cubesDeTerre.handleEvents(e.key.keysym.sym, selector.getPosition());
                    }
                    if(pinceau == SAND){
                        cubesDeSable.handleEvents(e.key.keysym.sym, selector.getPosition());
                    }
                    if(pinceau == WATER){
                        cubesDEau.handleEvents(e.key.keysym.sym, selector.getPosition());
                    }
                    if(pinceau == GRASS){
                        cubesDHerbe.handleEvents(e.key.keysym.sym, selector.getPosition());
                    }
                    selector.handleEvents(e.key.keysym.sym);
                    camera.handleKeyboardEventsDown(e.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    camera.handleKeyboardEventsUp(e.key.keysym.sym);
                    break;
                case SDL_MOUSEMOTION:
                    if(e.button.button == SDL_BUTTON_LEFT){
                        camera.handleMouseEvents(e);
                    }

                default: break;
            }
        }

        camera.updateCameraMovement();

        if(menu.getMenuName() == principal){
            //menu.draw(applicationPath);
        }else if(menu.getMenuName() == inGame){

            /*********************************
             * HERE SHOULD COME THE RENDERING CODE
             *********************************/

            MVMatrix = camera.getViewMatrix();

            shader.bind();
            shader.setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*MVMatrix));
            shader.setUniformMatrix4fv("uMVMatrix", glm::value_ptr(MVMatrix));
            shader.setUniformMatrix4fv("uNormalMatrix", glm::value_ptr(NormalMatrix));
            shader.setUniform1i("u_Texture", 0);

            textureTerre.bind();
            selector.draw();
            cubesDeTerre.draw();
            textureTerre.unbind();

            textureSable.bind();
            cubesDeSable.draw();
            textureSable.unbind();

            textureEau.bind();
            cubesDEau.draw();
            textureEau.unbind();

            textureHerbe.bind();
            cubesDHerbe.draw();
            textureHerbe.unbind();

            shader.unbind();
        }
        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
