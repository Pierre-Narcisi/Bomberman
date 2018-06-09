/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Main.cpp
*/

#include "Game/Game.hpp"
#include "MapGen/mapGen.hpp"
#include "System/Create.hpp"
#include "System/CreateButton.hpp"
#include "System/Graphical.hpp"

int main()
{
	srand (time(NULL));
	indie::Game &game = indie::Game::get();

	irr::core::array<irr::SJoystickInfo> joystickInfo;
	game.getDevice()->activateJoysticks(joystickInfo);

	ecs::system::createBackground("./assets/buttons/maxresdefault.jpg", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{255, 255, 255, 255});
	ecs::system::createBackground("./assets/buttons/flou.jpg", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{0, 255, 255, 255});
	ecs::system::createBackground("./assets/buttons/title.png", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{255, 255, 255, 255});
	ecs::system::Scene::loadSceneOne();
	game.gameLoop();
}
