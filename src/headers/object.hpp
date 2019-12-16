#pragma once

#include <glm/glm.hpp>

#include "shader.h"

// HERITE DE OBJET

class Object  {
public:
    Object();
    Object(glm::vec3 position);
    ~Object();


private:
    glm::vec3 position;
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;


    ///// GETTER //////
    unsigned int Object::getVao();
    unsigned int Object::getIb();
    Shader Object::getShader();
    glm::vec3 Object::getPosition();


    ///// SETTER //////
    void Object::setVao(unsigned int newVao);
    void Object::setIb(unsigned int IbVao));
    void Object::setShader(Shader newShader);
    void Object::setPosition(glm::vec3 newPos);

    
};




