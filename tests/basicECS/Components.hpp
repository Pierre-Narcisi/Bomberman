/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Component.hpp
*/

#pragma once

namespace ecs::component {

	struct Type {
		enum class Enum {
			Player, Monster
		};
		Enum t;
	};

	struct Position {
		int x{};
		int y{};	
	};

	struct Speed {
		int x{};
		int y{};
	};

}
