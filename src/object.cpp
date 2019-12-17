
    #include "object.hpp"


        ///// CONSTRUCTORS & DESTRUCTOR //////

        Object::Object() : m_vao(0), m_ib(0), m_position(0), m_shader("res/shaders/basic.vert", "res/shaders/basic.frag"){
            
        }

        Object::Object(glm::vec3 position) : m_vao(0), m_ib(0), m_position(position), m_shader("res/shaders/basic.vert", "res/shaders/basic.frag"){

        }


        Object::~Object(){}


        ///// GETTER //////
        unsigned int Object::getVao(){
            return m_vao;
        }
        unsigned int Object::getIb(){
            return m_ib;
        }
        Shader Object::getShader(){
            return m_shader;
        }



        ///// SETTER //////
        void Object::setVao(unsigned int newVao){
            m_vao=newVao;
        }
        void Object::setIb(unsigned int newIb){
            m_ib=newIb;

        }
        void Object::setShader(std::string newVs, std::string newFs){
            m_shader.setPath(newVs, newFs);
        }
        
