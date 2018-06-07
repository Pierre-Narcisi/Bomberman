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

	struct UnanimatedObject {
		irr::scene::ISceneNode	*_node;
	};

}