#pragma once

/*!
 * \file cube.hpp
 * \brief Create same type cubes vector
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
		 * \fn Cube::Cube()
		 * 
		 * \brief Construct a new Cube object
		 * \param type 
		 */
		Cube(typeCube type);
		/**
		 * \brief Destroy the Cube object
		 */
		~Cube();

		/**
		 * \brief Draw the OpenGL Object
		 * \param MVMatrix 
		 * \param lumieres 
		 */
		void draw(const glm::mat4 MVMatrix, const glm::vec3* lumieres);

		///// GETTERS /////
		/**
		 * \brief getTexture of cube (return pointer on texture)
		 */
		Texture* getTexture() const;
		/**
		 * \brief Get the Vao attribute 
		 * \return GLuint 
		 */
		inline GLuint getVao() { return m_vao;}
		/**
		 * \brief Get the Vbo attribute
		 * \return GLuint 
		 */
		inline GLuint getVbo() { return m_vbo;}
		/**
		 * \brief Get the Ibo attribute
		 * \return GLuint 
		 */
		inline GLuint getIbo() { return m_ibo;}
		/**
		 * \brief get the size of the vectorPositions (<=> number of cubes of this type)
		 * \return GLuint 
		 */
		inline GLuint size() { return m_positionsCubes.size();}
		/**
		 * \brief Get the Data attribute of positionCubes (all position) 
		 * \return std::vector<glm::vec3> 
		 */
		inline std::vector<glm::vec3> getData() { return m_positionsCubes;}
		/**
		 * \brief Get the Type of cube vector
		 * \return typeCube 
		 */
		inline typeCube getType() {return m_type;}

		///// SETTERS /////

		/**
		 * \brief Set the Vao attribute of cube
		 * \param newVao new value of Vao
		 */
		void setVao(GLuint const newVao);

		/**
		 * \brief Set the Vbo attribute of cube
		 * \param newVbo new value of Vbo
		 */
		void setVbo(GLuint const newVbo);
		
		/**
		 * \brief Set the Ibo attribute of cube
		 * \param newIbo new value of Ibo
		 */
		void setIbo(GLuint const newIbo);


		///// EVENT MANAGER /////

		/**
		 * \brief Cube Event Manager
		 * \param e event
		 * \param position position of selector
		 * \param type type selected
		 */
		void handleEvents(const SDLKey e, const glm::vec3 position, const typeCube type);

		/**
		 * \brief Change night mode to day mode and vice versa
		 * 
		 */
		void changeNightMode();

		/**
		 * \brief find a cube from the position
		 * \param position position known
		 * \return int 
		 */
		int findFromPosition(const glm::vec3 position);

		/**
		 * \brief Update GPU (Buffer functions)
		 * 
		 */
		void updateGPU();

		///// CUBE MANAGER /////

		/**
		 * \brief Add a cube in world 
		 * \param position position of selector
		 * \return true if created
		 * \return false if error
		 */
		bool addCube(const glm::vec3 position);

		/**
		 * \brief Delete a cube from world
		 * \param position position of selector
		 */
		void deleteCube(const glm::vec3 position);

		/**
		 * \brief Read ptsDeControle file and fill Matrix world
		 * \param ptsDeControle Matrix of ptsDeControle
		 * \param uk vector of ptsDeControle
		 * \return int 
		 */
		int initControles(Eigen::MatrixXf* ptsDeControle, Eigen::VectorXf* uk);

		/**
		 * \brief Load cube for base world from with ptsDeControle function
		 * 
		 */
		void loadMonde();

		/**
		 * \brief find last cube of a column
		 * \param position position known
		 * \return int 
		 */
		int findLastCube(const glm::vec3 position);

		/**
		 * \brief extrude current cube (with same type)
		 * \param position position of selector
		 */
		void extrudeCube(glm::vec3 position);
		
		/**
		 * \brief dig the same type cube from the top of the column
		 * \param position position of selector
		 */
		void digCube(glm::vec3 position);

};