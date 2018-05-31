/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <ECS/Entity/Entity.hpp>
#include <ECS/Component/Component.hpp>
#include "ComponentBeing.hpp"

namespace ecs::component {
	struct Mouse {
		Mouse()
		{
			position.X = 0;
			position.Y = 0;
			leftClick = false;
			rightClick = false;
		};
		irr::core::position2di	position;
		bool 			leftClick;
		bool 			rightClick;
	};
}
