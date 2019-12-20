#pragma once

enum MenuName {
	inGame,
	principal
};

class Menu{
	private:
		MenuName m_name;

	public :
		Menu();
		~Menu();
		
		MenuName getMenuName();
};