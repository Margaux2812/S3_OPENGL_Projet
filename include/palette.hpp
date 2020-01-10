#pragma once
#include "myshader.hpp"
#include "texture.hpp"
#include "vertex.hpp"
#include "typeCube.hpp"

class Palette{
private:
	MyShader* m_shader;
	Texture* m_texture;
    GLuint m_ibo;
    GLuint m_vbo;
    GLuint m_vao;
    const VertexTex vertices[4] = { 
	    VertexTex(glm::vec2(-0.95f, 0.87f), 
	            glm::vec2(0.f, 0.f)),
	    VertexTex(glm::vec2(-0.805f, 0.87f), 
	            glm::vec2(1.f, 0.f)),
	    VertexTex(glm::vec2(-0.805f, -0.87f),
	            glm::vec2(1.f, 1.f)),
	    VertexTex(glm::vec2(-0.95f, -0.87f), 
	            glm::vec2(0.f, 1.f))
	};

	const uint32_t indices[6] = {
	    0, 1, 2,
	    2, 3, 0
	};

public:
	Palette();
	~Palette();
	void draw();
	void update(const typeCube type);
};