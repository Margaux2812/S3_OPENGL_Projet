#pragma once
#include <GL/glew.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../lib/glimac/include/Image.hpp"
#include "vertex.hpp"

enum MenuName {
	inGame,
	inPause,
	principal
};

class Menu{
	private:
		MenuName m_name;
		GLuint m_ibo;
		GLuint m_vbo;
    	GLuint m_vao;

	public :
		Menu();
		~Menu();
		
		bool operator==(MenuName name);
		void setMenuName(MenuName name);
		void draw(MenuName name);
		void drawPausedGame();
		void drawMainMenu();
};