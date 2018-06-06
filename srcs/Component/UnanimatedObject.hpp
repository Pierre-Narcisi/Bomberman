/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

#include "Game.hpp"

namespace ecs::component {

	struct UnanimatedObject {
		explicit UnanimatedObject(std::string const &texture, irr::core::vector2df const &pos)
		{
			auto &game = indie::Game::get();

			_node = game.getSmgr()->addCubeSceneNode(100);
			_node->setMaterialTexture(0, game.getDriver()->getTexture(texture.c_str()));
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));
		};
		~UnanimatedObject()
		{
			auto &game = indie::Game::get();
			// game.getSmgr()->addToDeletionQueue(_node);
		}
		irr::scene::ISceneNode	*_node;
	};

}