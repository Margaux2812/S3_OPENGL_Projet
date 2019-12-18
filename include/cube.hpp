#pragma once

#include <GL/glew.h>

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
	public :
		Cube();
		~Cube();
		void draw();

};