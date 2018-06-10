/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include "ECS/Entity/Entity.hpp"
#include "ECS/Component/Component.hpp"
#include "ComponentBeing.hpp"

namespace ecs { namespace component {
	struct Mouse {
		irr::core::position2di	position{0, 0};
		bool 			leftClick = false;
		bool 			rightClick = false;
	};
}}
