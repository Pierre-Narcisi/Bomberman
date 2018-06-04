/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Position.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::component
{
	struct Attributes {
		enum class Enum {
			Default
		};

		long double	since;
		Enum		t;
	};
}
