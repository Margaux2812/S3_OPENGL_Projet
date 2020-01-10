#pragma once

/*!
 * \file vertex.hpp
 * \brief Create a vertex
 */

#include "../lib/glimac/include/glm.hpp"

/**
 * @brief structure for Vertex3DColor
 * 
 */
struct Vertex3DColor{
    glm::vec3 position;
    glm::vec3 color;

    /**
     * @brief Construct a new Vertex 3 D Color object
     * 
     */
    Vertex3DColor(){
        this->position.x = 0;
        this->position.y = 0;
        this->position.z = 0;
        this->color.r = 0;
        this->color.g = 0;
        this->color.b = 0;
    }

    /**
     * @brief Construct a new Vertex 3 D Color object
     * 
     * @param position 
     * @param color 
     */
    Vertex3DColor(glm::vec3 position, glm::vec3 color)
    : position(position), 
        color(color)
    {
    }
};

/**
 * @brief Structure for Vertex3D
 * 
 */
struct Vertex3D{
    glm::vec3 position;
    glm::vec3 normals;
    glm::vec2 texCoords;

    /**
     * @brief Construct a new Vertex 3 D object
     * 
     */
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

    /**
     * @brief Construct a new Vertex 3 D object
     * 
     * @param position 
     * @param normals 
     * @param texCoords 
     */
    Vertex3D(glm::vec3 position, glm::vec3 normals, glm::vec2 texCoords)
    : position(position), 
        normals(normals),
        texCoords(texCoords)
    {
    }
};


/**
 * @brief Structure for VertexTex
 * 
 */
struct VertexTex{
    glm::vec2 position;
    glm::vec2 texCoords;

    /**
     * @brief Construct a new VertexTex object
     * 
     */
    VertexTex(){
        this->position.x = 0;
        this->position.y = 0;
        this->texCoords.x = 0;
        this->texCoords.y = 0;
    }

/**
 * @brief Construct a new VertexTex object
 * 
 * @param position 
 * @param texCoords 
 */
    VertexTex(glm::vec2 position, glm::vec2 texCoords)
    : position(position),
        texCoords(texCoords)
    {
    }
};

/**
 * @brief test if the value is between my min and max
 * 
 * @param value 
 * @param min 
 * @param max 
 * @return true if min <= value <= max
 * @return false if value < min or value > max
 */
bool floatIsBetween(const float value, const int min, const int max);

const float SCREEN_WIDTH = 800.f;
const float SCREEN_HEIGHT = 600.f;
const glm::mat4 ProjMatrix = glm::infinitePerspective(
    1.f,
    SCREEN_WIDTH/SCREEN_HEIGHT,
    0.1f);
const glm::mat4 NormalMatrix = glm::transpose(glm::inverse(
    glm::translate(
        glm::mat4(),
        glm::vec3(0, 0, -5)
    )));