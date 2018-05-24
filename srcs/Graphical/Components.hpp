/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include </usr/include/irrlicht/irrlicht.h>
#include <string>

namespace ecs::component {
	namespace gi {
		struct Being {
			enum class State {
				STANDING,
				WALKKING,
				RUNNING,
				CROUCH_STAND,
				CROUCH_WALKING
			};
			State					_state;
			irr::scene::IAnimatedMeshSceneNode*	_node;
		};
	}
}