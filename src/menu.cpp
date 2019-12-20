#include "../include/menu.hpp"

Menu::Menu(){
	m_name = inGame;
}

Menu::~Menu(){

}

		
MenuName Menu::getMenuName(){
	return m_name;
}

