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
#include "irrKlang/ik_ISound.h"
#include "irrKlang/ik_ISound.h"
#include "irrKlang/ik_EStreamModes.h"
#include "irrKlang/irrKlang.h"

int main()
{
	indie::Game &game = indie::Game::get();
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	game.getDevice()->activateJoysticks(joystickInfo);

	ecs::system::Scene::sound(0);
	ecs::system::Scene::loadBackground();
	ecs::system::Scene::loadSceneOne();
	game.gameLoop();
}
