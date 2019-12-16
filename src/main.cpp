#include <glimac/SDLWindowManager.hpp>
#include <GL/glad.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <vector>
#include <glm/gtc/constants.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(1920, 1050, "WORLD_IMACker");
    // Initialize glad for OpenGL3+ support
    GLenum gladInitError = gladInit();
    if(GLAD_OK != gladInitError) {
        std::cerr << gladGetErrorString(gladInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLAD Version : " << gladGetString(GLAD_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
