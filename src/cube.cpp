#include "../include/cube.hpp"
#include "../include/vertex.hpp"
#include <iostream>
#include <fstream>
#include <string>

const Vertex3D vertices[] = {
    // Front v0,v1,v2,v3
    Vertex3D(glm::vec3(0.5, 0.5, 0.5), //Position
                glm::vec3(0, 0, 1),         //Normals 
                glm::vec2(1.f, 1.f/3.f)),      //Texture coordonnées
        Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(0.f, 1.f/3.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(0.f, 2.f/3.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(1.f, 2.f/3.f)), 
    // Right v0,v3,v4,v5

    Vertex3D(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(1, 0, 0),
                glm::vec2(0.f, 1.f/3.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(0.f, 2.f/3.f)),  
        Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(1.f, 2.f/3.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(1.f, 1.f/3.f)),
    // Top v0,v5,v6,v0.5    

    Vertex3D(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(0, 1, 0),
                glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(0.f, 0.f)),  
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(0.f, 1.f/3.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(1.f, 1.f/3.f)), 
    // Left v0.5,v6,v7,v2   

    Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                glm::vec3(-1, 0, 0),
                glm::vec2(1.f, 1.f/3.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(0.f, 1.f/3.f)),  
        Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(0.f, 2.f/3.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(1.f, 2.f/3.f)),  
    // Bottom v7,v4,v3,v2

    Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                glm::vec3(0,-1, 0),
                glm::vec2(1.f, 2.f/3.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(0.f, 2.f/3.f)),  
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(0.f, 1.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(1.f, 1.f)), 
    // Back v4,v7,v6,v5 

    Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                glm::vec3(0, 0,-1),
                glm::vec2(0.f, 2.f/3.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(1.f, 2.f/3.f)),  
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(1.f, 1.f/3.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(0.f, 1.f/3.f))
    };

const uint32_t indices[] = {
        0, 1, 2,   2, 3, 0,       // front
        4, 5, 6,   6, 7, 4,       // right
        8, 9, 10,  10,11,8,       // top
        12,13,14,  14,15,12,      // left
        16,17,18,  18,19,16,      // bottom
        20,21,22,  22,23,20       // back
    };

Cube::Cube(typeCube type)
: m_type(type),
m_texture(getTexture()),
m_shader(new MyShader("shaders/3D.vs.glsl", "shaders/normal.fs.glsl")),
nightMode(false)
{
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORD = 2;
    const GLuint VERTEX_ATTR_POSITION_ALL = 3;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    //On a 24 sommets
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vertex3D), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    if(type == GROUND)
        loadMonde();

    glGenBuffers(1, &vboAll); 
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    glBufferData(GL_ARRAY_BUFFER, m_positionsCubes.size()*sizeof(glm::vec3), m_positionsCubes.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    //On a 36 points
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, normals));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, vboAll);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION_ALL); 

    glVertexAttribPointer(VERTEX_ATTR_POSITION_ALL, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glVertexAttribDivisor(VERTEX_ATTR_POSITION_ALL, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO
m_shader->setUniform1i("u_Texture", 0);
};

Cube::~Cube(){
	glDeleteBuffers(1, &m_ibo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &vboAll);
    glDeleteVertexArrays(1, &m_vao);
}

void Cube::draw(const glm::mat4 MVMatrix, const glm::vec3* lumieres){

    m_shader->bind();
    m_shader->setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*MVMatrix));
    m_shader->setUniformMatrix4fv("uMVMatrix", glm::value_ptr(MVMatrix));
    m_shader->setUniformMatrix4fv("uNormalMatrix", glm::value_ptr(NormalMatrix));
    m_shader->setUniform3f("uLightDir", glm::normalize(glm::vec3(0.3f, -0.7f, 0.3f)));
    m_shader->setUniformVec3("uLightPonct",  lumieres);

    if(nightMode){
        m_shader->setUniform1f("uAmbiantLight", 0.2f);
    }else{
        m_shader->setUniform1f("uAmbiantLight", 0.8f);
    }

    m_texture->bind();
	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    //Dernier paramètre est nb de cubes
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0, m_positionsCubes.size());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO
    m_texture->unbind();
    m_shader->unbind();
}

///////////////////////////////////////////////////////////////
/////////////////////////// GETTERS ///////////////////////////
///////////////////////////////////////////////////////////////

