/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include "ECS/Component/Component.hpp"
#include "Component/UnanimatedObject.hpp"
#include "Game/Game.hpp"
#include "ECS/Entity/Entity.hpp"

namespace ecs { namespace component {
	class Destructors {
	public:
		static void UnanimatedObject(entity::Id id)
		{
			//auto &game = indie::Game::get();
			auto &obj = component::Manager<component::UnanimatedObject>::get();

			obj[id]._node->setPosition(irr::core::vector3df(1000, 1000, 1000));
			//obj[id]._node->removeAnimators();
			//game.getSmgr()->addToDeletionQueue(obj[id]._node);
		}
	};
}}