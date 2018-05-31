#include "./menu.hpp"

int main()
{
	menu::Menu menu;

	menu.setRoot("home");
	menu.push("settings");
	menu.push("sound");
	menu.viewCtrl();
	menu.pop();
	menu.pop();
	menu.viewCtrl();
}
