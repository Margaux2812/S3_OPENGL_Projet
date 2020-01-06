#include "../include/selector.hpp"
#include "../include/vertex.hpp"

const glm::vec3 vertices[] = {
    // Front v0,v1,v2,v3
    glm::vec3(0.5, 0.5, 0.5),            
        glm::vec3(-0.5, 0.5, 0.5), 
        glm::vec3(-0.5, -0.5, 0.5), 
        glm::vec3(0.5, -0.5, 0.5),
    // Right v0,v3,v4,v5

    glm::vec3(0.5, 0.5, 0.5), 
        glm::vec3(0.5, -0.5, 0.5), 
        glm::vec3(0.5, -0.5, -0.5), 
        glm::vec3(0.5, 0.5, -0.5), 
    // Top v0,v5,v6,v0.5    

    glm::vec3(0.5, 0.5, 0.5), 
        glm::vec3(0.5, 0.5, -0.5), 
        glm::vec3(-0.5, 0.5, -0.5), 
        glm::vec3(-0.5, 0.5, 0.5), 
    // Left v0.5,v6,v7,v2   

    glm::vec3(-0.5, 0.5, 0.5), 
        glm::vec3(-0.5, 0.5, -0.5), 
        glm::vec3(-0.5, -0.5, -0.5), 
        glm::vec3(-0.5, -0.5, 0.5),  
    // Bottom v7,v4,v3,v2

    glm::vec3(-0.5, -0.5, -0.5),
        glm::vec3(0.5, -0.5, -0.5), 
        glm::vec3(0.5, -0.5, 0.5), 
        glm::vec3(-0.5, -0.5, 0.5), 
    // Back v4,v7,v6,v5 

    glm::vec3(0.5, -0.5, -0.5), 
        glm::vec3(-0.5, -0.5, -0.5), 
        glm::vec3(-0.5, 0.5, -0.5), 
        glm::vec3(0.5, 0.5, -0.5)
    };

Selector::Selector()
:m_shader(new MyShader("shaders/color.vs.glsl", "shaders/color.fs.glsl"))
{
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_POSITION_ALL = 2;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    //On a 24 sommets
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(glm::vec3), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    m_positionCube.push_back(glm::vec3(25.f, 1.f, 25.f));

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

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (const GLvoid*) 0);

    glBindBuffer(GL_ARRAY_BUFFER, vboAll);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION_ALL); 

    glVertexAttribPointer(VERTEX_ATTR_POSITION_ALL, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glVertexAttribDivisor(VERTEX_ATTR_POSITION_ALL, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO
}

Selector::~Selector(){
    delete m_shader;
    glDeleteBuffers(1, &vboAll);
    glDeleteBuffers(1, &m_ibo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

glm::vec3 Selector::getPosition(){
    return m_positionCube[0];;
}

void Selector::draw(glm::mat4 MVMatrix, glm::vec3 color){
    m_shader->bind();
    m_shader->setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*MVMatrix));
    m_shader->setUniformMatrix4fv("uMVMatrix", glm::value_ptr(MVMatrix));
    m_shader->setUniformMatrix4fv("uNormalMatrix", glm::value_ptr(NormalMatrix));
    m_shader->setUniform3f("uColor", color);
    
	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    //Dernier truc est nb de cubes
    glDrawElementsInstanced(GL_LINES, 36, GL_UNSIGNED_INT, (void*) 0, m_positionCube.size());

    glBindVertexArray(0); //Debinder la VAO
    m_shader->unbind();
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