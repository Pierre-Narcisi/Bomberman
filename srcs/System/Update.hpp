/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <math.h>

#include "Settings/Inputs.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Component/Stat.hpp"
#include "Component/Being.hpp"
#include "Component/Camera.hpp"
#include "System/Graphical.hpp"

#include "System/Create.hpp"

namespace ecs { namespace system {

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
					pos.Y = being[id]._node->getPosition().Z + 50 - ::fmod(static_cast<double>(being[id]._node->getPosition().Z + 50) , 100.0);
					pos.X = being[id]._node->getPosition().X + 50 - ::fmod(static_cast<double>(being[id]._node->getPosition().X + 50) , 100.0);
					ecs::system::Create::createBomb(id, pos);
				}
			}
		}
	};

	class HandleMenu {
	public:
		static void update()
		{
			static bool _switch = false;

			_switch = !_switch;
			if (_switch == true) {
			
			
				ecs::system::Scene::loadMenuInGame();
				/* create menu */
			} else {
				ecs::system::Scene::unloadMenuInGame();
				/* delete menu */
			}
		}
	};

}}