#include "../include/cube.hpp"
#include "../include/vertex.hpp"
#include "../include/radialBasisFunctions.hpp"
#include <iostream>

const Vertex3D vertices[] = {
    // Front v0,v1,v2,v3
    Vertex3D(glm::vec3(0.5, 0.5, 0.5), //Position
                glm::vec3(0, 0, 1),         //Normals 
                glm::vec2(0.f, 0.f)),       //Texture coordonnées
        Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec2(0.f, 1.f)),
    // Right v0,v3,v4,v5

    Vertex3D(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(1, 0, 0),
                glm::vec2(0.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec2(0.f, 1.f)),
    // Top v0,v5,v6,v0.5    

    Vertex3D(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(0, 1, 0),
                glm::vec2(0.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec2(0.f, 1.f)), 
    // Left v0.5,v6,v7,v2   

    Vertex3D(glm::vec3(-0.5, 0.5, 0.5), 
                glm::vec3(-1, 0, 0),
                glm::vec2(0.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec2(0.f, 1.f)),  
    // Bottom v7,v4,v3,v2

    Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                glm::vec3(0,-1, 0),
                glm::vec2(0.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec2(0.f, 1.f)), 
    // Back v4,v7,v6,v5 

    Vertex3D(glm::vec3(0.5, -0.5, -0.5), 
                glm::vec3(0, 0,-1),
                glm::vec2(0.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(1.f, 0.f)), 
        Vertex3D(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(1.f, 1.f)), 
        Vertex3D(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec2(0.f, 1.f))
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
m_texture(getTexture())
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

    if(type == EARTH)
        loadMonde();

    // on crée le buffer
    glGenBuffers(1, &vboAll); 
    // on le bind pour que la ligne suivante s'applique bien à ce buffer ci
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    // on envoie toutes nos données au GPU
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
    // Avec une petite nouveauté :
    // C'est pour dire à OpenGL qu'il ne doit pas avancer dans le buffer à chaque vertex, mais seulement à chaque nouveau cube qu'il commence à dessiner
    glVertexAttribDivisor(VERTEX_ATTR_POSITION_ALL, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO

};

Cube::~Cube(){
    //      TODO:
    //Have to delete each one, faire une boucle
    //glDeleteProgram(m_shaders);

	glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}


void Cube::draw(){
    //std::cout << m_texture.name() << std::endl;
    m_texture.bind();
	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    //Dernier truc est nb de cubes
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0, m_positionsCubes.size());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO
    m_texture.unbind();
}


///////////////////////////////////////////////////////////////
/////////////////////////// GETTERS ///////////////////////////
///////////////////////////////////////////////////////////////

std::string Cube::getTexture(){
    switch(m_type){
        case GRASS: return ("assets/textures/grass.png");
        break;
        case WATER : return ("assets/textures/water.png");
        break;
        case SAND : return ("assets/textures/sand.jpg");
        break;
        case EARTH :
        default: return ("assets/textures/cubeTerre.jpg");
        break;
    }
}
        
std::vector<glm::vec3> Cube::getPositions(){
    return m_positionsCubes;
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



/*Peu importe le type de pinceau, on doit pouvoir supprimer un cube*/
void Cube::handleEvents(const SDLKey e, const glm::vec3 position, typeCube type){
    if(e == SDLK_DELETE)
        deleteCube(position);
    if(type == m_type){
        switch(e){
            case SDLK_RETURN : addCube(position);
            break;
            case SDLK_e: extrudeCube(position);
            break;
            case SDLK_c : digCube(position);
            break;
            
            default: break;
        }
    }
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


void Cube::addCube(const glm::vec3 position){
    int exists = findFromPosition(position);
    if(exists == -1){
        m_positionsCubes.push_back(position);
        updateGPU();
    }
}

void Cube::replace(const glm::vec3 position){
    deleteCube(position);
    m_positionsCubes.push_back(position);
    updateGPU();
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

void Cube::loadMonde(){
    Eigen::MatrixXd map(WORLD_WIDTH_HEIGHT, WORLD_WIDTH_HEIGHT);

    const int nbPoints = 3;

    Eigen::MatrixXf ptsDeControle(nbPoints, 2);
    ptsDeControle << 10, 10,
    2, 3,
    30, 40;
    Eigen::VectorXf uk(nbPoints);
    uk << 10, -2, -20;

    map = getValues(ptsDeControle, uk);
    for(int x=0; x<WORLD_WIDTH_HEIGHT; x++){
        for(int z = 0; z<WORLD_WIDTH_HEIGHT; z++){
            for(int y= WORLD_DEPTH; y <= map(x, z); y++){
                m_positionsCubes.push_back(glm::vec3(x, y, z));
            }
        }
    }
}

int Cube::findLastCube(const glm::vec3 position){
    int yMax = WORLD_DEPTH;
    for (int i=1; i< int(m_positionsCubes.size()); i++ ){
        if((glm::length(position.x-m_positionsCubes[i].x) < 0.1f) && (glm::length(position.z-m_positionsCubes[i].z) < 0.1f)){
            if(m_positionsCubes[i].y > yMax)
                yMax = m_positionsCubes[i].y;
        }
    }
    return yMax;
}

/*On a le curseur à un endroit et on veut ajouter un dernier cube en haut de l'endroit où on est
S'il n'y a pas de cube, ça en ajoute un à y=0*/
void Cube::extrudeCube(glm::vec3 position){
    int yMax = findLastCube(position);
    position.y = yMax+1;
    m_positionsCubes.push_back(position);
    updateGPU();
}

/*On a le curseur à un endroit et on veut enlever le dernier cube en haut de l'endroit où on est*/
void Cube::digCube(glm::vec3 position){
    int yMax = findLastCube(position);
    position.y = yMax;
    deleteCube(position);
    updateGPU();
}