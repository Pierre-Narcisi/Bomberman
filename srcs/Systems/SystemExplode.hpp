/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include "basicECS/Components.hpp"
#include "Component/ParticleEmitter.hpp"
#include "Entity.hpp"
#include "Filter.hpp"

#include "AttributeBomb.hpp"
#include "Mesh.hpp"
#include "ParticleSystem.hpp"
#include "ParticleAffector.hpp"
#include "SystemCreate.hpp"

namespace ecs::system {

	class Explode {
	public:
		static void update(irr::scene::ISceneManager *scene_manager, irr::video::IVideoDriver *driver)
		{
			entity::Filter<component::Type> fl;

			auto &typeManager = component::Manager<component::Type>::get();
			auto &attributesManager = component::Manager<component::Attributes>::get();
			auto &positionManager = component::Manager<component::Position>::get();
			auto &meshManager = component::Manager<component::Mesh>::get();

			auto &particleSystemManager = component::Manager<component::ParticleSystem>::get();
			auto &particleAffectorManager = component::Manager<component::ParticleAffector>::get();

			for (auto &id : fl.list) {
				if (typeManager[id].t == component::Type::Enum::Bomb) {
					if ((long double) time(NULL) >= attributesManager[id].since){
						scene_manager->addToDeletionQueue(meshManager[id].mesh);
						Create::createExplosion(scene_manager, driver, positionManager[id], 5);
						component::Manager<component::Deletable>::get()[id].del = true;
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
