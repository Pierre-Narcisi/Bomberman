/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Map.hpp
*/

#pragma once

#include <vector>

namespace ecs { namespace component {

	struct Map {
		std::vector<std::vector<int>> map;
	};
}}