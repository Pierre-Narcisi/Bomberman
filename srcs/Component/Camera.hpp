/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Entity.hpp"
#include "Game/Game.hpp"
#include "ECS/Component/Component.hpp"
#include "ECS/Entity/Entity.hpp"
#include "Component/Being.hpp"

namespace ecs::component {

	struct Camera {
		irr::scene::ICameraSceneNode	*_camera;
	};

}
