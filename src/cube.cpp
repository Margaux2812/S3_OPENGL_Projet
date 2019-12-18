#include "../include/cube.hpp"
#include "../include/vertex.hpp"

Cube::Cube(){
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COULEUR = 1;

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

    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

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

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), 0);
    glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(3*sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO
};

Cube::~Cube(){
	glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void Cube::draw(){
	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0);

    glBindVertexArray(0); //Debinder la VAO
};


Cube Cube::findFromPosition(Cube &mapCube, glm::vec3 position){
    Cube mycube;
    // for (int i=0; i<mapCube; i++ )
    return mycube;
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
