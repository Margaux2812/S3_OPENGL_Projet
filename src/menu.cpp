#include "../include/menu.hpp"
#include <iostream>

const VertexTex vertices[] = { 
    VertexTex(glm::vec2(-1.f, 1.f), 
            glm::vec2(0.f, 0.f)),
    VertexTex(glm::vec2(1.f, 1.f), 
            glm::vec2(1.f, 0.f)),
    VertexTex(glm::vec2(1.f, -1.f),
            glm::vec2(1.f, 1.f)),
    VertexTex(glm::vec2(-1.f, -1.f), 
            glm::vec2(0.f, 1.f))
};

const uint32_t indices[] = {
    0, 1, 2,
    2, 3, 0
};

Menu::Menu()
:m_name(inGame),
m_texture("assets/textures/MenuPrincipal.png")
{
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_TEXCOORD = 1;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(VertexTex), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    //On a 36 points
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTex), (const GLvoid*) offsetof(VertexTex, position));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTex), (const GLvoid*) offsetof(VertexTex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO
}

Menu::~Menu(){

}

		
bool Menu::operator==(MenuName name){
	return m_name == name;
}

void Menu::setMenuName(MenuName name){
	m_name = name;
	switch(m_name){
		case principal:
		break;
		case inPause: 
        SDL_ShowCursor(SDL_ENABLE);
        SDL_WM_GrabInput(SDL_GRAB_OFF);
		break;
		case inGame:
		default: 
		break;
	}
}

void Menu::draw(){
	m_texture.bind();
    glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*) 0, 1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO
    m_texture.unbind();
}