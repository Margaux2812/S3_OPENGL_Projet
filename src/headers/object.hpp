#pragma once

#include <glm/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <string>

class Object  {
public:
    Object::Object();
    Object::Object(glm::vec3 position);
    virtual ~Object(void);       // Le destructeur virtuel.
    virtual void print(void) =0; // Fonction virtuelle pure.

public : 
    glm::vec3 m_position;


private:
    unsigned int m_vao;
    unsigned int m_ib;
    std::string m_VertexShader;
    std::string m_FragmentShader;


    ///// GETTER //////
    unsigned int Object::getVao();
    unsigned int Object::getIb();
    std::string Object::getVertexShader();
    std::string Object::getFrangmentShader();


    ///// SETTER //////
    void Object::setVao(unsigned int newVao);
    void Object::setIb(unsigned int newIB);
    void Object::setVertexShader(std::string newVS);
    void Object::setFrangmentShader(std::string newFs);
    
};
