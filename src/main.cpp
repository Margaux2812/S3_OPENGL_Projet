#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/FreeflyCamera.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../include/vertex.hpp"
#include "../include/cube.hpp"

using namespace glimac;

const float cameraSpeed = 1.f;
const float cameraSpeedRotation = 0.1f;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "Test");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "../shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "../shaders/normal.fs.glsl");
    program.use();

    //Les variables uniformes du Vertex Shader
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    FreeflyCamera camera;
    Cube cube;
    //Selector selector;

    ////MAP WORLD***////

      glm::mat4 ProjMatrix = glm::infinitePerspective(
        1.f,
        800.f/600.f,
        0.1f);
    glm::mat4 MVMatrix = glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
        );
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            switch(e.type){
                case SDL_QUIT :
                    done = true; // Leave the loop after this iteration
                    break;

                case SDL_KEYDOWN : 
                    switch(e.key.keysym.sym){
                        /*Z key to move forward*/
                        case SDLK_z: camera.moveFront(cameraSpeed);
                        break;
                        /*S key to move backward*/
                        case SDLK_s: camera.moveFront(-cameraSpeed);
                        break;
                        /*Q key to move left*/
                        case SDLK_q: camera.moveLeft(cameraSpeed);
                        break;
                        /*D key to move right*/
                        case SDLK_d: camera.moveLeft(-cameraSpeed);
                        break;

                        /*case SDLK_LEFT: selector.moveLeft();
                        break;
                        case SDLK_RIGHT: selector.moveLeft();
                        break;
                        case SDLK_UP: selector.moveUp();
                        break;
                        case SDL_DOWN: selector.moveUp();
                        break;*/
                        /*MOUVEMENT DU CURSEUR*/

                        default: break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if(e.button.button != 0.0){
                        if ( e.motion.xrel != 0 ) {
                          camera.rotateUp( float(-e.motion.xrel) * cameraSpeedRotation);
                        }
                        if ( e.motion.yrel != 0 ) {
                          camera.rotateLeft( float(e.motion.yrel) * cameraSpeedRotation);
                        }
                    }

                default: break;
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = camera.getViewMatrix();

        glUniformMatrix4fv(uMVPMatrix,
            1,
            GL_FALSE,
            glm::value_ptr(ProjMatrix*MVMatrix)
            );
        glUniformMatrix4fv(uMVMatrix,
            1,
            GL_FALSE,
            glm::value_ptr(MVMatrix)
            );
        glUniformMatrix4fv(uNormalMatrix,
            1,
            GL_FALSE,
            glm::value_ptr(NormalMatrix)
            );
        
        cube.draw();

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
