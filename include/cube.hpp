#pragma once

#include <GL/glew.h>
#include "TYPECUBE.hpp"

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;

		// glm::vec3 m_position;
		// Shader m_shader;
		// TYPECUBE m_typeCube;

	public :
		Cube();
		~Cube();
		void draw();
		void print();

		///// GETTERS /////

		GLuint getVao();
		GLuint getVbo();
		GLuint getIbo();
		// glm::vec3 getPosition();
		// Shader getShader();
		// TypeCube getType();

		///// SETTERS /////

		void setVao(GLuint newVao);
		void setVbo(GLuint newVbo);
		void setIbo(GLuint newIbo);
		void setPosition(glm::vec3 newPos);
		void setShader(std::string newVs, std::string newFs);
		void setType(TYPECUBE newType);


		///// MANAGER /////

		Cube findFromPosition(Cube &mapCube, glm::vec3 position);
		void addCube(std::string vs, std::string fs);
		void deleteCube();
		void extrudeCube(Cube &mapCube);
		void digCube(Cube &mapCube);

};