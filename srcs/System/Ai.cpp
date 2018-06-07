/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.cpp
*/

#include "Ai.hpp"
#include "Component/Graphicals.hpp"

namespace ecs::system {

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
			/*for (auto line : map) {
				for (auto nb : line) {
					std::cout << nb;
				}
				std::cout << std::endl;
			}*/
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
				map[static_cast<int>(pos.Z) / 100][static_cast<int>(pos.X) / 100] = 4;
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