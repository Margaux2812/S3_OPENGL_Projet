#include "../include/menu.hpp"
#include <iostream>

Menu::Menu()
:m_name(inGame)
{
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_TEXCOORD = 2;

	glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    VertexTex vertices[] = { 
    	VertexTex(glm::vec3(-1.f, 1.f, 1.f), 
    			glm::vec2(-1.f, 1.f)),
        VertexTex(glm::vec3(1.f, 1.f, 1.f), 
        		glm::vec2(1.f, 1.f)),
        VertexTex(glm::vec3(-1.f, -1.f, 1.f), 
        		glm::vec2(1.f, -1.f)),
        VertexTex(glm::vec3(1.f, -1.f, 1.f), 
        		glm::vec2(-1.f, -1.f))
    };

    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(VertexTex), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    GLuint m_ibo;
    glGenBuffers(1, &m_ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    uint32_t indices[] = {
        0, 1, 2, //Triangle 1
        1, 3, 2 //Triangle 2
    };

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(uint32_t), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTex), (const GLvoid*) offsetof(VertexTex, position));
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
}

void Menu::draw(MenuName name){
	switch(name){
		case inPause : drawPausedGame();
		break;
		case principal: drawMainMenu();
		break;
		case inGame : //Pas de menu à afficher
		default: break;
	}
}

void Menu::drawMainMenu(){

}

void Menu::drawPausedGame(){
	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO    

    std::cout << "pause" << std::endl;
}


//Ce qu'il y a en commentaire à ajouter quand on a une image de menu

/*void Menu::draw(glimac::FilePath applicationPath){

	if(m_name == principal){

		GLuint fond;
		std::unique_ptr<glimac::Image> jaune = loadImage(applicationPath.dirPath() + "../assets/textures/EarthMap.jpg");

    	if(jaune == NULL) std::cout << "Earth's image not loaded" << std::endl;
    
		if(jaune != NULL) {

			glGenTextures(1, &fond);
			//appel de la texture
			glBindTexture(GL_TEXTURE_2D, fond);

			glTexImage2D(GL_TEXTURE_2D,
		        0,
		        GL_RGBA,
		        jaune->getWidth(),
		        jaune->getHeight(),
		        0,
		        GL_RGBA,
		        GL_FLOAT,
		        jaune->getPixels());
		    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		    //Debinder texture
		    glBindTexture(GL_TEXTURE_2D, 0);

		    glBindTexture(GL_TEXTURE_2D, fond);
		    glBegin(GL_QUADS);
			//couleur neutre
			glColor3ub(200,200,200);
			//coordonée de la texture
			glTexCoord2f(1, 1);
			//Cordonnée du quadrilatère 
			glVertex2f(800, 660);

			glTexCoord2f(1, 0);
			glVertex2f(800, 0);

			glTexCoord2f(0, 0);
			glVertex2f(0, 0);

			glTexCoord2f(0, 1);
			glVertex2f(0, 660);

			glEnd();
		}
	}
}*/