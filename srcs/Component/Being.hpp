/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/


#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

#include "Game/Game.hpp"


namespace ecs::component {

	struct Being {
		enum class State {
			STANDING,
			WALKKING,
			RUNNING,
			CROUCH_STAND,
			CROUCH_WALKING
		};

		Being(std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos) {
			auto &game = indie::Game::get();
			irr::scene::IAnimatedMesh *_mesh;

			_mesh = game.getSmgr()->getMesh(mesh.c_str());
			if (_mesh == nullptr)
				exit(84);
			_node = game.getSmgr()->addAnimatedMeshSceneNode(_mesh);
			if (_node == nullptr)
				exit(84);
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setMD2Animation(irr::scene::EMAT_STAND);
			_node->setMaterialTexture(0, game.getDriver()->getTexture(texture.c_str()));
			_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));

			_node->setScale(irr::core::vector3df(3, 3, 3));

			_state = State::STANDING;
			_lastMov = irr::scene::EMAT_STAND;
			_then = game.getDevice()->getTimer()->getTime();
		}

		State					_state;
		irr::scene::IAnimatedMeshSceneNode	*_node;
		irr::scene::EMD2_ANIMATION_TYPE		_lastMov;
		float					_rotation;
		irr::u32				_then;
	};

}
