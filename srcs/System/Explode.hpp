/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include <Constructors/Destructors.hpp>
#include "Game/Game.hpp"
#include "ECS/Entity/Entity.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Component/Basics.hpp"
#include "Component/Graphicals.hpp"
#include "Component/AttributeBomb.hpp"

#include "System/Create.hpp"

namespace ecs::system {

	class Explode {
	public:
		static void update()
		{
			auto &game = indie::Game::get();
			entity::Filter<component::Type> fl;
			entity::Filter<component::UnanimatedObject, component::Deletable> walls;

			auto &typeManager = component::Manager<component::Type>::get();
			auto &attributesManager = component::Manager<component::Attributes>::get();
			auto &positionManager = component::Manager<component::Position>::get();
			auto &being = component::Manager<component::UnanimatedObject>::get();

			auto &particleSystemManager = component::Manager<component::ParticleSystem>::get();

			int dist = 1 * 100 + 100;

			for (auto &id : fl.list) {
				if (typeManager[id].t == component::Type::Enum::Wall
				&& (long double) time(NULL) >= attributesManager[id].since) {
					game.getSmgr()->addToDeletionQueue(being[id]._node);

					auto pos = positionManager[id];
					for (auto &ID : walls.list) {
						if (positionManager[ID].x == pos.x) {
							if (positionManager[ID].y > (pos.y - dist) && positionManager[ID].y < (pos.y + dist)) {
								ecs::component::Destructors::UnanimatedObject(ID);
								break;
							}
						}
						if (positionManager[ID].y == pos.y) {
							if (positionManager[ID].x > (pos.x - dist) && positionManager[ID].x < (pos.x + dist)) {
								ecs::component::Destructors::UnanimatedObject(ID);
								break;
							}
						}
					}

					Create::createExplosion(pos, 5);
					component::Manager<component::Deletable>::get()[id].del = true;
				}
				if (typeManager[id].t == component::Type::Enum::Explosion
				&& (long double) time(NULL) >= attributesManager[id].since) {
					particleSystemManager[id].PSUp->removeAllAffectors();
					particleSystemManager[id].PSDown->removeAllAffectors();
					particleSystemManager[id].PSLeft->removeAllAffectors();
					particleSystemManager[id].PSRight->removeAllAffectors();

					game.getSmgr()->addToDeletionQueue(particleSystemManager[id].PSUp);
					game.getSmgr()->addToDeletionQueue(particleSystemManager[id].PSDown);
					game.getSmgr()->addToDeletionQueue(particleSystemManager[id].PSLeft);
					game.getSmgr()->addToDeletionQueue(particleSystemManager[id].PSRight);

					component::Manager<component::Deletable>::get()[id].del = true;
				}
			}
		}
	};
}
