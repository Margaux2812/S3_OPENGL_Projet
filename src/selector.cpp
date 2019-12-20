#include "../include/selector.hpp"
#include "../include/vertex.hpp"

const Vertex3DColor vertices[] = {
    // Front v0,v1,v2,v3
    Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(0, 0, 1),                    
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0, 0, 1),
                    glm::vec3(1.f, 0.4f, 0.7f)),
    // Right v0,v3,v4,v5

    Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(1, 0, 0),
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)),
    // Top v0,v5,v6,v0.5    

    Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), 
                glm::vec3(0, 1, 0),
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), 
                    glm::vec3(0, 1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
    // Left v0.5,v6,v7,v2   

    Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), 
                glm::vec3(-1, 0, 0),
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(-1, 0, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)),  
    // Bottom v7,v4,v3,v2

    Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), 
                glm::vec3(0,-1, 0),
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), 
                    glm::vec3(0,-1, 0),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
    // Back v4,v7,v6,v5 

    Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), 
                glm::vec3(0, 0,-1),
                glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec3(1.f, 0.4f, 0.7f)), 
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), 
                    glm::vec3(0, 0,-1),
                    glm::vec3(1.f, 0.4f, 0.7f))
    };

Selector::Selector(){
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_COULEUR = 2;
    const GLuint VERTEX_ATTR_POSITION_ALL = 3;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    //On a 24 sommets
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    m_positionCube.push_back(glm::vec3(0, -1, -3));

    // on crée le buffer
    glGenBuffers(1, &vboAll); 
    // on le bind pour que la ligne suivante s'applique bien à ce buffer ci
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    // on envoie toutes nos données au GPU
    glBufferData(GL_ARRAY_BUFFER, m_positionCube.size()*sizeof(glm::vec3), m_positionCube.data(), GL_STATIC_DRAW);
    // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &m_ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    uint32_t indices[] = {
        0, 1, 1, 2, 2, 3, 3, 0,       // front
        4, 5, 5, 6, 6, 7, 7, 4,       // right
        8, 9, 9,10,10,11,11,8,       // top
        12,13,13,14,14,15,15,12,      // left
        16,17,17,18,18,19,19,16,      // bottom
        20,21,21,22,22,23,23,20       // back
    };

    //On a 36 points
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3DColor, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3DColor, normals));
    glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3DColor, color));

    glBindBuffer(GL_ARRAY_BUFFER, vboAll);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION_ALL); 

    glVertexAttribPointer(VERTEX_ATTR_POSITION_ALL, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    // Avec une petite nouveauté :
    // C'est pour dire à OpenGL qu'il ne doit pas avancer dans le buffer à chaque vertex, mais seulement à chaque nouveau cube qu'il commence à dessiner
    glVertexAttribDivisor(VERTEX_ATTR_POSITION_ALL, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO

    m_position = m_positionCube[0];
}

Selector::~Selector(){
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}
glm::vec3 Selector::getPosition(){
    return m_position;
}

void Selector::draw(){
	//Il faudra bind le shader ici

	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    //Dernier truc est nb de cubes
    glDrawElementsInstanced(GL_LINES, 36, GL_UNSIGNED_INT, (void*) 0, m_positionCube.size());

    glBindVertexArray(0); //Debinder la VAO
}

void Selector::handleEvents(SDLKey e){
    switch(e){
        case SDLK_LEFT: move(gauche);
        break;
        case SDLK_RIGHT:move(droite);
        break;
        case SDLK_UP:move(haut);
        break;
        case SDLK_DOWN: move(bas);
        break;
        case SDLK_o:move(arriere);
        break;
        case SDLK_l: move(avant);
        break;
        
        default: break;
    }
}


void Selector::updateGPU(){
    glBindBuffer(GL_ARRAY_BUFFER, vboAll); 
    glBufferData(GL_ARRAY_BUFFER, m_positionCube.size()*sizeof(glm::vec3), m_positionCube.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Selector::updatePos(glm::vec3 position){
    m_positionCube.pop_back();
    m_positionCube.push_back(position);
    m_position = position;
    updateGPU();
}

void Selector::move(Fleche f){
	glm::vec3 movement = glm::vec3(0., 0., 0.);
	switch(f){
		case gauche: movement = glm::vec3(-1., 0., 0.);
		break;
        case droite: movement = glm::vec3(1., 0., 0.);
        break;
        case haut: movement = glm::vec3(0., 1., 0.);
        break;
        case bas: movement = glm::vec3(0., -1., 0.);
        break;
        case arriere: movement = glm::vec3(0., 0., -1.);
        break;
        case avant: movement = glm::vec3(0., 0., 1.);
        break;
        default: 
        break;
	}
	glm::vec3 newPos = m_positionCube[0]+movement;
	updatePos(newPos);
	updateGPU();
}