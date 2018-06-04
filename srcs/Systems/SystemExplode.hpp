/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include "irrlicht/irrlicht.h"
#include "Components.hpp"
#include "ECS/Entity/Filter.hpp"
#include "Component/UnanimatedObject.hpp"
#include "Component/AttributeBomb.hpp"
#include "Component/Graphicals.hpp"
#include "System/Create.hpp"

namespace ecs::system {

	class Explode {
	public:
		static void update(irr::scene::ISceneManager *scene_manager, irr::video::IVideoDriver *driver)
		{
			entity::Filter<component::Type> fl;
			entity::Filter<component::UnanimatedObject, component::Deletable> walls;

			auto &typeManager = component::Manager<component::Type>::get();
			auto &attributesManager = component::Manager<component::Attributes>::get();
			auto &positionManager = component::Manager<component::Position>::get();
			auto &meshManager = component::Manager<component::Mesh>::get();
			auto &wall = component::Manager<component::Deletable>::get();
			auto &being = component::Manager<component::UnanimatedObject>::get();

			int dist = 1 * 100 + 100;

			auto &particleSystemManager = component::Manager<component::ParticleSystem>::get();

			for (auto &id : fl.list) {
				if (typeManager[id].t == component::Type::Enum::Bomb) {
					if ((long double) time(NULL) >= attributesManager[id].since){
						scene_manager->addToDeletionQueue(meshManager[id].mesh);
						Create::createExplosion(positionManager[id], 5);
						component::Manager<component::Deletable>::get()[id].del = true;
						auto pos = positionManager[id];

						for (auto &ID : walls.list) {
							if (positionManager[ID].x == pos.x) {
								if (positionManager[ID].y > (pos.y - dist) && positionManager[ID].y < (pos.y + dist))
									being[ID]._node->setPosition(irr::core::vector3df(10,10,10));
							}
							if (positionManager[ID].y == pos.y) {
								if (positionManager[ID].x > (pos.x - dist) && positionManager[ID].x < (pos.x + dist))
									being[ID]._node->setPosition(irr::core::vector3df(10,10,10));
							}
						}
					}
				}
				if (typeManager[id].t == component::Type::Enum::Explosion)
				{
					if ((long double) time(NULL) >= attributesManager[id].since)
					{
						particleSystemManager[id].PSUp->removeAllAffectors();
						particleSystemManager[id].PSDown->removeAllAffectors();
						particleSystemManager[id].PSLeft->removeAllAffectors();
						particleSystemManager[id].PSRight->removeAllAffectors();

						scene_manager->addToDeletionQueue(particleSystemManager[id].PSUp);
						scene_manager->addToDeletionQueue(particleSystemManager[id].PSDown);
						scene_manager->addToDeletionQueue(particleSystemManager[id].PSLeft);
						scene_manager->addToDeletionQueue(particleSystemManager[id].PSRight);

						component::Manager<component::Deletable>::get()[id].del = true;
					}
				}
			}
		}
	};
}
