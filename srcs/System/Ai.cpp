/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.cpp
*/

#include "Ai.hpp"

namespace ecs::system {

	void Ai::update(entity::Id ai, map_t const &map)
	{

	}

	void Ai::updateAll()
	{
		entity::Filter<component::UnanimatedObject> fl;
		entity::Filter<component::UnanimatedObject, component::Deletable> list;
		entity::Filter<component::Map> mapList;
		auto &wall = component::Manager<component::UnanimatedObject>::get();
		auto &delWall = component::Manager<component::UnanimatedObject, component::Deletable>::get();
		map_t &map;
		irr::core::vector2df pos;

		for (auto &id : mapList.list) {
			map = component::Manager<ecs::component::Map>::get()[id].map;
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				map[i][j] = 0;			
			}	
		}
		for (auto &id : fl.list) {
			pos = wall[id]._node.getPosition();
			if (wall[id]._node.getType() == component::Type::Bomb) {
				map[pos.y / 100][pos.x / 100] = 3;
			} else if (wall[id]._node.getType() == component::Type::Wall) {
				map[pos.y / 100][pos.x / 100] = 1;
			}
		}
		for (auto &id : list.list) {
			pos = delWall[id]._node.getPosition();
			map[pos.y / 100][pos.x / 100] = 2;		
		}
	}
}