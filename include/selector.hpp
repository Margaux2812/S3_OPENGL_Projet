#pragma once

#include "cube.hpp"

enum Fleche {haut, bas, gauche, droite, avant, arriere};

class Selector{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		glm::vec3 m_position;
		std::vector<glm::vec3> m_positionCube;
	public :
		Selector();
		~Selector();

		glm::vec3 getPosition();

		void draw();

		void handleEvents(SDLKey e);
		void updateGPU();
		void updatePos(glm::vec3 position);
		void move(Fleche direction);

};