/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Map.hpp
*/

#include <vector>

namespace ecs::component {

	struct Map {
		std::vector<std::vector<int>> map;
	};
}