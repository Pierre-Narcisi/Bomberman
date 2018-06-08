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
#include "../irrKlang/include/ik_ISound.h"
#include "../irrKlang/include/ik_ISound.h"
#include "../irrKlang/include/ik_EStreamModes.h"
#include "../irrKlang/include/irrKlang.h"

int main()
{
	irrklang::ISound *introMusic;
	irrklang::ISoundEngine *engine;

	indie::Game &game = indie::Game::get();
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	game.getDevice()->activateJoysticks(joystickInfo);

	engine = irrklang::createIrrKlangDevice();
	introMusic = engine->play2D("./assets/Varien-Lilith.wav", true,
		false, false, irrklang::ESM_AUTO_DETECT, true);

	introMusic->setVolume(static_cast<irr::f32>(1));

	ecs::system::Scene::loadBackground();
	ecs::system::Scene::loadSceneOne();
	game.gameLoop();
}
