/*
** EPITECH PROJECT, 2017
** Client
** File description:
** mapGen.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <vector>

#include "System/Create.hpp"
#include "Graphical/EventReceiver.hpp"

namespace indie {

	class mapGen {
	public:
		mapGen(int x, int y);
	private:
		void generate2D();
		void choose_pos();
		int check_wall();
		void make_unperfect();
		void create_spawn();
		void createMap() const;
		void createBorder() const;

	private:
		int					_xgen{};
		int					_ygen{};
		int					_xmap;
		int					_ymap;
		std::vector<std::pair<int, int>>	gen;
		std::vector<std::vector<char>>		_2Dmap;
	};

}