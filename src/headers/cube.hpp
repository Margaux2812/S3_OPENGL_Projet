#pragma once

#include "object.hpp"
#include <iterator>

// HERITE DE OBJET

class Cube : public Object {
public:
    Cube();
    Cube(glm::vec3 position);
    ~Cube();

    void print();
    void draw();
    void addCube();
    void extrudeCube();
    void digCube();
    void deleteCube();
    
};
