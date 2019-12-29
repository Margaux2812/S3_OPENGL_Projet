#pragma once

#include <GL/glew.h>
//#include "../include/TYPECUBE.hpp"
#include "../lib/glimac/include/glm.hpp"
#include <vector>
//To have the SDL_Event
#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "myshader.hpp"
#include "typeCube.hpp"

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionsCubes;

		//std::vector<MyShader> m_shaders;
		typeCube m_type;

	public :
		Cube(typeCube type);
		~Cube();
		void draw();
		void print();

		///// GETTERS /////

		inline GLuint getVao() { return m_vao;}
		inline GLuint getVbo() { return m_vbo;}
		inline GLuint getIbo() { return m_ibo;}
		// Shader getShader();
		//TYPECUBE getType();

		///// SETTERS /////

		void setVao(GLuint const newVao);
		void setVbo(GLuint const newVbo);
		void setIbo(GLuint const newIbo);
		//void setShader(std::string newVs, std::string newFs);
		//void setType(TYPECUBE newType);


		///// MANAGER /////

		void handleEvents(const SDLKey e, const glm::vec3 position, typeCube type);
		int findFromPosition(const glm::vec3 position);
		void updateGPU();
		void addCube(const glm::vec3 position);
		void replace(const glm::vec3 position);
		void deleteCube(const glm::vec3 position);
		void loadMonde();
		int findLastCube(const glm::vec3 position);
		void extrudeCube(glm::vec3 position);
		void digCube(glm::vec3 position);

};