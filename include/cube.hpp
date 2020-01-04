#pragma once

#include <GL/glew.h>
#include "../lib/glimac/include/glm.hpp"
#include <vector>
//To have the SDL_Event
#include "../lib/glimac/include/SDLWindowManager.hpp"

#include "myshader.hpp"
#include "typeCube.hpp"
#include "texture.hpp"
#include "radialBasisFunctions.hpp"

class Cube{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionsCubes;

		typeCube m_type;
		Texture* m_texture;
		MyShader* m_shader;

		bool nightMode;

	public :
		Cube(typeCube type);
		~Cube();
		void draw(glm::mat4 MVMatrix, Cube lumieres);
		void drawLights(Cube lumieres);

		///// GETTERS /////
		Texture* getTexture() const;
		inline GLuint getVao() { return m_vao;}
		inline GLuint getVbo() { return m_vbo;}
		inline GLuint getIbo() { return m_ibo;}
		inline GLuint size() { return m_positionsCubes.size();}
		inline std::vector<glm::vec3> getData() { return m_positionsCubes;}
		inline typeCube getType() {return m_type;}

		///// SETTERS /////

		void setVao(GLuint const newVao);
		void setVbo(GLuint const newVbo);
		void setIbo(GLuint const newIbo);


		///// EVENT MANAGER /////

		void handleEvents(const SDLKey e, const glm::vec3 position, const typeCube type);
		void changeNightMode();
		int findFromPosition(const glm::vec3 position);
		void updateGPU();

		///// CUBE MANAGER /////

		bool addCube(const glm::vec3 position);
		void deleteCube(const glm::vec3 position);
		int initControles(Eigen::MatrixXf* ptsDeControle, Eigen::VectorXf* uk);
		void loadMonde();
		int findLastCube(const glm::vec3 position);
		void extrudeCube(glm::vec3 position);
		void digCube(glm::vec3 position);

};