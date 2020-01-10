#pragma once

/*!
 * \file texture.hpp
 * \brief Create a texture
 */

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

	/**
	 * @brief Construct a new Texture object from path
	 * 
	 * @param path 
	 */
	Texture(const std::string& path);

	/**
	 * @brief Destroy the Texture object
	 * 
	 */
	~Texture();

	/**
	 * @brief bind the textur
	 * 
	 * @param slot 
	 */
	void bind(unsigned int slot=0) const;

	/**
	 * @brief unbing the texture 
	 * 
	 */
	void unbind() const;

	/**
	 * @brief Get the Width object
	 * 
	 * @return int 
	 */
	inline int getWidth() const { return m_width; }

	/**
	 * @brief Get the Height object
	 * 
	 * @return int 
	 */
	inline int getHeight() const { return m_height; }
};