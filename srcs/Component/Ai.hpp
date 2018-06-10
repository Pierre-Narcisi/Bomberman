/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.hpp
*/

#pragma once

namespace ecs { namespace component {

	struct Ai {
		irr::core::vector3df goal;
		int free;
		long double since;
	};
}}
