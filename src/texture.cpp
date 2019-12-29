#include "../include/texture.hpp"
#include <iostream>

Texture::Texture(const std::string& path)
: m_textureID(0),
m_filepath(path),
m_width(0),
m_height(0),
m_BPP(nullptr)
{
	std::unique_ptr<glimac::Image> textureImg = glimac::loadImage(path);

	if(textureImg == NULL)
		std::cout << "Image located in "<< path << " not loaded !" <<std::endl;

	m_width = textureImg->getWidth();
	m_height = textureImg->getHeight();
	m_BPP = textureImg->getPixels();

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		m_width,
		m_height,
		0,
		GL_RGBA,
		GL_FLOAT,
		m_BPP
		);
}

Texture::~Texture(){
	glDeleteTextures(1, &m_textureID);
}


void Texture::bind(unsigned int slot) const{
	glActiveTexture(GL_TEXTURE+slot);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void Texture::unbind() const{
	glBindTexture(GL_TEXTURE_2D, 0);
}

std::string Texture::name(){
	return m_filepath;
}

