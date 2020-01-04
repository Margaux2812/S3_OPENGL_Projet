#pragma once

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
   	public:
		World();
		~World();

		void draw(glm::mat4 MVMatrix);
		void handleEvents(const SDLKey e, const bool ctrlIsPressed);

		void addCube(const glm::vec3 position, const typeCube typePinceau);
		void replace(const glm::vec3 position, const typeCube typePinceau);
		void changeNightMode();
};