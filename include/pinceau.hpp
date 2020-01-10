#pragma once

/*!
 * \file pinceau.hpp
 * \brief Create a pinceau
 */

#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "typeCube.hpp"
#include "palette.hpp"

class Pinceau{
	
private:
	typeCube m_typeSelected;
	Palette* m_palette;
public:

	/**
	 * @brief Construct a new Pinceau object
	 * 
	 */
	Pinceau();

	/**
	 * @brief Destroy the Pinceau object
	 * 
	 */
	~Pinceau();

	/**
	 * @brief Get the Type_Selected object
	 * 
	 * @return typeCube of cube selected
	 */
	inline typeCube getType(){ return m_typeSelected; };

	/**
	 * @brief event manager
	 * 
	 * @param e event to manage
	 */
	void handleEvents(const SDLKey e);

	/**
	 * @brief == operator overloading
	 * 
	 * @param type type to test
	 * @return true if type == m_typeSelected
	 * @return false if type != m_typeSelected
	 */
	bool operator==(const typeCube type);

	/**
	 * @brief call palette.draw() function
	 * 
	 */
	void draw();
};