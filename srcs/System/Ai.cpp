/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.cpp
*/

#include "Ai.hpp"

namespace ecs { namespace system {

	void Ai::deplacement(int y, int x, int moving, entity::Id id)
	{
		auto &game = indie::Game::get();
		auto &being = component::Manager<component::Being>::get();
		auto &camera = component::Manager<component::Camera>::get();
		irr::f32 deltatime;
		irr::core::vector3df pos;
		irr::f32 speed = 300.f;
		float rot;

		speed = speed * component::Manager<component::Stat>::get()[id].speed;
		rot = being[id]._rotation;
		deltatime = static_cast<irr::f32>((game.getDevice()->getTimer()->getTime() - being[id]._then) / 1000.f);
		being[id]._then = game.getDevice()->getTimer()->getTime();

		// Set Rotation
		if (y == 0)
			rot = 270;
		else if (y == 1)
			rot = 90;
		if (x == 0) {
			if (rot == 270)
				rot = 225;
			else if (rot == 90)
				rot = 135;
			else
				rot = 180;
		} else if (x == 1) {
			if (rot == 270)
				rot = 315;
			else if (rot == 90)
				rot = 45;
			else
				rot = 0;
		}

		being[id]._node->setRotation(irr::core::vector3df(0, rot - 180, 0));

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

	int Ai::isViable(map_t map, int y, int x, int size)
	{
		int viable = 0;
		if (x + 1 < size && map[y][x + 1] == 2)
			viable++;
		if (y + 1 < size && map[y + 1][x] == 2)
			viable++;
		if (x - 1 >= 0 && map[y][x - 1] == 2)
			viable++;
		if (y - 1 >= 0 && map[y - 1][x] == 2)
			viable++;
		if (map[y][x] != 0)
			return 0;
		return viable;
	}
	
	irr::core::vector3df Ai::findSpot(map_t map, irr::core::vector3df pos)
	{
		int incr = 2;
		int size = map.size();
		irr::core::vector3df tmp;
		tmp.X = getPos(pos.X);
		tmp.Z = getPos(pos.Z);
		int x = getPos(pos.X) - 1;
		int y = getPos(pos.Z) - 1;

		tmp.X = x;
		tmp.Z = y;
		while (incr < size) {
			for (int i = 0; i < incr; i++) {
				if (y + i >= 0 && x >= 0 && y + i < size && x < size && isViable(map, y + i, x, size) != 0) {
					pos.Z = y + i;
					pos.X = x;
					return pos;
				} if (y + i >= 0 && x + incr >= 0 && y + i < size && x + incr < size && isViable(map, y + i, x + incr, size) != 0) {
					pos.Z = y + i;
					pos.X = x + incr;
					return pos;
				} if (y >= 0 && x + i >= 0 && y < size && x + i < size && isViable(map, y, x + i, size) != 0) {
					pos.Z = y;
					pos.X = x + i;
					return pos;
				} if (y + incr >= 0 && x + i >= 0 && y + incr < size && x + i < size && isViable(map, y + incr, x + i, size) != 0) {
					pos.Z = y + incr;
					pos.X = x + i;
					return pos;
				}
			}
			incr = incr + 2;
			x--;
			y--;
		}
		return tmp;
	}

	irr::core::vector3df Ai::findSafe(map_t map, irr::core::vector3df pos)
	{
		int incr = 2;
		int size = map.size();
		irr::core::vector3df tmp;
		tmp.X = getPos(pos.X);
		tmp.Z = getPos(pos.Z);
		int x = getPos(pos.X) - 1;
		int y = getPos(pos.Z) - 1;

		while (incr < size) {
			for (int i = 0; i < incr; i++) {
				if (y + i >= 0 && x >= 0 && y + i < size && x < size && map[y + i][x] == 0) {
					pos.Z = y + i;
					pos.X = x;
					return pos;
				} if (y + i >= 0 && x + incr >= 0 && y + i < size && x + incr < size && map[y + i][x + incr] == 0) {
					pos.Z = y + i;
					pos.X = x + incr;
					return pos;
				} if (y >= 0 && x + i >= 0 && y < size && x + i < size && map[y][x + i] == 0) {
					pos.Z = y;
					pos.X = x + i;
					return pos;
				} if (y + incr >= 0 && x + i >= 0 && y + incr < size && x + i < size && map[y + incr][x + i] == 0) {
					pos.Z = y + incr;
					pos.X = x + i;
					return pos;
				}
			}
			incr = incr + 2;
			x--;
			y--;
		}
		return tmp;
	}

	void Ai::bomb(int id, irr::core::vector3df pos)
	{
		irr::core::vector2di newpos;

		newpos.Y = pos.Z + 50 - std::fmod(static_cast<double>(pos.Z + 50) , 100.0);
		newpos.X = pos.X + 50 - std::fmod(static_cast<double>(pos.X + 50) , 100.0);
		Create::createBomb(id, newpos);
	}

	void Ai::moveTo(irr::core::vector3df to, irr::core::vector3df pos, int &free, entity::Id id)
	{
		int x = 2;
		int y = 2;
		irr::core::vector3df tmp;
		to.Z = to.Z * 100;
		to.X = to.X * 100;
		int moving = 0;
		auto &ai = component::Manager<component::Ai>::get();

		if (to.Z - pos.Z < 0 && abs(to.Z - pos.Z) > 5) {
			y = 1;
			moving = 1;
		} else if (to.Z - pos.Z > 0 && abs(to.Z - pos.Z) > 5) {
			y = 0;
			moving = 1;
		}
		if (to.X - pos.X < 0 && abs(to.X - pos.X) > 5) {
			x = 0;
			moving = 1;
		} else if (to.X - pos.X > 0 && abs(to.X - pos.X) > 5) {
			x = 1;
			moving = 1;
		}
		deplacement(y, x, moving, id);

		if (abs(to.X - pos.X) <= 5 &&abs(to.Z - pos.Z) <= 5) {
			if (free == 1) {
				free = 0;
				bomb(id, pos);
			} else if (time(NULL) >= ai[id].since) {
				free = 0;
			}
		}
	}

	int Ai::getPos(float pos)
	{
		return static_cast<int>(pos + 50) / 100;
	}

	void Ai::setGoal(irr::core::vector3df &goal, int &free, map_t map, irr::core::vector3df pos, entity::Id id)
	{
		auto &ai = component::Manager<component::Ai>::get();
	
		if (map[getPos(pos.Z)][getPos(pos.X)] == 5) {
			auto newpos = findSafe(map, pos);
			goal.X = newpos.X;
			goal.Z = newpos.Z;
			free = 2;
			ai[id].since = time(NULL) + 3;
		} else if (free == 0) {
			auto newpos = findSpot(map, pos);
			goal.X = newpos.X;
			goal.Z = newpos.Z;
			free = 1;
		}
	}

	void Ai::update(entity::Id id)
	{
		entity::Filter<component::Map> mapList;
		int moving = 0;
		auto &being = component::Manager<component::Being>::get();
		auto &ai = component::Manager<component::Ai>::get();

		if (!ai.hasComponent(id))
			return;
		auto &goal = ai[id].goal;
		auto &free = ai[id].free;

		for (auto &idmap : mapList.list) {
			auto map = component::Manager<component::Map>::get()[idmap].map;
			auto pos = being[id]._node->getPosition();
			zone(map);
			setGoal(goal, free, map, pos, id);
			moveTo(goal, pos, free, id);
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
}}