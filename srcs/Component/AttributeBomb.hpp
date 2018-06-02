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
	struct Attributes
	{
		long double	since;
		enum class Enum
		{
			Default
		};
		Enum t;
	};
}
