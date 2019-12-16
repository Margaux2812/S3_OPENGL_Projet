#pragma once

#include <glm/glm.hpp>

#include "object.hpp"

// HERITE DE OBJET

class Cube : virtual public Object {
public:
    Cube();
    Cube(glm::vec3 position); // Nécessaire ? Ou ajouter : Object(glm::vec3 position)
    ~Cube();

    void drawCube();
    Cube extrudeCube();
    void digCube();
    void deleteCube();
    
};
