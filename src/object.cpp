
    #include "object.hpp"


        ///// CONSTRUCTORS & DESTRUCTOR //////

        Object::Object(){
            m_position=glm::vec3(0,0,0);
        }

        Object::Object(glm::vec3 position){
            m_position=position;
        }

        Object::~Object(void){
        return ;
        }



        ///// GETTER //////
        unsigned int Object::getVao(){
            return m_vao;
        }
        unsigned int Object::getIb(){
            return m_ib;
        }
        std::string Object::getVertexShader(){
            return m_VertexShader;
        }
        std::string Object::getFrangmentShader(){
            return m_FragmentShader;
        }


        ///// SETTER //////
        void Object::setVao(unsigned int newVao){
            m_vao=newVao;
        }
        void Object::setIb(unsigned int newIb){
            m_ib=newIb;

        }
        void Object::setVertexShader(std::string newVS){
            m_VertexShader=newVS;

        }
        void Object::setFrangmentShader(std::string newFs){
            m_FragmentShader=newFs;

        }
        
