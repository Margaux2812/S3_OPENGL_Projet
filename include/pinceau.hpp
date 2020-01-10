#pragma once

#include "../lib/glimac/include/SDLWindowManager.hpp"
#include "typeCube.hpp"
#include "palette.hpp"

class Pinceau{
	
private:
	typeCube m_typeSelected;
	Palette* m_palette;
public:

	Pinceau();
	~Pinceau();

	inline typeCube getType(){ return m_typeSelected; };
	void handleEvents(const SDLKey e);
	bool operator==(const typeCube type);
	void draw();
};