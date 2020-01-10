#pragma once

/*!
 * \file selector.hpp
 * \brief Create a selector
 */


#include "cube.hpp"
#include "myshader.hpp"

enum Fleche {haut, bas, gauche, droite, avant, arriere};

class Selector{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionCube;
		MyShader* m_shader;

	public :

		/**
		 * @brief Construct a new Selector object
		 * 
		 */	
		Selector();
		/**
		 * @brief Destroy the Selector object
		 * 
		 */
		~Selector();
		/**
		 * @brief Get the Position of selector
		 * 
		 * @return glm::vec3 
		 */
		glm::vec3 getPosition();


		/**
		 * @brief draw the OpenGL Object with good color
		 * 
		 * @param MVMatrix 
		 * @param color 
		 */
		void draw(glm::mat4 MVMatrix, glm::vec3 color);

		/**
		 * @brief Event Manager
		 * 
		 * @param e 
		 */
		void handleEvents(SDLKey e);

		/**
		 * @brief Update GPU to see new texture
		 * 
		 */
		void updateGPU();

		/**
		 * @brief update selector position
		 * 
		 * @param position 
		 */
		void updatePos(glm::vec3 position);

		/**
		 * @brief move selector
		 * 
		 * @param direction 
		 */
		void move(Fleche direction);

};