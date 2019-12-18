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
    // Selector mySelector();

    ////MAP WORLD***////
    uint nbCubeLines = 5; // Nombre de cube par tranche

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
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            if(e.type == SDL_KEYDOWN){
                float speed = 0.1f;
                switch(e.key.keysym.sym){
                    /*Z key to move forward*/
                    case SDLK_z: camera.moveFront(speed);
                    break;
                    /*S key to move backward*/
                    case SDLK_s: camera.moveFront(-speed);
                    break;
                    /*Q key to move left*/
                    case SDLK_q: camera.moveLeft(speed);
                    break;
                    /*D key to move right*/
                    case SDLK_d: camera.moveLeft(-speed);
                    break;

                    default: break;
                }
            }
            
            if(e.type== SDL_MOUSEMOTION && e.button.button == SDL_BUTTON_LEFT){
                float speed = 0.1f;
                if ( e.motion.xrel != 0 ) {
                  camera.rotateUp( float(-e.motion.xrel) * speed);
                }
                if ( e.motion.yrel != 0 ) {std::cout << float(-e.motion.yrel) * speed << std::endl;
                  camera.rotateLeft( float(e.motion.yrel) * speed);
                }
                
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
