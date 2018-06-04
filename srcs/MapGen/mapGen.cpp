/*
** EPITECH PROJECT, 2017
** Client
** File description:
** mapGen.c pp
*/

#include "mapGen.hpp"

void mapGen::create_spawn()
{
	_2Dmap[0][0] = '0';
	_2Dmap[1][0] = '0';
	_2Dmap[0][1] = '0';
	_2Dmap[_ymap - 1][0] = '0';
	_2Dmap[_ymap - 1][1] = '0';
	_2Dmap[_ymap - 2][0] = '0';
	_2Dmap[0][_xmap - 2] = '0';
	_2Dmap[1][_xmap - 1] = '0';
	_2Dmap[0][_xmap - 1] = '0';
	_2Dmap[_xmap - 2][_xmap - 1] = '0';
	_2Dmap[_xmap - 1][_xmap - 1] = '0';
	_2Dmap[_xmap - 1][_xmap - 2] = '0';
}

void	mapGen::make_unperfect()
{
  unsigned long i;
  unsigned long j;

  i = 0;
  while (i < _2Dmap.size()) {
      j = 0;
      while (j < _2Dmap[i].size()) {
	  		if (_2Dmap[i][j] == '1' && rand() % 100 < 60)
	    		_2Dmap[i][j] = '2';
	  		j++;
			}
      i++;
  }
}

void	mapGen::generate2D()
{
  int	bol;
  std::pair<int ,int>	tmp;

  _2Dmap[0][0] = '2';
  bol = 0;
  while (!gen.empty() || bol == 0) {
      if (check_wall() != -1) {
	  tmp = gen.back();
	  choose_pos();
	  gen.push_back(std::pair<int, int> (_ygen, _xgen));
	  _2Dmap[gen.back().first][gen.back().second] = '2';
	  _2Dmap[gen.back().first + ((tmp.first - _ygen) / 2)][gen.back().second + ((tmp.second - _xgen) / 2)] = '2';
		} else {
	  	_xgen = gen.back().second;
	  	_ygen = gen.back().first;
		  gen.pop_back();
		}
      bol = 1;
    }
}

int	mapGen::check_wall()
{
  if (_xgen + 2 < _xmap && _2Dmap[_ygen][_xgen + 2] == '1')
    return (0);
  if (_xgen - 2 >= 0 && _2Dmap[_ygen][_xgen - 2] == '1')
    return (2);
  if (_ygen + 2 < _ymap && _2Dmap[_ygen + 2][_xgen] == '1')
    return (3);
  if (_ygen - 2 >= 0 && _2Dmap[_ygen - 2][_xgen] == '1')
    return (1);
  return (-1);
}

void	mapGen::choose_pos()
{
  int	dir;
  int	bol;

  bol = 0;
  while (bol == 0)
    {
      dir = rand() % 4;
      if (dir == 0 && _xgen + 2 < _xmap && _2Dmap[_ygen][_xgen + 2] == '1') {
			bol = 1;
			_xgen += 2;
      } else if (dir == 1 && _xgen - 2 >= 0 && _2Dmap[_ygen][_xgen - 2] == '1') {
			bol = 1;
			_xgen -= 2;
      } else if (dir == 2 && _ygen + 2 < _ymap && _2Dmap[_ygen + 2][_xgen] == '1') {
			bol = 1;
			_ygen += 2;
      } else if (dir == 3 && _ygen - 2 >= 0 && _2Dmap[_ygen - 2][_xgen] == '1') {
			bol = 1;
			_ygen -= 2;
      }
    }
}


void mapGen::createBorder()
{
	irr::core::vector2df pos;

	for (int i = 0; i < _xmap + 2; i++) {
		ecs::system::Create::createWall(_driver, _smgr, irr::core::vector2df(0, i * 100));
		ecs::system::Create::createWall(_driver, _smgr, irr::core::vector2df((_xmap + 1) * 100, i * 100));
	}
	for (int i = 0; i < _ymap + 2; i++) {
		ecs::system::Create::createWall(_driver, _smgr, irr::core::vector2df(i * 100, 0));
		ecs::system::Create::createWall(_driver, _smgr, irr::core::vector2df(i * 100, (_ymap + 1) * 100));
	}
}

void mapGen::createMap()
{
	createBorder();
	for (int i = 0; i < _ymap; i++) {
		for (int j = 0; j < _xmap; j++) {
			if (_2Dmap[i][j] == '2') {
				ecs::system::Create::createDeletableWall(_driver, _smgr, irr::core::vector2df((i  + 1) * 100, (j + 1) * 100));
			} else if (_2Dmap[i][j] == '1') {
				ecs::system::Create::createWall(_driver, _smgr, irr::core::vector2df((i  + 1) * 100, (j + 1) * 100));
			}
		}
	}
}


mapGen::mapGen(int x, int y, irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
{
	_xmap = x;
	_ymap = y;
	_xgen = 0;
	_ygen = 0;
	_driver = driver;
	_smgr = smgr;
	srand(time(NULL));
	_2Dmap = std::vector<std::vector<char>>(y, std::vector<char>(x));
	gen.push_back(std::pair<int, int> (_xgen, _ygen));
	for (int i = 0; i < y ;i++) {
		for (int j = 0; j < x ;j++) {
			_2Dmap[i][j] = '1';
		}
	}
	generate2D();
	make_unperfect();
	create_spawn();
	createMap();
}
