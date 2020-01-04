#include "../include/pinceau.hpp"
#include <iostream>

Pinceau::Pinceau()
:m_typeSelected(GROUND),
m_palette(new Palette())
{
}

Pinceau::~Pinceau(){
    delete m_palette;
}

void Pinceau::handleEvents(const SDLKey e){
	switch(e){
        case SDLK_AMPERSAND: //1
        case SDLK_KP1: m_typeSelected = GROUND;
        break;
        case SDLK_WORLD_73 : //2
        case SDLK_KP2: m_typeSelected = SAND;
        break;
        case SDLK_QUOTEDBL: //3
        case SDLK_KP3: m_typeSelected = WATER;
        break;
        case SDLK_QUOTE : //4
        case SDLK_KP4: m_typeSelected = GRASS;
        break;
        case SDLK_LEFTPAREN : //5
        case SDLK_KP5: m_typeSelected = LEAF;
        break;
        //case  : //5
        case SDLK_KP6: m_typeSelected = BARBARA;
        break;

        case SDLK_KP9: m_typeSelected = LIGHT;
        break;
        
        default: //m_typeSelected = GROUND;
        break;
    }
    m_palette->update(m_typeSelected);
}

bool Pinceau::operator==(const typeCube type){
	return type == m_typeSelected;
}

void Pinceau::draw(){
    m_palette->draw();
}