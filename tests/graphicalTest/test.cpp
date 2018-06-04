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


int main() {
	indie::Game &game = indie::Game::get();

	indie::mapGen(10, 10);
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	game.getDevice()->activateJoysticks(joystickInfo);
	ecs::system::Create::createPlayer("../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(100,100));

	game.gameLoop();
}
