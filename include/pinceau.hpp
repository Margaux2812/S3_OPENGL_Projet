#pragma once

#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "typeCube.hpp"

class Pinceau{
	
private:
	typeCube m_typeSelected;
public:

	Pinceau();
	~Pinceau();

	inline typeCube getType() {return m_typeSelected;}
	void handleEvents(const SDLKey e);
	bool operator==(const typeCube type);
};