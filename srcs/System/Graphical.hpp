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

#include "Component/Basics.hpp"
#include "Settings/Inputs.hpp"
#include "System/CreateButton.hpp"

#include "Game/Game.hpp"

namespace ecs::system {

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
				std::cout << "delete img" << std::endl;
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
				std::cout << "delete img" << std::endl;
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
			ecs::system::createButton(ecs::component::Button::Type::None, "./assets/buttons/multiWhite1.png",
			ecs::component::Rect{640, 750, 515, 150}, "./assets/buttons/multiBlack1.png");
		};
		static void loadGame()
		{
			indie::mapGen(10, 10);
			ecs::system::Create::createPlayer("./assets/sydney.md2", "./assets/redVoodoo.png", irr::core::vector2df(100,100));
		};
		static void loadMenuInGame()
		{
				ecs::system::createButton(ecs::component::Button::Type::Play, "./assets/buttons/playWhite1.png",
				ecs::component::Rect{700, 500, 418, 150}, "./assets/buttons/playBlack1.png");
				ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/exitWhite1.png",
				ecs::component::Rect{700, 750, 390, 140}, "./assets/buttons/exitBlack1.png");
		}
		static void unloadMenuInGame()
		{
				ecs::system::Deletable::button();
		}
	};
}
