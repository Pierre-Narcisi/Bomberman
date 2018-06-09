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
			entity::Filter<component::Button, component::Image> fl;
			auto &imgManager = component::Manager<component::Image>::get();

			for (auto &e: fl.list) {
				component::Image &img = imgManager[e];
				img.del = true;
			}
		};
		static void all()
		{
			entity::Filter<component::Image> fl;
			auto &imgManager = component::Manager<component::Image>::get();

			for (auto &e: fl.list) {
				component::Image &img = imgManager[e];
				img.del = true;
			}
		}
	};

	class Scene {
	public:
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
			ecs::component::Rect{700, 500, 418, 150}, "./assets/buttons/playBlack1.png");
			ecs::system::createButton(ecs::component::Button::Type::Quit, "./assets/buttons/multiWhite1.png",
			ecs::component::Rect{700, 750, 390, 140}, "./assets/buttons/exitBlack1.png");
		};
		static void LoadGame()
		{
			indie::mapGen(10, 10);
			ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo1.png", irr::core::vector2df(100,100));
			ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo2.png", irr::core::vector2df(900,100));
			ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo3.png", irr::core::vector2df(100,900));
			//ecs::system::Create::createPlayer("./assets/voodoo.ms3d", "./assets/voodoo4.png", irr::core::vector2df(1000,1000));
		};
	};
}
