#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

#include "app.hpp"
#include "cube.hpp"

int main(int argc, char *argv[]) {
    App app;
    Cube myCube;
    Cube myCube2;
    // Créer un tableau fixe de cube invisibles
    // Init chaque cube
    // Créer le selecteur


    glClearColor(1, 0, 1, 1);

<<<<<<< Updated upstream
    while (app.isRunning()) {
=======
    Cube myCube(glm::vec3(0, 0, 0));

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
>>>>>>> Stashed changes
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT: app.exit();

            case SDL_KEYDOWN:
                if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                    myCube.m_position.x--;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                    myCube.m_position.x++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_UP) {
                    myCube.m_position.y++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                    myCube.m_position.y--;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_PAGEUP) {
                    myCube.m_position.z++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_PAGEDOWN) {
                    myCube.m_position.z--;
                }

            default: break;
            };
        }

<<<<<<< Updated upstream
        app.beginFrame();

        myCube.drawCube();
        myCube2.drawCube();
=======
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        cube.draw();
        // Update the display
        windowManager.swapBuffers();
    }
>>>>>>> Stashed changes

        app.endFrame();
    }
    
    return 0;
}
