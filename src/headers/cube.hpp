#pragma once

#include "object.hpp"

// HERITE DE OBJET

class Cube : public Object {
public:
    Cube();
    Cube(glm::vec3 position); // Nécessaire ? Ou ajouter : Object(glm::vec3 position)
    ~Cube();

    void print();
    void drawCube();
    void extrudeCube(glm::vec3 position);
    void digCube();
    void deleteCube();
    
};
