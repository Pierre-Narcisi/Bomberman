/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/


#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

#include "Game/Game.hpp"


namespace ecs::component {

	struct Being {
		enum class State {
			STANDING,
			WALKKING,
			RUNNING,
			CROUCH_STAND,
			CROUCH_WALKING
		};

		State					_state;
		irr::scene::IAnimatedMeshSceneNode	*_node;
		irr::scene::EMD2_ANIMATION_TYPE		_lastMov;
		float					_rotation;
		irr::u32				_then;
	};

}
