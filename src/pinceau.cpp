#include "../include/pinceau.hpp"
#include <iostream>
Pinceau::Pinceau(){
	m_typeSelected = GROUND;
}

Pinceau::~Pinceau(){

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

        case SDLK_KP9: m_typeSelected = LIGHT;
        break;
        
        default:
        break;
    }
    std::cout << m_typeSelected << std::endl;
}

bool Pinceau::operator==(const typeCube type){
	return type == m_typeSelected;
}