/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

namespace ecs { namespace component {
	struct Stat {
		int	range = 1;
		float	speed = 1;
		int	bombMax = 1;
	};
}}
