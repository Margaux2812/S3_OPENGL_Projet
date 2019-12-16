#ifndef _Object_hpp_
#define _Object_hpp_

#include <glm/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <string>

class Object  {
public:
    Object();
    Object(glm::vec3 position);
    ~Object();


private:
    glm::vec3 position;
    unsigned int m_vao;
    unsigned int m_ib;
    std::string m_VertexShader;
    std::string m_FragmentShader;


    ///// GETTER //////
    unsigned int Object::getVao();
    unsigned int Object::getIb();
    std::string Object::getVertexShader();
    std::string Object::getFrangmentShader();
    glm::vec3 Object::getPosition();


    ///// SETTER //////
    void Object::setVao(unsigned int newVao);
    void Object::setIb(unsigned int IbVao);
    void Object::setVertexShader(std::string newVS);
    void Object::setFrangmentShader(std::string newFs);
    void Object::setPosition(glm::vec3 newPos);
    
};

#endif