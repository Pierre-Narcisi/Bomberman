/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <ECS/Component/Component.hpp>
#include <Component/UnanimatedObject.hpp>
#include "Game/Game.hpp"
#include "ECS/Entity/Entity.hpp"

namespace ecs::component {
	class Destructors {
	public:
		static void UnanimatedObject(entity::Id id)
		{
			//auto &game = indie::Game::get();
			//auto &obj = component::Manager<component::UnanimatedObject>::get();

			printf("JE DETRUIT LE MUR\n");
			//obj[id]._node->removeAnimators();
			//Zgame.getSmgr()->addToDeletionQueue(obj[id]._node);
		}
	};
}
