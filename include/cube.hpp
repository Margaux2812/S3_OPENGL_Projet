#pragma once

#include <GL/glew.h>

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;

		// A ajouter : m_shader ? m_position ? (ou sur Object) ? 
		// A ajouter : ENUM : type cube ? 	
	public :
		Cube();
		~Cube();
		void draw();
		void print();

		///// GETTERS /////

		GLuint getVao();
		GLuint getVbo();
		GLuint getIbo();

		///// SETTERS /////

		void setVao(GLuint newVao);
		void setVbo(GLuint newVbo);
		void setIbo(GLuint newIbo);


		///// MANAGER /////

		int findFromPosition(glm::vec3 position);
		void Cube::updateGPU();
		void addCube(glm::vec3 position);
		void deleteCube(glm::vec3 position);
		void extrudeCube(Cube &mapCube);
		void digCube(Cube &mapCube);

};