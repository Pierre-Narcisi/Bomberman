/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include "irrlicht/driverChoice.h"

#include <iostream>

#include "Entity.hpp"
#include "Filter.hpp"
#include "Component.hpp"
#include "Components.hpp"

namespace ecs::system {

	class Create {
	public:
		static entity::Id createBackground(irr::video::ITexture *image, component::Rect rect, component::Color color)
		{
			auto id = entity::Manager::get().newEntity();
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Background);
			component::Manager<component::Image>::get().addComponentForEntity(id, image, rect, color);
			return id;
		}

		static entity::Id createButton(irr::video::ITexture *image, component::Rect rect, component::Color color, component::Position pos)
		{
			auto id = entity::Manager::get().newEntity();
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Button);
			component::Manager<component::Image>::get().addComponentForEntity(id, image, rect, color, pos);
			return id;
		}
	};

	// class Collider {
	// public:
	// 	static void check(entity::Id id, component::Type &type, component::Position &pos)
	// 	{
	// 		entity::Filter<component::Type, component::Position> fl;
	// 		auto &typeManager = component::Manager<component::Type>::get();
	// 		auto &posManager = component::Manager<component::Position>::get();
	//
	// 		for (auto enemyId : fl.list) {
	// 			if (id == enemyId || typeManager[enemyId].t != component::Type::Enum::Monster)
	// 				continue;
	// 			auto &enemyPos = posManager[enemyId];
	// 			if (enemyPos.x == pos.x && enemyPos.y == pos.y) {
	// 				apply(id, type, enemyId, typeManager[enemyId]);
	// 			}
	// 		}
	// 	}
	// private:
	// 	static void apply(entity::Id id, component::Type &type,
	// 		entity::Id enemyId, component::Type &enemyType)
	// 	{
	// 		if (type.t == enemyType.t)
	// 			std::cout << "salut poto" << std::endl;
	// 		else if (type.t == component::Type::Enum::Player) {
	// 			Kill::kill(enemyId);
	// 			Create::createMonster();
	// 		} else {
	// 			Kill::kill(id);
	// 			Create::createMonster();
	// 		}
	// 	}
	// };

	// class Position {
	// public:
	// 	static void update()
	// 	{
	// 		entity::Filter<component::Position, component::Type> fl;
	// 		auto &posManager = component::Manager<component::Position>::get();
	// 		auto &typeManager = component::Manager<component::Type>::get();
	//
	// 		for (auto id : fl.list) {
	// 			auto &pos = posManager[id];
	// 			if (typeManager[id].t == component::Type::Enum::Button) {
	// 				auto &speed = component::Manager<component::Speed>::get()[id];
	// 				pos.x += speed.x;
	// 				pos.y += speed.y;
	// 				speed = {0, 0};
	// 			}
	// 			// Collider::check(id, typeManager[id], pos);
	// 		}
	// 	}
	// };

	class Update {
	public:
		static void update(entity::Id id)
		{
			if (component::Manager<component::Image>::get()[id].color.a < 252) {
				component::Manager<component::Image>::get()[id].color.a += 2;
			}
		}
	};

	class Render {
	public:
		static void update(irr::video::IVideoDriver* driver)
		{
			entity::Filter<component::Image> fl;
			auto &typeManager = component::Manager<component::Image>::get();

			for (auto &e: fl.list) {
				component::Image &image = typeManager[e];
				driver->draw2DImage(image.image, irr::core::position2d<irr::s32>(image.pos.x, image.pos.y),
					irr::core::rect<irr::s32>(image.rect.xs, image.rect.ys, image.rect.xi, image.rect.yi), 0,
					irr::video::SColor(image.color.a, image.color.r, image.color.g, image.color.b), true);
			}
		}
	};

	// class Move {
	// public:
	// 	static void update()
	// 	{
	// 		std::string str;
	// 		entity::Filter<component::Speed> fl;
	// 		auto player = fl.list.front();
	// 		auto &speed = component::Manager<component::Speed>::get()[player];
	// 		std::cin >> str;
	//
	// 		for (auto c : str) {
	// 			if (c == 'z')
	// 				speed.y -= 1;
	// 			else if (c == 'q')
	// 				speed.x -= 1;
	// 			else if (c == 's')
	// 				speed.y += 1;
	// 			else if (c == 'd')
	// 				speed.x += 1;
	// 		}
	// 	}
	// };

	class Destroyer {
	public:
		static void update()
		{
			entity::Filter<component::Deletable> fl;
			auto &deleteManager = component::Manager<component::Deletable>::get();

			for (auto &id : fl.list) {
				if (deleteManager[id].del == true)
					entity::Manager::get().deleteEntity(id);
			}
		}
	};

}
