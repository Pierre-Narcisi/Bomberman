/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

namespace ecs::component {
	struct UnanimatedObject {
		UnanimatedObject(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &texture, irr::core::vector2df const &pos)
		{
			_node = smgr->addCubeSceneNode(100);
			_node->setMaterialTexture(0, driver->getTexture(texture.c_str()));
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));
		};
		irr::scene::ISceneNode*	_node;
	};
}
