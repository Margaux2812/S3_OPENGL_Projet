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
:m_name(principal),
m_texture(new Texture("assets/textures/MenuPrincipal.png")),
m_precMenu(principal),
m_shader(new MyShader("shaders/texture2D.vs.glsl", "shaders/texture2D.fs.glsl"))
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

void Menu::draw(){
    m_shader->bind();
    m_shader->setUniform1i("u_Texture", 0);
    
    m_texture->bind();
    glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*) 0, 1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO
    m_texture->unbind();
    m_shader->unbind();
}

		
bool Menu::operator==(MenuName name){
	return m_name == name;
}

bool Menu::operator!=(MenuName name){
    return m_name != name;
}

void Menu::changeState(){
	switch(m_name){
		case inPause: changeTo(inGame);
		break;
		case inGame: changeTo(inPause);
        break;
		default: 
		break;
	}
}

void Menu::changeTo(MenuName name){
    //Si c'est controle le précédent on ne veut pas le savoir
    if(m_name != controle && m_name != controle2)
        m_precMenu = m_name;
    switch(name){
        case principal:
        enableCursor();
        m_name = principal;
        m_texture = new Texture("assets/textures/MenuPrincipal.png");
        break;
        case inPause:
        enableCursor();
        m_name = inPause;
        m_texture = new Texture("assets/textures/pauseMenu.png");
        break;
        case controle:
        enableCursor();
        m_name = controle;
        m_texture = new Texture("assets/textures/controles1.png");
        break;
        case controle2:
        enableCursor();
        m_name = controle2;
        m_texture = new Texture("assets/textures/controles2.png");
        break;
        case quit:
        enableCursor();
        m_name = quit;
        m_texture = new Texture("assets/textures/quitGame.png");
        break;
        case inGame:
        disableCursor();
        m_name = inGame;
        break;
        default: break;
    }
}

void Menu::handleClicks(const float x, const float y){
    switch(m_name){
        case principal:handleInPrincipal(x, y);
        break;
        case inPause:handleInPause(x, y);
        break;
        case controle:handleInControle1(x, y);
        break;
        case controle2:handleInControle2(x, y);
        break;
        case quit:
        handleInQuit(x, y);
        break;
        default: break;
    }
}

void Menu::handleInPrincipal(const float x, const float y){
    //Bouton démarrer
    if(floatIsBetween(x, 234, 565) && floatIsBetween(y, 343, 428)){
        changeTo(inGame);
    //Bouton "Controles"
    }else if(floatIsBetween(x, 234, 565) && floatIsBetween(y, 445, 527)){
        changeTo(controle);
    }
}

void Menu::handleInPause(const float x, const float y){
    //Bouton "Retour au jeu"
    if(floatIsBetween(x, 234, 565) && floatIsBetween(y, 154, 237)){
        changeTo(inGame);
    //Bouton "Controles"
    }else if(floatIsBetween(x, 234, 565) && floatIsBetween(y, 254, 336)){
        changeTo(controle);
    //Bouton "Principal"
    }else if(floatIsBetween(x, 234, 565) && floatIsBetween(y, 355, 436)){
        changeTo(principal);
    }
}

void Menu::handleInControle1(const float x, const float y){
    //Bouton Ferme
    if(floatIsBetween(x, 704, 749) && floatIsBetween(y, 41, 82)){
        //Si c'est ingame, inpause on retourne la bas, sinon par default on revient à principal
        switch(m_precMenu){
            case inGame: changeTo(inGame);
            break;
            case inPause: changeTo(inPause);
            break;
            case principal:
            default: changeTo(principal);
            break;
        }
    //Fleche suivant
    }else if(floatIsBetween(x, 373, 417) && floatIsBetween(y, 505, 547)){
        changeTo(controle2);
    }
}

void Menu::handleInControle2(const float x, const float y){
    //Bouton Ferme
    if(floatIsBetween(x, 704, 749) && floatIsBetween(y, 41, 82)){
        switch(m_precMenu){
            case inGame: changeTo(inGame);
            break;
            case inPause: changeTo(inPause);
            break;
            case principal:
            default: changeTo(principal);
            break;
        }
    //Fleche suivant
    }else if(floatIsBetween(x, 373, 417) && floatIsBetween(y, 505, 547)){
        changeTo(controle);
    }
}

bool Menu::handleInQuit(const float x, const float y){
    //Bouton Oui
    if(floatIsBetween(x, 47, 379) && floatIsBetween(y, 356, 440)){
        return true;
    //Bouton Non
    }else if(floatIsBetween(x, 424, 756) && floatIsBetween(y, 355, 439)){
        changeTo(m_precMenu);
    }
    return false;
}

void Menu::enableCursor(){
    SDL_ShowCursor(SDL_ENABLE);
    SDL_WM_GrabInput(SDL_GRAB_OFF);
}

void Menu::disableCursor(){
    SDL_ShowCursor(SDL_DISABLE);
    SDL_WM_GrabInput(SDL_GRAB_ON);
}