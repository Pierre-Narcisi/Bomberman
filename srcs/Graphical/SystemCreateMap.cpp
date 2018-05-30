/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemCreate.hpp"

namespace ecs::system {
	irr::scene::IMetaTriangleSelector* Create::createMap(irr::scene::ISceneManager *smgr)
	{
		irr::scene::IMetaTriangleSelector* worldSel = smgr->createMetaTriangleSelector();
		entity::Filter<component::UnanimatedObject> fl;
		auto &map = component::Manager<component::UnanimatedObject>::get();
		irr::scene::ITriangleSelector* sel1;

		for (auto &id: fl.list) {
			sel1 = smgr->createTriangleSelectorFromBoundingBox(map[id]._node);
			worldSel->addTriangleSelector(sel1);
		}
		return (worldSel);
	}
}
