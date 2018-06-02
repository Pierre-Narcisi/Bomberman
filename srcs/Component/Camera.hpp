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
#include "Component/Being.hpp"

namespace ecs::component {

	struct Camera {
		Camera(irr::scene::ISceneManager *smgr, ecs::entity::Id id)
		{
			irr::core::vector3df pos = ecs::component::Manager<ecs::component::Being>::get()[id]._node->getPosition();
			_camera = smgr->addCameraSceneNode();
			_camera->setPosition(irr::core::vector3df(pos.X + 0, pos.Y + 500,pos.Z - 500));
			_camera->setTarget(pos);
		};

		irr::scene::ICameraSceneNode	*_camera;
	};

}
