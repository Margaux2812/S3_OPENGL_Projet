#pragma once

#include <GL/glew.h>
//#include "../include/TYPECUBE.hpp"
#include "../lib/glimac/include/glm.hpp"
#include <vector>

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionsCubes;

		// glm::vec3 m_position;
		// Shader m_shader;
		//TYPECUBE m_type;

	public :
		Cube();
		~Cube();
		void draw();
		void print();

		///// GETTERS /////

		GLuint getVao();
		GLuint getVbo();
		GLuint getIbo();
		// Shader getShader();
		//TYPECUBE getType();

		///// SETTERS /////

		void setVao(GLuint newVao);
		void setVbo(GLuint newVbo);
		void setIbo(GLuint newIbo);
		//void setShader(std::string newVs, std::string newFs);
		//void setType(TYPECUBE newType);


		///// MANAGER /////

		int findFromPosition(glm::vec3 position);
		void updateGPU();
		void addCube(glm::vec3 position);
		void replace(glm::vec3 position);
		void deleteCube(glm::vec3 position);
		void loadMonde();
		int findLastCube(glm::vec3 position);
		void extrudeCube(glm::vec3 position);
		void digCube(glm::vec3 position);

};