#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

#include "headers/app.hpp"
#include "headers/cube.hpp"

int main(int argc, char *argv[]) {
    App app;
    Cube myCube;
    Cube myCube2;
    // Selector mySelect();

    ////***MAP WORLD***////
    // Créer un tableau fixe de cube invisibles

    // uint nbCubeLines = 10;
    // Cube mapCube[nbCubeLines*nbCubesLines*nbCubesLines];

    ////**************////



    glClearColor(1, 0, 1, 1);
    while (app.isRunning()) {
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

        app.beginFrame();

        myCube.draw();
        myCube2.draw();


        // // Edit cube position + Draw them
        // uint countCube = 0;
        // for (uint line=0; line<=nbCubeLines; line++){
        //     for (uint row=0; row<=nbCubeLines; row++){
        //         for (uint prof=0; prof<=nbCubeLine; prof++){
        //             mapCube[countCube].drawCube();                            
        //             mapCube[countCube].m_position.x=line;    // Initialise lignes (X)                      
        //             mapCube[countCube].m_position.y=row;     // Initialise colonnes (Y)                       
        //             mapCube[countCube].m_position.z=prof;    // Initialise profondeur (Z)                       
        //             countCube++;
        //         }
        //     }
        // }    



        app.endFrame();
    }
    
    return 0;
}
