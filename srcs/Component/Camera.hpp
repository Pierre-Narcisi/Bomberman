/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Entity.hpp"
#include "Game.hpp"
#include "Component.hpp"
#include "Entity.hpp"
#include "Being.hpp"

namespace ecs::component {

	struct Camera {
		irr::scene::ICameraSceneNode	*_camera;
	};

}
