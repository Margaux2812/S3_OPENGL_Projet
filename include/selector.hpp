#pragma once

#include "cube.hpp"

enum Fleche {haut, bas, gauche, droite};

class Selector{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionCube;
	public :
		Selector();
		void draw();
		void updateGPU();
		void updatePos(glm::vec3 position);
		void move(Fleche direction);
};