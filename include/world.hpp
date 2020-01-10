#pragma once

/*!
 * \file world.hpp
 * \brief Create a world
 */

#include <GL/glew.h>
#include "../lib/glimac/include/glm.hpp"
#include <vector>
//To have the SDL_Event
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "cube.hpp"
#include "typeCube.hpp"
#include "skybox.hpp"
#include "pinceau.hpp"
#include "selector.hpp"

class World{
	private:
		std::vector<Cube*> m_allCubes;
		Skybox* m_skybox;
		Selector* m_selector;
		Pinceau* m_pinceau;
		glm::vec3 m_lights[6];

   	public:

		/**
		 * @brief Construct a new World object
		 * 
		 */
		World();

		/**
		 * @brief Destroy the World object
		 * 
		 */
		~World();

		/**
		 * @brief draw the skybox and handle cursor color
		 * 
		 * @param MVMatrix 
		 * @param ctrlIsPressed 
		 */
		void draw(const glm::mat4 MVMatrix, const bool ctrlIsPressed);

		/**
		 * @brief draw the lights in world
		 * 
		 */
		void drawLights();

		/**
		 * @brief event manager
		 * 
		 * @param e 
		 * @param ctrlIsPressed 
		 */
		void handleEvents(const SDLKey e, const bool ctrlIsPressed);

		/**
		 * @brief addCube function for all types
		 * 
		 * @param position 
		 * @param typePinceau 
		 */
		void addCube(const glm::vec3 position, const typeCube typePinceau);
		
		/**
		 * @brief replace cube function for all types
		 * 
		 * @param position 
		 * @param typePinceau 
		 */
		void replace(const glm::vec3 position, const typeCube typePinceau);
		
		/**
		 * @brief extrudeCube function for all types
		 * 
		 * @param position 
		 * @param typePinceau 
		 */
		void extrudeCube(glm::vec3 position, const typeCube typePinceau);

		/**
		 * @brief digCube function for all types
		 * 
		 * @param position 
		 * @param typePinceau 
		 */
		void digCube(glm::vec3 position, const typeCube typePinceau);

		/**
		 * @brief change night to day and vice versa
		 * 
		 */
		void changeNightMode();

		/**
		 * @brief check if the position is empty
		 * 
		 * @param position 
		 * @return true if the position isn't empty
		 * @return false if the position is empty
		 */
		bool existsSmth(const glm::vec3 position);

		/**
		 * @brief find last cube of cubeVector
		 * 
		 * @param position 
		 * @return int 
		 */
		int findLastCube(const glm::vec3 position);
};