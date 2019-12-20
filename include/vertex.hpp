#pragma once

#include "../lib/glimac/include/glm.hpp"

struct Vertex3DColor{
    glm::vec3 position;
    glm::vec3 normals;
    glm::vec3 color;

    Vertex3DColor(){
        this->position.x = 0;
        this->position.y = 0;
        this->position.z = 0;
        this->normals.x = 0;
        this->normals.y = 0;
        this->normals.z = 0;
        this->color.r = 0;
        this->color.g = 0;
        this->color.b = 0;
    }

    Vertex3DColor(glm::vec3 position, glm::vec3 normals, glm::vec3 color)
    : position(position), 
        normals(normals),
        color(color)
    {
    }
};