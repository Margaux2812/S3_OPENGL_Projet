#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../include/FreeflyCamera.hpp"
#include "../include/vertex.hpp"
#include "../include/cube.hpp"
#include "../include/selector.hpp"

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
    std::cout << "***********************************************" << std::endl;
    std::cout << "*****************LES COMMANDES*****************" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << "Pour déplacer la caméra : - Haut : Z" << std::endl;
    std::cout << "                          - Bas : S" << std::endl;
    std::cout << "                          - Gauche : Q" << std::endl;
    std::cout << "                          - Droite : D" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << "Pour déplacer le curseur : - Haut : Fleche du haut" << std::endl;
    std::cout << "                           - Bas : Fleche du bas" << std::endl;
    std::cout << "                           - Gauche : Fleche de gauche" << std::endl;
    std::cout << "                           - Droite : Fleche de droite" << std::endl;
    std::cout << "                           - Fond : O" << std::endl;
    std::cout << "                           - Avant : L" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << "Pour manipuler les cubes : - Ajouter : Entrée" << std::endl;
    std::cout << "                           - Supprimer : Del" << std::endl;
    std::cout << "                           - Extrude : E" << std::endl;
    std::cout << "                           - Dig : C" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << "***********************************************" << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    FreeflyCamera camera;
    Cube cubes;
    Selector selector;

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
                    cubes.handleEvents(e.key.keysym.sym, selector.getPosition());
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
        
        selector.draw();
        cubes.draw();

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
