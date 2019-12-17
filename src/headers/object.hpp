#pragma once

#include <glm/glm.hpp>

#include "shader.hpp"
#include <string>

class Object  {
public:
    Object();
    Object(glm::vec3 position);
    virtual ~Object();       // Le destructeur virtuel.
    virtual void print() =0; // Fonction virtuelle pure.

public : 
    glm::vec3 m_position;


protected:
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;


    ///// GETTER //////
    unsigned int getVao();
    unsigned int getIb();
    Shader getShader();


    ///// SETTER //////
    void setVao(unsigned int newVao);
    void setIb(unsigned int newIB);
    void setShader(std::string newVS, std::string newFs);    
};
