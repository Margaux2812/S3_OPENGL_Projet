#pragma once

/*!
 * \file cube.hpp
 * \brief Classe Cube créant un tableau de cube du même type
 */

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
		/**
		 * @brief Construct a new Cube object
		 * @param type 
		 */
		Cube(typeCube type);
		/**
		 * @brief Destroy the Cube object
		 */
		~Cube();

		/**
		 * @brief Draw the OpenGL Object
		 * @param MVMatrix 
		 * @param lumieres 
		 */
		void draw(const glm::mat4 MVMatrix, const glm::vec3* lumieres);
		/**
		 * @brief Draw lights and apply on the cubes
		 * @param lumieres 
		 */
		void drawLights(Cube lumieres);

		///// GETTERS /////
		/**
		 * @brief getTexture of cube (return pointer on texture)
		 */
		Texture* getTexture() const;
		/**
		 * @brief Get the Vao attribute 
		 * @return GLuint 
		 */
		inline GLuint getVao() { return m_vao;}
		/**
		 * @brief Get the Vbo attribute
		 * @return GLuint 
		 */
		inline GLuint getVbo() { return m_vbo;}
		/**
		 * @brief Get the Ibo attribute
		 * @return GLuint 
		 */
		inline GLuint getIbo() { return m_ibo;}
		/**
		 * @brief get the size of the vectorPositions (<=> number of cubes of this type)
		 * @return GLuint 
		 */
		inline GLuint size() { return m_positionsCubes.size();}
		/**
		 * @brief Get the Data attribute of positionCubes (all position) 
		 * @return std::vector<glm::vec3> 
		 */
		inline std::vector<glm::vec3> getData() { return m_positionsCubes;}
		/**
		 * @brief Get the Type of cube vector
		 * @return typeCube 
		 */
		inline typeCube getType() {return m_type;}

		///// SETTERS /////

		/**
		 * @brief Set the Vao attribute of cube
		 * @param newVao 
		 */
		void setVao(GLuint const newVao);

		/**
		 * @brief Set the Vbo attribute of cube
		 * @param newVbo 
		 */
		void setVbo(GLuint const newVbo);
		
		/**
		 * @brief Set the Ibo attribute of cube
		 * @param newIbo 
		 */
		void setIbo(GLuint const newIbo);


		///// EVENT MANAGER /////

		void changeNightMode();
		int findFromPosition(const glm::vec3 position);
		void updateGPU();

		///// CUBE MANAGER /////

		bool addCube(const glm::vec3 position);
		void deleteCube(const glm::vec3 position);
		int initControles(Eigen::MatrixXf* ptsDeControle, Eigen::VectorXf* uk);
		void loadMonde();

};