#pragma once

#include "../lib/glimac/include/glm.hpp"

struct Vertex3DColor{
    glm::vec3 position;
    glm::vec3 color;

    Vertex3DColor(){
        this->position.x = 0;
        this->position.y = 0;
        this->position.z = 0;
        this->color.r = 0;
        this->color.g = 0;
        this->color.b = 0;
    }

    Vertex3DColor(glm::vec3 position, glm::vec3 color)
    : position(position), 
        color(color)
    {
    }
};

struct Vertex3D{
    glm::vec3 position;
    glm::vec3 normals;
    glm::vec2 texCoords;

    Vertex3D(){
        this->position.x = 0;
        this->position.y = 0;
        this->position.z = 0;
        this->normals.x = 0;
        this->normals.y = 0;
        this->normals.z = 0;
        this->texCoords.x = 0;
        this->texCoords.y = 0;
    }

    Vertex3D(glm::vec3 position, glm::vec3 normals, glm::vec2 texCoords)
    : position(position), 
        normals(normals),
        texCoords(texCoords)
    {
    }
};

struct VertexTex{
    glm::vec2 position;
    glm::vec2 texCoords;

    VertexTex(){
        this->position.x = 0;
        this->position.y = 0;
        this->texCoords.x = 0;
        this->texCoords.y = 0;
    }

    VertexTex(glm::vec2 position, glm::vec2 texCoords)
    : position(position),
        texCoords(texCoords)
    {
    }
};

bool floatIsBetween(const float value, const int min, const int max);