#pragma once

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
public:
	Skybox();
	~Skybox();

	void draw(glm::mat4 MVMatrix);
	void loadTexture();
	void loadTextureFace(const GLenum side_target, const std::string path);
};