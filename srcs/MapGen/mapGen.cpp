/*
** EPITECH PROJECT, 2017
** Client
** File description:
** mapGen.c pp
*/

#include <random>

#include "Game/Game.hpp"
#include "System/Create.hpp"
#include "mapGen.hpp"

namespace indie {

	void mapGen::create_spawn()
	{
		_2Dmap[0][0] = 0;
		_2Dmap[1][0] = 0;
		_2Dmap[0][1] = 0;
		_2Dmap[_ymap - 1][0] = 0;
		_2Dmap[_ymap - 1][1] = 0;
		_2Dmap[_ymap - 2][0] = 0;
		_2Dmap[0][_xmap - 2] = 0;
		_2Dmap[1][_xmap - 1] = 0;
		_2Dmap[0][_xmap - 1] = 0;
		_2Dmap[_xmap - 2][_xmap - 1] = 0;
		_2Dmap[_xmap - 1][_xmap - 1] = 0;
		_2Dmap[_xmap - 1][_xmap - 2] = 0;
	}

	void	mapGen::make_unperfect()
	{
		std::uniform_int_distribution<int> distribution(0, 100);
		std::random_device rd;
		std::mt19937 engine(rd());

		for (std::size_t i = 0; i < _2Dmap.size(); ++i) {
			for (std::size_t j = 0; j < _2Dmap[i].size(); ++j) {
				if (_2Dmap[i][j] == 1 && distribution(engine) < 60)
					_2Dmap[i][j] = 2;
			}
		}
	}

	void	mapGen::generate2D()
	{
		bool			bol = false;
		std::pair<int ,int>	tmp;

		_2Dmap[0][0] = 2;
		while (gen.empty() == false || bol == false) {
			if (check_wall() != -1) {
				tmp = gen.back();
				choose_pos();
				gen.push_back(std::make_pair(_ygen, _xgen));
				_2Dmap[gen.back().first][gen.back().second] = 2;
				_2Dmap[gen.back().first + ((tmp.first - _ygen) / 2)][gen.back().second + ((tmp.second - _xgen) / 2)] = 2;
			} else {
				_xgen = gen.back().second;
				_ygen = gen.back().first;
				gen.pop_back();
			}
			bol = true;
		}
	}

	int	mapGen::check_wall()
	{
		if (_xgen + 2 < _xmap && _2Dmap[_ygen][_xgen + 2] == 1)
			return (0);
		if (_xgen - 2 >= 0 && _2Dmap[_ygen][_xgen - 2] == 1)
			return (2);
		if (_ygen + 2 < _ymap && _2Dmap[_ygen + 2][_xgen] == 1)
			return (3);
		if (_ygen - 2 >= 0 && _2Dmap[_ygen - 2][_xgen] == 1)
			return (1);
		return (-1);
	}

	void	mapGen::choose_pos()
	{
		std::uniform_int_distribution<int> distribution(0, 3);
		std::random_device rd;
		std::mt19937 engine(rd());

		do {
			int dir = distribution(engine);

			if (dir == 0 && _xgen + 2 < _xmap && _2Dmap[_ygen][_xgen + 2] == 1)
				_xgen += 2;
			else if (dir == 1 && _xgen - 2 >= 0 && _2Dmap[_ygen][_xgen - 2] == 1)
				_xgen -= 2;
			else if (dir == 2 && _ygen + 2 < _ymap && _2Dmap[_ygen + 2][_xgen] == 1)
				_ygen += 2;
			else if (dir == 3 && _ygen - 2 >= 0 && _2Dmap[_ygen - 2][_xgen] == 1)
				_ygen -= 2;
			else
				continue;
		} while (false);
	}

	void mapGen::createMap() const
	{
		for (int i = 0; i < _ymap; i++) {
			for (int j = 0; j < _xmap; j++) {
				if (_2Dmap[i][j] == 2)
					ecs::system::Create::createDeletableWall(irr::core::vector2df((i  + 1) * 100, (j + 1) * 100));
				else if (_2Dmap[i][j] == 1)
					ecs::system::Create::createWall(irr::core::vector2df((i  + 1) * 100, (j + 1) * 100));
			}
		}
	}

	void mapGen::createBorder() const
	{
		for (int i = 0; i < _xmap + 2; i++) {
			ecs::system::Create::createWall(irr::core::vector2df(0, i * 100));
			ecs::system::Create::createWall(irr::core::vector2df((_ymap + 1) * 100, i * 100));
		}
		for (int i = 0; i < _ymap + 2; i++) {
			ecs::system::Create::createWall(irr::core::vector2df(i * 100, 0));
			ecs::system::Create::createWall(irr::core::vector2df(i * 100, (_xmap + 1) * 100));
		}
	}

	mapGen::mapGen(int x, int y):
	_xmap{x},
	_ymap{y},
	gen{std::make_pair(_xgen, _ygen)},
	_2Dmap(y + 2, std::vector<int>(x + 2, 1))
	{
		generate2D();
		make_unperfect();
		create_spawn();
		createMap();
		createBorder();
		ecs::system::Create::createMap(_2Dmap);
	}

}
