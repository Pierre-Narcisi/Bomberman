/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Position.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs { namespace component {

	struct Attributes {
		enum class Enum {
			Default
		};

		long double	since;
		int		range;
		Enum		t;
		entity::Id 	player;
		bool 		explode = false;
	};
}}
