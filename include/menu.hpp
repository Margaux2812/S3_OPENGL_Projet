#pragma once


/*!
 * \file menu.hpp
 * \brief Create menu
 */

#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/Image.hpp"

#include "vertex.hpp"
#include "texture.hpp"
#include "myshader.hpp"

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
    	MyShader* m_shader;

	public :
	/**
	 * \brief Construct a new Menu object
	 * 
	 */
		Menu();

	/**
	 * \brief Destroy the Menu object
	 * 
	 */
		~Menu();
	/**
	 * \brief draw OpenGL Menu Object
	 * 
	 */
		void draw();

	/**
	 * \brief == operator overloading / test name of menu
	 * 
	 * \param name name to test
	 * \return true if m_name==name
	 * \return false if m_name!=name
	 */
		bool operator==(MenuName name);

	/**
	 * \brief != operator overloading / test name of menu
	 * 
	 * \param name name to test
	 * \return true if m_name==name
	 * \return false if m_name!=name
	 */
		bool operator!=(MenuName name);

	/**
	 * \brief change menuState inGame to Pause and vice versa
	 * 
	 */
		void changeState();

	/**
	 * \brief change manually m_name
	 * 
	 * \param name selected
	 */
		void changeTo(MenuName name);

	/**
	 * \brief click event manager
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y
	 */
		void handleClicks(const float x, const float y);

	/**
	 * \brief handle events in principal menu
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y
	 */
		void handleInPrincipal(const float x, const float y);
	
	/**
	 * \brief handle events in pause menu
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y
	 */
		void handleInPause(const float x, const float y);

	/**
	 * \brief handle event in controle1 menu
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y 
	 */
		void handleInControle1(const float x, const float y);

	/**
	 * \brief handle event in controle2 menu
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y
	 */
		void handleInControle2(const float x, const float y);

	/**
	 * \brief handle event in quit menu
	 * 
	 * \param x Coordinate X
	 * \param y Coordinate Y
	 * \return true if user want to quit
	 * \return false if user want to stay
	 */
		bool handleInQuit(const float x, const float y);
	
	/**
	 * \brief display cursor
	 * 
	 */
		void enableCursor();

	/**
	 * \brief hide cursor
	 * 
	 */
		void disableCursor();
};