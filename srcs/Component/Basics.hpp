/*
** EPITECH PROJECT, 2017
** Client
** File description:
** BasicComponents.hpp
*/

#pragma once

namespace ecs { namespace component {

	struct Type {
		enum class Enum {
			Player,
			Monster,
			Wall,
			Bomb,
			Explosion
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

	struct Deletable {
		bool del = false;
	};

}}
