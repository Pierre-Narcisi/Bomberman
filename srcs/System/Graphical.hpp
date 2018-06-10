/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Graphical.hpp
*/

#pragma once

#include <iostream>

#include "ECS/Entity/Entity.hpp"
#include "ECS/Entity/Filter.hpp"
#include "ECS/Component/Component.hpp"

#include "Component/Graphicals.hpp"
#include "MapGen/mapGen.hpp"
#include "System/Create.hpp"
#include "System/Destroyer.hpp"

#include "Component/Basics.hpp"
#include "Settings/Inputs.hpp"
#include "System/CreateButton.hpp"

#include "Game/Game.hpp"

#include "irrKlang/ik_ISound.h"
#include "irrKlang/ik_ISound.h"
#include "irrKlang/ik_EStreamModes.h"
#include "irrKlang/irrKlang.h"

namespace ecs { namespace system {

	class Blur {
	public:
		static void update()
		{
			entity::Filter<component::Color, component::Image> fl;
			auto &colorManager = component::Manager<component::Color>::get();

			for (auto &e: fl.list) {
				component::Color &color = colorManager[e];
				if (color.a < 252) {
					color.a += 2;
				}
			}
		}
	};

	class Deletable {
	public:
		static void button()
		{
			entity::Filter<component::Deletable, component::Button, component::Image> fl;
			auto &imgManager = component::Manager<component::Image>::get();
			auto &delManager = component::Manager<component::Deletable>::get();
			auto &game = indie::Game::get();

			for (auto &e: fl.list) {
				component::Image &img = imgManager[e];
				game.getDriver()->removeTexture(img.image);
				delManager[e].del = true;
			}
		};
		static void all()
		{
			entity::Filter<component::Deletable, component::Image> fl;
			auto &imgManager = component::Manager<component::Image>::get();
			auto &delManager = component::Manager<component::Deletable>::get();
			auto &game = indie::Game::get();

			for (auto &e: fl.list) {
				component::Image &img = imgManager[e];
				game.getDriver()->removeTexture(img.image);
				delManager[e].del = true;
			}
		}
	};

