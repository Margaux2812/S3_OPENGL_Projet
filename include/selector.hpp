#pragma once

#include "cube.hpp"

class Selector{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionsCube;
	public :
		Selector();
		void draw();
};