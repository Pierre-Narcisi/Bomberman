/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.cpp
*/

#include "Ai.hpp"
#include "Component/Graphicals.hpp"

namespace ecs::system {

	void Ai::update(entity::Id ai, map_t const &map)
	{

	}

	void Ai::updateAll()
	{
		entity::Filter<component::Type> fl;
		entity::Filter<component::UnanimatedObject, component::Deletable> list;
		entity::Filter<component::Map> mapList;
		auto &wall = component::Manager<component::UnanimatedObject>::get();
		auto &mesh = component::Manager<component::Mesh>::get();
		auto &delWall = component::Manager<component::Deletable>::get();
		auto &type = component::Manager<component::Type>::get();


		for (auto &id : mapList.list) {
			auto &map = component::Manager<component::Map>::get()[id].map;
			for (int i = 0; i < map.size(); i++) {
				for (int j = 0; j < map[i].size(); j++) {
					map[i][j] = 0;		
				}	
			}
			for (auto &id : fl.list) {
				if (type[id].t == component::Type::Enum::Bomb) {
					auto pos = mesh[id].mesh->getPosition();
					map[pos.Z / 100][pos.X / 100] = 3;
				} else if (type[id].t == component::Type::Enum::Wall) {
					auto pos = wall[id]._node->getPosition();
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