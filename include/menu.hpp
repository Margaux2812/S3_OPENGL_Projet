#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../lib/glimac/include/Program.hpp"
#include "../lib/glimac/include/FilePath.hpp"
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "../lib/glimac/include/Image.hpp"
#include "vertex.hpp"
#include "texture.hpp"

enum MenuName {
	principal,
	inGame,
	inPause,
	controle,
	controle2,
	quit
};

class Menu{
	private:
		MenuName m_name;
		GLuint m_ibo;
		GLuint m_vbo;
    	GLuint m_vao;
    	Texture* m_texture;
    	MenuName m_precMenu;

	public :
		Menu();
		~Menu();

		void draw();

		bool operator==(MenuName name);
		bool operator!=(MenuName name);

		void changeState();
		void changeTo(MenuName name);

		void handleClicks(const float x, const float y);
		void handleInPrincipal(const float x, const float y);
		void handleInPause(const float x, const float y);
		void handleInControle1(const float x, const float y);
		void handleInControle2(const float x, const float y);
		bool handleInQuit(const float x, const float y);
		
		void enableCursor();
		void disableCursor();
};