#include "./menu.hpp"

namespace menu {

	void Menu::setRoot(std::string const &name)
	{
		std::cout << "set root to " << name << std::endl;
		this->_menu.push_front(name);
	}

	void Menu::push(std::string const &name)
	{
		std::cout << "go to " << name << std::endl;
		this->_menu.push_back(name);
	}

	void Menu::pop()
	{
		this->_menu.pop_back();
		std::cout << "return to " << this->_menu.back() << std::endl;
	}

	void Menu::viewCtrl()
	{
		std::cout << "--------" << std::endl;
		for (auto &e: this->_menu) {
			std::cout << e << std::endl;
		}
		std::cout << "--------" << std::endl;
	}

	// void menu::load()
	// {
	//
	// }

}

// Menu::setBackground(std::string const &background)
// {
// 	(void)background;
// }
//
// Menu::setString(std::string const &text)
// {
// 	this->_string.push_back(text);
// }
