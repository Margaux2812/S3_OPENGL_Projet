#include "../include/cube.hpp"
#include "../include/vertex.hpp"
#include <vector>

Cube::Cube(){
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COULEUR = 1;
    const GLuint VERTEX_ATTR_POSITION_ALL = 3;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    Vertex3DColor vertices[] = {
        // Front v0,v1,v2,v3
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)),
        // Right v0,v3,v4,v5
        
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)),
        // Top v0,v5,v6,v0.5    
        
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
        // Left v0.5,v6,v7,v2   
        
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)),  
        // Bottom v7,v4,v3,v2
        
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(1.f, 1.f, 0.f)), 
        // Back v4,v7,v6,v5 
        
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f)), 
            Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(1.f, 1.f, 0.f))
        };

    //On a 24 sommets
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    std::vector<glm::vec3> m_positionsCubes;

    m_positionsCubes.push_back(glm::vec3(-2, -1, -3));
    m_positionsCubes.push_back(glm::vec3(0, -1, -3));
    m_positionsCubes.push_back(glm::vec3(2, -1, -3));


    GLuint vboAll;
    // on crée le buffer
    glGenBuffers(1, &vboAll); 
    // on le bind pour que la ligne suivante s'applique bien à ce buffer ci
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    // on envoie toutes nos données au GPU
    glBufferData(GL_ARRAY_BUFFER, m_positionsCubes.size()*sizeof(glm::vec3), m_positionsCubes.data(), GL_STATIC_DRAW);
    // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &m_ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    uint32_t indices[] = {
        0, 1, 2,   2, 3, 0,       // front
        4, 5, 6,   6, 7, 4,       // right
        8, 9, 10,  10,11,8,       // top
        12,13,14,  14,15,12,      // left
        16,17,18,  18,19,16,      // bottom
        20,21,22,  22,23,20       // back
    };

    //On a 36 points
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), 0);
    glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(3*sizeof(GLfloat)));

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
	glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void Cube::draw(){
    //Il faudra bind le shader ici

	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    //Dernier truc est nb de cubes
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0, 3);

    glBindVertexArray(0); //Debinder la VAO
};


int Cube::findFromPosition(glm::vec3 position){
    for (int i=0; i<m_positionsCubes.size(); i++ ){
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

void Cube::addCube(glm::vec3 position){
    m_positionsCubes.push_back(position);
    updateGPU();
}

void deleteCube(glm::vec3 position){
    int index = findFromPosition(position);
    if(index != -1){
        int lastIndex = m_positionsCubes - 1;
        std::swap(m_positionsCubes[index], m_positionsCubes[lastIndex]);
        m_positionsCubes.pop_back();

        updateGPU();
    }
}

///////////////////////////////////////////////////////////////
/////////////////////////// GETTERS ///////////////////////////
///////////////////////////////////////////////////////////////


		GLuint Cube::getVao(){
            return m_vao;
        }
		GLuint Cube::getVbo(){
            return m_vbo;
        }
		GLuint Cube::getIbo(){
            return m_ibo;
        }

        glm::vec3 Cube::getPosition(){
            return m_position;
        }
		// Shader Cube::getShader(){
        //     return m_shader;
        // }
		TYPECUBE Cube::getType(){
            return m_type;
        }


///////////////////////////////////////////////////////////////
/////////////////////////// SETTERS ///////////////////////////
///////////////////////////////////////////////////////////////

		void Cube::setVao(GLuint newVao){
            m_vao=newVao;
        }
		void Cube::setVbo(GLuint newVbo){
            m_vbo=newVbo;
        }
		void Cube::setIbo(GLuint newIbo){
            m_ibo=newIbo;
        }

        void Cube::setPosition(glm::vec3 newPos){
            m_position=newPos;
        }
		// void Cube::setShader(std::string newVs, std::string newFs){
        //     m_shader.setVS(newVS);
        //     m_shader.setFS(newFS);
        // }
		void Cube::setType(TYPECUBE newType){
            m_type =newType;
        }



///////////////////////////////////////////////////////////////
///////////////////////// CUBE MANAGER ////////////////////////
///////////////////////////////////////////////////////////////


    // void Cube::addCube(std::string vs, std::string fs){ // Affiche image du cube // Passer en paramètre les shaders voulus adaptés au typeCube // Créer un enum des types de cubes
        
    //     /////// A DEPLACER AU MOMENT OU ON SELECTINNE LE TYPE DE CUBE ///////

    //     // if (type == SAND){
    //     //     vs="shaders.sand.vs.glsl";
    //     //     fs="shaders.sand.fs.glsl";
    //     // }

    //     /////////////////////////////////////////////////////////////////////

    //     // m_shader.setPath(vs, fs);
    // }


    // void Cube::deleteCube(){ // Delete image du cube
    //     // std::string vs="shaders/transparent.vs.glsl";
    //     // std::string fs="shaders/transparent.fs.glsl";

    //     // m_shader.setPath(vs, fs);
    // }

    // void Cube::extrudeCube(Cube &mapCube){ // Faire un while pour selectionner le premier cube vide
    //     float newZ = m_position.z++;
    //     glm::vec3 posNewCube = glm::vec3(m_position.x,m_position.y,newZ); 
    //     Cube extrCube = findFromPosition(mapCube, posNewCube);
    //     // Dans le main de selection : Recherche cube where position = this.position.z++ && .x && .y
    //     extrCube.addCube(m_shader.getVS, m_shader.getFS);
    // }

    //     void Cube::digCube(Cube &mapCube){ // Faire un while pour selectionner le premier cube non vide
    //     float newZ = m_position.z--;
    //     glm::vec3 posNewCube = glm::vec3(m_position.x,m_position.y,newZ); 
    //     Cube digCube = findFromPosition(mapCube, posNewCube);
    //     // Dans le main de selection : Recherche cube where position = this.position.z++ && .x && .y
    //     digCube.deleteCube();
    // }
