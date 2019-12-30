#pragma once

#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "typeCube.hpp"

class Pinceau{
	
private:
	typeCube m_typeSelected;
public:

	Pinceau();
	~Pinceau();

	void handleEvents(const SDLKey e);
	bool operator==(const typeCube type);
};