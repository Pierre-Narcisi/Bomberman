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
		Camera(ecs::entity::Id id)
		{
			auto &game = indie::Game::get();

			irr::core::vector3df pos = ecs::component::Manager<ecs::component::Being>::get()[id]._node->getPosition();
			_camera = game.getSmgr()->addCameraSceneNode();
			_camera->setPosition(irr::core::vector3df(pos.X + 0, pos.Y + 500,pos.Z - 500));
			_camera->setTarget(pos);
		};

		irr::scene::ICameraSceneNode	*_camera;
	};

}
