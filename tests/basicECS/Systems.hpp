/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include "Entity.hpp"
#include "Filter.hpp"
#include "Component.hpp"
#include "Components.hpp"

namespace ecs::system {

	class Create {
	public:
		static entity::Id createPlayer()
		{
			auto id = entity::Manager::get().newEntity();
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Player);
			component::Manager<component::Position>::get().addComponentForEntity(id, rand() % 10, rand() % 10);
			component::Manager<component::Speed>::get().addComponentForEntity(id);
			return id;
		}

		static entity::Id createMonster()
		{
			auto id = entity::Manager::get().newEntity();
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Monster);
			component::Manager<component::Position>::get().addComponentForEntity(id, rand() % 10, rand() % 10);
			component::Manager<component::Deletable>::get().addComponentForEntity(id);
			return id;
		}
	};

	class Kill {
	public:
		static void kill(entity::Id id)
		{
			if (component::Manager<component::Deletable>::get().hasComponent(id))
				component::Manager<component::Deletable>::get()[id].del = true;
			else
				entity::Manager::get().deleteEntity(id);
		}
	};

	class Collider {
	public:
		static void check(entity::Id id, component::Type &type, component::Position &pos)
		{
			entity::Filter<component::Type, component::Position> fl;
			auto &typeManager = component::Manager<component::Type>::get();
			auto &posManager = component::Manager<component::Position>::get();

			for (auto enemyId : fl.list) {
				if (id == enemyId || typeManager[enemyId].t != component::Type::Enum::Monster)
					continue;
				auto &enemyPos = posManager[enemyId];
				if (enemyPos.x == pos.x && enemyPos.y == pos.y) {
					apply(id, type, enemyId, typeManager[enemyId]);
				}
			}
		}
	private:
		static void apply(entity::Id id, component::Type &type,
			entity::Id enemyId, component::Type &enemyType)
		{
			if (type.t == enemyType.t)
				std::cout << "salut poto" << std::endl;
			else if (type.t == component::Type::Enum::Player) {
				Kill::kill(enemyId);
				Create::createMonster();
			} else {
				Kill::kill(id);
				Create::createMonster();
			}
		}
	};

	class Position {
	public:
		static void update()
		{
			entity::Filter<component::Position, component::Type> fl;
			auto &posManager = component::Manager<component::Position>::get();
			auto &typeManager = component::Manager<component::Type>::get();

			for (auto id : fl.list) {
				auto &pos = posManager[id];
				if (typeManager[id].t == component::Type::Enum::Player) {
					auto &speed = component::Manager<component::Speed>::get()[id];
					pos.x += speed.x;
					pos.y += speed.y;
					speed = {0, 0};
				} else {
					// pos.x += rand() % 3 - 1;
					// pos.y += rand() % 3 - 1;
				}
				Collider::check(id, typeManager[id], pos);
			}
		}
	};

	class Render {
	public:
		static void update()
		{
			entity::Filter<component::Type> fl;
			auto &typeManager = component::Manager<component::Type>::get();

			for (auto id : fl.list) {
				auto &type = typeManager[id];
				if (type.t == component::Type::Enum::Player) {
					auto &pos = component::Manager<component::Position>::get()[id];
					std::cout << "player is located at (" << pos.x << ", " << pos.y << ")" << std::endl;
				} else if (type.t == component::Type::Enum::Monster) {
					auto &pos = component::Manager<component::Position>::get()[id];
					std::cout << "Monster is located at (" << pos.x << ", " << pos.y << ")" << std::endl;
				}
			}
		}
	};

	class Move {
	public:
		static void update()
		{
			std::string str;
			entity::Filter<component::Speed> fl;
			auto player = fl.list.front();
			auto &speed = component::Manager<component::Speed>::get()[player];
			std::cin >> str;

			for (auto c : str) {
				if (c == 'z')
					speed.y -= 1;
				else if (c == 'q')
					speed.x -= 1;
				else if (c == 's')
					speed.y += 1;
				else if (c == 'd')
					speed.x += 1;
			}
		}
	};

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