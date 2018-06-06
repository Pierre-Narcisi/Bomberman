/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <ctime>
#include <cstdlib>

#include "Game.hpp"
#include "mapGen.hpp"
#include "Create.hpp"
#include "System/CreateButton.hpp"


int main() {
	indie::Game &game = indie::Game::get();

	indie::mapGen(10, 10);
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	game.getDevice()->activateJoysticks(joystickInfo);
	ecs::system::Create::createPlayer("./assets/sydney.md2", "./assets/sydney.bmp", irr::core::vector2df(100,100));
	// ecs::system::createBackground("./assets/buttons/maxresdefault.jpg", ecs::component::Rect{0, 0, 1920, 1080});
	// ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/exitWhite1.png",
	// ecs::component::Rect{700, 750, 400, 150}, "./assets/buttons/exitBlack1.png");
	game.gameLoop();
}
