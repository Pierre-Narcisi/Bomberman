/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include "Settings/Inputs.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Component/Stat.hpp"
#include "Component/Being.hpp"
#include "Component/Camera.hpp"

#include "System/Create.hpp"

namespace ecs::system {

	class Update {
	public:
		static void Deplacement();
		static void Bomb()
		{
			entity::Filter<component::Input, component::Being> fl;
			auto &key = component::Manager<component::Input>::get();
			auto &being = component::Manager<component::Being>::get();
			irr::core::vector2di pos;

			for (auto &id : fl.list) {
				if (key[id].attack.state) {
					pos.Y = being[id]._node->getPosition().Z + 50 - std::fmod(static_cast<double>(being[id]._node->getPosition().Z + 50) , 100.0);
					pos.X = being[id]._node->getPosition().X + 50 - std::fmod(static_cast<double>(being[id]._node->getPosition().X + 50) , 100.0);
					ecs::system::Create::createBomb(id, pos);
				}
			}
		}
	};

}