	class Scene {
	public:
		static void loadBackground()
		{
			ecs::system::createBackground("./assets/buttons/maxresdefault.jpg", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{255, 255, 255, 255});
			ecs::system::createBackground("./assets/buttons/flou.jpg", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{0, 255, 255, 255});
			ecs::system::createBackground("./assets/buttons/title.png", ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{255, 255, 255, 255});
		};
		static void loadSceneOne()
		{
			ecs::system::createButton(ecs::component::Button::Type::Play, "./assets/buttons/playWhite1.png",
			ecs::component::Rect{700, 500, 418, 150}, "./assets/buttons/playBlack1.png");
			ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/exitWhite1.png",
			ecs::component::Rect{700, 750, 390, 140}, "./assets/buttons/exitBlack1.png");
		};
		static void loadSceneTwo()
		{
			ecs::system::createButton(ecs::component::Button::Type::Solo, "./assets/buttons/soloWhite1.png",
			ecs::component::Rect{700, 500, 420, 140}, "./assets/buttons/soloBlack1.png");
			ecs::system::createButton(ecs::component::Button::Type::Start, "./assets/buttons/multiWhite1.png",
			ecs::component::Rect{640, 750, 515, 150}, "./assets/buttons/multiBlack1.png");
		};
		static void loadSceneThree()
		{
			ecs::system::createButton(ecs::component::Button::Type::Yellow, "./assets/voodooYellow.png",
			ecs::component::Rect{200, 350, 280, 467}, "./assets/voodooYellow.png");
			ecs::system::createButton(ecs::component::Button::Type::Blue, "./assets/voodooBlue.png",
			ecs::component::Rect{600, 350, 288, 467}, "./assets/voodooBlue.png");
			ecs::system::createButton(ecs::component::Button::Type::Red, "./assets/voodooRed.png",
			ecs::component::Rect{1000, 350, 288, 467}, "./assets/voodooRed.png");
			ecs::system::createButton(ecs::component::Button::Type::Green, "./assets/voodooGreen.png",
			ecs::component::Rect{1400, 350, 288, 467}, "./assets/voodooGreen.png");
			ecs::system::createButton(ecs::component::Button::Type::Start, "./assets/buttons/startGameWhite1.png",
			ecs::component::Rect{470, 900, 920, 126}, "./assets/buttons/startGameBlack1.png");
		};
		static void loadGame(std::string &color)
		{
			indie::mapGen(10, 10);
			// ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo1.png", irr::core::vector2df(100,100));
			// ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo2.png", irr::core::vector2df(900,100));
			// // ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo3.png", irr::core::vector2df(100,900));
			// //ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo4.png", irr::core::vector2df(1000,1000));
			// ecs::system::Create::createAi("./assets/voodoo.ms3d", "./assets/voodoo4.png", irr::core::vector2df(100,900));	
			ecs::system::Create::createPlayer("./assets/voodoo.ms3d", color, irr::core::vector2df(100,100));
		};
		static void loadMenuInGame()
		{
			ecs::system::Scene::loadOpt();
		}
		static void unloadMenuInGame()
		{
			ecs::system::Deletable::button();
		}
		static void loadWinMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/win.png",
			ecs::component::Rect{520, 200, 908, 166}, "");
			ecs::system::Scene::loadOpt();
		}
		static void loadLooseMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/loose.png",
			ecs::component::Rect{450, 200, 1103, 164}, "");
			ecs::system::Scene::loadOpt();
		}
		static void load1WinMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/player1Win.png",
			ecs::component::Rect{350, 200, 1163, 141}, "");
			ecs::system::Scene::loadOpt();
		}
		static void load2WinMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/player2Win.png",
			ecs::component::Rect{350, 200, 1180, 140}, "");
			ecs::system::Scene::loadOpt();
		}
		static void load3WinMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/player3Win.png",
			ecs::component::Rect{350, 200, 1178, 138}, "");
			ecs::system::Scene::loadOpt();
		}
		static void load4WinMenu()
		{
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/player4Win.png",
			ecs::component::Rect{350, 200, 1177, 138}, "");
			ecs::system::Scene::loadOpt();
		}
		static void loadOpt()
		{
			ecs::system::createButton(ecs::component::Button::Type::MusicUp, "./assets/buttons/add.png",
			ecs::component::Rect{600, 370, 64, 64}, "./assets/buttons/add.png");
			ecs::system::createButton(ecs::component::Button::Type::MusicDown, "./assets/buttons/down.png",
			ecs::component::Rect{1180, 370, 64, 64}, "./assets/buttons/down.png");
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/sound.png",
			ecs::component::Rect{730, 350, 382, 102}, "");
			ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/restartWhite1.png",
			ecs::component::Rect{660, 500, 515, 110}, "./assets/buttons/restartBlack1.png");
			ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/mainMenuWhite1.png",
		 	ecs::component::Rect{580, 650, 660, 110}, "./assets/buttons/mainMenuBlack1.png");
		}
		static void sound(int action)
		{
			static int pass = 0;
			static irrklang::ISound *introMusic;

			if (pass == 0) {
				irrklang::ISoundEngine *engine;
				engine = irrklang::createIrrKlangDevice();
				introMusic = engine->play2D("./assets/Varien-Lilith.wav", true,
				false, false, irrklang::ESM_AUTO_DETECT, true);

				introMusic->setVolume(static_cast<irr::f32>(0.5));
				pass++;
				return;
			}

			if (action == -1 && introMusic->getVolume() > 0) {
				introMusic->setVolume(introMusic->getVolume() - 0.1);
			} else if (action == 1 && introMusic->getVolume() < 1) {
				introMusic->setVolume(introMusic->getVolume() + 0.1);
			}
		}
	};
}}