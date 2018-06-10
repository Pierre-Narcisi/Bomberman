/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include "ECS/Component/Component.hpp"
#include "Component/UnanimatedObject.hpp"
#include "System/Create.hpp"
#include "Game/Game.hpp"
#include "ECS/Entity/Entity.hpp"
#include <random>

namespace ecs { namespace component {
	class Destructors {
	public:
		static void UnanimatedObject(entity::Id id)
		{
			//auto &game = indie::Game::get();
			auto &obj = component::Manager<component::UnanimatedObject>::get();
			std::uniform_int_distribution<int> distribution(0, 100);
			std::random_device rd;
			std::mt19937 engine(rd());
			ecs::component::Position pos;

			pos.x = obj[id]._node->getPosition().X;
			pos.y = obj[id]._node->getPosition().Z;

			int ran = distribution(engine);
			if (ran > 50)
				ecs::system::Create::createBonus(pos);

			obj[id]._node->setPosition(irr::core::vector3df(1000, 1000, 1000));
			//obj[id]._node->setVisible(0);
			//obj[id]._node->removeAnimators();
			//game.getSmgr()->addToDeletionQueue(obj[id]._node);

		}
	};
}}
