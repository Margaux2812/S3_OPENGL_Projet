#pragma once

#include <GL/glew.h>
#include "../lib/glimac/include/glm.hpp"
#include <vector>
//To have the SDL_Event
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "cube.hpp"
#include "typeCube.hpp"

class World{
	private:
		std::vector<Cube*> m_allCubes;
   	public:
		World();
		~World();

		void draw(glm::mat4 MVMatrix);
		void handleEvents(const SDLKey e, const glm::vec3 position, const typeCube typePinceau);

		void addCube(const glm::vec3 position, const typeCube typePinceau);
		void changeNightMode();
};