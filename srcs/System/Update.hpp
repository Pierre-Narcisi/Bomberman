/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include "ECS/Entity/Filter.hpp"

#include "Component/Being.hpp"
#include "Component/Keyboard.hpp"
#include "Component/Controller360.hpp"
#include "Component/Camera.hpp"

#include "System/Create.hpp"

namespace ecs::system {

	class Update {
	public:
		static void Deplacement();
		static void Bomb()
		{
			entity::Filter<component::Keyboard, component::Being> fl;
			entity::Filter<component::Controller360, component::Being> list;
			auto &key = component::Manager<component::Keyboard>::get();
			auto &ctrl = component::Manager<component::Controller360>::get();
			auto &being = component::Manager<component::Being>::get();
			irr::core::vector2di pos;

			for (auto &id : fl.list) {
				if (key[id].actions["attack"].state) {
					pos.Y = being[id]._node->getPosition().Z + 28 - std::fmod(static_cast<double>(being[id]._node->getPosition().Z + 28) , 100.0);
					pos.X = being[id]._node->getPosition().X + 37 - std::fmod(static_cast<double>(being[id]._node->getPosition().X + 37) , 100.0);
					ecs::system::Create::createBomb(pos, component::Manager<component::Stat>::get()[i].range);
					key[id].actions["action"].state = false;
				}
			}

			for (auto &id : list.list) {
				if (ctrl[id].rightT) {
					pos.Y = being[id]._node->getPosition().Z + 28 - std::fmod(static_cast<double>(being[id]._node->getPosition().Z + 28) , 100.0);
					pos.X = being[id]._node->getPosition().X + 37 - std::fmod(static_cast<double>(being[id]._node->getPosition().X + 37) , 100.0);
					ecs::system::Create::createBomb(pos, component::Manager<component::Stat>::get()[i].range);
					ctrl[id].rightT = false;
				}
			}
		}
	};

}
