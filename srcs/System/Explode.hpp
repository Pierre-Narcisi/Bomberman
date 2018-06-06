/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include <Constructors/Destructors.hpp>
#include <Component/Stat.hpp>
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
			entity::Filter<component::Type, component::Attributes, component::Position, component::Mesh> fl;
			entity::Filter<component::Type, component::Position, component::Attributes, component::Deletable, component::ParticleSystem> exp;
			entity::Filter<component::UnanimatedObject, component::Deletable> walls;

			auto &typeManager = component::Manager<component::Type>::get();
			auto &attributesManager = component::Manager<component::Attributes>::get();
			auto &positionManager = component::Manager<component::Position>::get();
			auto &being = component::Manager<component::UnanimatedObject>::get();
			auto &bomb = component::Manager<component::Mesh>::get();
			auto &dlt = component::Manager<component::Deletable>::get();
			auto &attribute = component::Manager<component::Attributes>::get();

			auto &particleSystemManager = component::Manager<component::ParticleSystem>::get();

			int dist = 1 * 100 + 100;

			for (auto &id : fl.list) {
				if (typeManager[id].t == component::Type::Enum::Bomb
				    && (long double) time(NULL) >= attributesManager[id].since) {
					auto pos = positionManager[id];
					game.getSmgr()->addToDeletionQueue(bomb[id].mesh);
					for (auto &ID : walls.list) {
						if (being[ID]._node->getPosition().X == pos.x) {
							if (being[ID]._node->getPosition().Z > (pos.y - dist) &&
							    being[ID]._node->getPosition().Z < (pos.y + dist)) {
								ecs::component::Destructors::UnanimatedObject(ID);
								dlt[ID].del = true;
							}
						} else if (being[ID]._node->getPosition().Z == pos.y) {
							if (being[ID]._node->getPosition().X > (pos.x - dist) &&
							    being[ID]._node->getPosition().X < (pos.x + dist)) {
								ecs::component::Destructors::UnanimatedObject(ID);
								dlt[ID].del = true;
							}
						}
					}
					component::Manager<component::Stat>::get()[attribute[id].player].bombMax += 1;
					Create::createExplosion(id, pos);
					component::Manager<component::Deletable>::get()[id].del = true;
				}
			}
			for (auto &id : exp.list) {
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
