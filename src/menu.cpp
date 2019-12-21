#include "../include/menu.hpp"
#include <iostream>

Menu::Menu(){
	m_name = inGame;
}

Menu::~Menu(){

}

		
MenuName Menu::getMenuName(){
	return m_name;
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