/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.cpp
*/

#include "Ai.hpp"

namespace ecs::system {

	void Ai::deplacement(int dir, int y, int x)
	{
		auto &game = indie::Game::get();
		entity::Filter<component::Being, component::Ai> player;

		auto &being = component::Manager<component::Being>::get();
		auto &camera = component::Manager<component::Camera>::get();
		irr::f32 deltatime;
		irr::core::vector3df pos;
		irr::f32 speed = 300.f;
		float rot;
		bool moving;

		for (auto id : player.list) {
			auto pos = being[id]._node->getPosition();
			speed = speed * component::Manager<component::Stat>::get()[id].speed;
			rot = being[id]._rotation;
			deltatime = static_cast<irr::f32>((game.getDevice()->getTimer()->getTime() - being[id]._then) / 1000.f);
			being[id]._then = game.getDevice()->getTimer()->getTime();

			if (static_cast<int>(pos.X) != x || static_cast<int>(pos.Z) != y)
				moving = 1;
			else
				moving = 0;

			// Set Rotation
			if (dir == 0)
				rot = 270;
			else if (dir == 1)
				rot = 90;
			if (dir == 2) {
				if (rot == 270)
					rot = 225;
				else if (rot == 90)
					rot = 135;
				else
					rot = 180;
			} else if (dir == 3) {
				if (rot == 270)
					rot = 315;
				else if (rot == 90)
					rot = 45;
				else
					rot = 0;
			}

			being[id]._node->setRotation(irr::core::vector3df(0, rot, 0));



			// Set Animation
			if (moving == 0) {
				if (being[id]._lastMov != irr::scene::EMAT_STAND)
					Being::updateState(being[id], irr::scene::EMAT_STAND);
			} else {
				if (being[id]._lastMov != irr::scene::EMAT_RUN)
					Being::updateState(being[id], irr::scene::EMAT_RUN);

				being[id]._rotation = rot;
				pos = being[id]._node->getPosition();
				pos.X = pos.X + static_cast<float>(cos(rot * M_PI / 180)) * speed * deltatime;
				pos.Z = pos.Z - static_cast<float>(sin(rot * M_PI / 180)) * speed * deltatime;
				being[id]._node->setPosition(pos);
			}
		}

	}

	void Ai::line(map_t &map, int y, int x)
	{
		for (int i = 0; map[y - i][x] != 1 && map[y - i][x] != 2; i++) {
			map[y - i][x] = 5;
		}
		for (int i = 0; map[y + i][x] != 1 && map[y + i][x] != 2; i++) {
			map[y + i][x] = 5;
		}
		for (int i = 0; map[y][x - i] != 1 && map[y][x - i] != 2; i++) {
			map[y][x - i] = 5;
		}
		for (int i = 0; map[y][x + i] != 1 && map[y][x + i] != 2; i++) {
			map[y][x + i] = 5;
		}
	}

	void Ai::zone(map_t &map)
	{
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j] == 3)
					line(map, i, j);
			}
		}
	}

	void Ai::update(entity::Id ai)
	{
		entity::Filter<component::Map> mapList;
		for (auto &id : mapList.list) {
			auto map = component::Manager<component::Map>::get()[id].map;
			zone(map);
			deplacement(0, 200, 100);
			for (auto line : map) {
				for (auto nb : line) {
					std::cout << nb;
				}
				std::cout << std::endl;
			}
			//std::cout << std::endl;
		}

	}

	void Ai::updateAll()
	{
		entity::Filter<component::Type> fl;
		entity::Filter<component::Being> player;
		entity::Filter<component::UnanimatedObject> listWall;
		entity::Filter<component::UnanimatedObject, component::Deletable> list;
		entity::Filter<component::Map> mapList;
		
		auto &wall = component::Manager<component::UnanimatedObject>::get();
		auto &mesh = component::Manager<component::Mesh>::get();
		auto &delWall = component::Manager<component::Deletable>::get();
		auto &type = component::Manager<component::Type>::get();
		auto &being = component::Manager<component::Being>::get();



		for (auto &idmap : mapList.list) {
			auto &map = component::Manager<component::Map>::get()[idmap].map;
			for (int i = 0; i < map.size(); i++) {
				for (int j = 0; j < map[i].size(); j++) {
					map[i][j] = 0;
				}
			}
			for (auto &id : player.list) {
				auto pos = being[id]._node->getPosition();
				map[static_cast<int>(pos.Z + 50) / 100][static_cast<int>(pos.X + 50) / 100] = 4;
			}
			for (auto &id : fl.list) {
				if (mesh.hasComponent(id) == true) {
					auto pos = mesh[id].mesh->getPosition();
					if (type.hasComponent(id) == true && type[id].t == component::Type::Enum::Bomb)
						map[pos.Z / 100][pos.X / 100] = 3;
				}
			}
			for (auto &id : listWall.list) {
				auto pos = wall[id]._node->getPosition();
	
				if (type.hasComponent(id) == true && type[id].t == component::Type::Enum::Wall) {
					map[pos.Z / 100][pos.X / 100] = 1;
				}
			}
			for (auto &id : list.list) {
				auto pos = wall[id]._node->getPosition();
				map[pos.Z / 100][pos.X / 100] = 2;
			}
		}
	}
}