#pragma once

#include <string>
#include <GL/glew.h>
#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/Image.hpp"

class Texture{
private:
	GLuint m_textureID;
	std::string m_filepath;
	int m_width, m_height;
	GLvoid* m_BPP;

public:
	Texture(const std::string& path);
	~Texture();

	void bind(unsigned int slot=0) const;
	void unbind() const;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

	//TODO remove after debugging
	std::string name();
};