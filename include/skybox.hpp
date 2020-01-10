#pragma once

/*!
 * \file skybox.hpp
 * \brief Create a skybox
 */

#include <GL/glew.h>
#include <string>
#include "../lib/glimac/include/glm.hpp"
#include "myshader.hpp"

class Skybox{
private:
	GLenum m_skyboxTarget[6] = {GL_TEXTURE_CUBE_MAP_POSITIVE_X,
        GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
        GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
        GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
        GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
        GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };

	GLuint m_vao;
	GLuint m_vbo;
	GLuint m_textureID; //Jour et nuit
	MyShader* m_shader;
	bool isDay;

public:

	/**
	 * @brief Construct a new Skybox object
	 * 
	 */
	Skybox();

	/**
	 * @brief Destroy the Skybox object
	 * 
	 */
	~Skybox();

	/**
	 * @brief change night to day and vice versa
	 * 
	 */
	void updateSky();

	/**
	 * @brief draw the OpenGL Object
	 * 
	 * @param MVMatrix 
	 */
	void draw(glm::mat4 MVMatrix);

	/**
	 * @brief load skybox Texture (doesn't work)
	 * 
	 */
	void loadTexture();

};