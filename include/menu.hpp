#pragma once
#include <GL/glew.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../lib/glimac/include/Image.hpp"

enum MenuName {
	inGame,
	principal
};

class Menu{
	private:
		MenuName m_name;

	public :
		Menu();
		~Menu();
		
		MenuName getMenuName();
		void draw(glimac::FilePath applicationPath);
};