Texture* Cube::getTexture() const{
    switch(m_type){
        case GRASS:  return new Texture("assets/textures/cubes_textures/grass.png");
        break;
        case WATER :  return new Texture("assets/textures/cubes_textures/water.png");
        break;
        case SAND : return new Texture("assets/textures/cubes_textures/sand.jpg");
        break;
        case LEAF : return new Texture("assets/textures/cubes_textures/leaf.png");
        break;
        case BARBARA : return new Texture("assets/textures/cubes_textures/barbara.png");
        break;
        case JULES : return new Texture("assets/textures/cubes_textures/jules.png");
        break;
        case IMAC : return new Texture("assets/textures/cubes_textures/imac.png");
        break;
        case GROUND :
        default:   return new Texture("assets/textures/cubes_textures/cubeTerre.jpg");
        break;
    }
}

///////////////////////////////////////////////////////////////
/////////////////////////// SETTERS ///////////////////////////
///////////////////////////////////////////////////////////////

void Cube::setVao(GLuint const newVao){
    m_vao=newVao;
}
void Cube::setVbo(GLuint const newVbo){
    m_vbo=newVbo;
}
void Cube::setIbo(GLuint const newIbo){
    m_ibo=newIbo;
}

///////////////////////////////////////////////////////////////
///////////////////////// EVENT MANAGER ///////////////////////
///////////////////////////////////////////////////////////////

void Cube::changeNightMode(){
    nightMode = !nightMode;
}

int Cube::findFromPosition(const glm::vec3 position){
    for (int i=0; i< int(m_positionsCubes.size()); i++ ){
        if(glm::length(position-m_positionsCubes[i]) < 0.1f){
            return i;
        }
    }
    return -1;
}

void Cube::updateGPU(){
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    glBufferData(GL_ARRAY_BUFFER, m_positionsCubes.size()*sizeof(glm::vec3), m_positionsCubes.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

///////////////////////////////////////////////////////////////
///////////////////////// CUBE MANAGER ////////////////////////
///////////////////////////////////////////////////////////////


bool Cube::addCube(const glm::vec3 position){
    int exists = findFromPosition(position);
    bool canAdd = true;
    if(m_type == LIGHT && m_positionsCubes.size() >= 10){
        canAdd = false;
    }

    if(exists == -1 && canAdd){
        m_positionsCubes.push_back(position);
        updateGPU();
        return 1;
    }
    return 0;
}

void Cube::deleteCube(const glm::vec3 position){
    int index = findFromPosition(position);
    if(index != -1){
        int lastIndex = m_positionsCubes.size() - 1;
        std::swap(m_positionsCubes[index], m_positionsCubes[lastIndex]);
        m_positionsCubes.pop_back();

        updateGPU();
    }
}

int Cube::initControles(Eigen::MatrixXf* ptsDeControle, Eigen::VectorXf* uk){
    bool initPoints = true, initY=false;
    int point = 0;
    std::string number="";
    std::string x="", y="", value="";

    std::string line;
    std::ifstream myfile ("doc/controles.txt");
    
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            if(line.find("POINTS") != std::string::npos){
                initPoints = true;
            }else if(line.find("VALEURS") != std::string::npos){
                initPoints = false;
                point=0;
            //On lit des points
            }else{
                if(initPoints){
                    /*Si on est entrain de regarder les points, on doit prendre les 2 premiers*/
                    for(uint i=0; i < line.size(); i++){
                        if(isspace(line[i])){
                            initY=true;
                        }

                        if(!initY){
                            x+= line[i];
                        }else{
                            y+= line[i];
                        }
                    }
                    ptsDeControle->row(point) << std::stoi(x), std::stoi(y);
                    point++;
                    x="";
                    y="";
                    initY=false;
                    ptsDeControle->conservativeResize(point+1, 2);
                }else{
                    for(uint i=0; i < line.size(); i++){
                        value+= line[i];
                    }
                    uk->row(point) << std::stoi(value);
                    point++;
                    value="";
                    uk->conservativeResize(point+1);
                }
            }
        }
        ptsDeControle->conservativeResize(point, 2);
        uk->conservativeResize(point);
        myfile.close();
        return 1;
    }else
        std::cout << "Unable to open file"; 
    return 0;
}

void Cube::loadMonde(){
    Eigen::MatrixXd map(WORLD_WIDTH_HEIGHT, WORLD_WIDTH_HEIGHT);

    Eigen::MatrixXf ptsDeControle(1, 2);
    Eigen::VectorXf uk(1);

    initControles(&ptsDeControle, &uk);

    map = getValues(ptsDeControle, uk);
    for(int x=0; x<WORLD_WIDTH_HEIGHT; x++){
        for(int z = 0; z<WORLD_WIDTH_HEIGHT; z++){
            for(int y= WORLD_DEPTH; y <= map(x, z); y++){
                m_positionsCubes.push_back(glm::vec3(x, y, z));
            }
        }
    }
}