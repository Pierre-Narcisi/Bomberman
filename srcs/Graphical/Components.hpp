/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include </usr/include/irrlicht/irrlicht.h>

namespace ecs::component {
	struct Being {
		Being(irr::scene::ISceneManager *smgr, std::string mesh, std::string texture, irr::core::vector2df pos){
			irr::scene::IAnimatedMesh*		_mesh;
			_mesh = _smgr->getMesh(mesh.c_str());
			if (!_mesh)
				exit(84);
			_node = _smgr->addAnimatedMeshSceneNode(_mesh);
			if (!_node)
				exit(84);
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setMD2Animation(irr::scene::EMAT_STAND);
			_node->setMaterialTexture( 0, driver->getTexture(texture.c_str()));
			_node->setRotation(irr::core::vector3df(0,90,0));
			size = _node->getScale();
			_node->setScale(irr::core::vector3df(size.X * 3, size.Y * 3, size.Z * 3));
			_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));
			_state = State::STANDING;
		};
		enum class State {
			STANDING,
			WALKKING,
			RUNNING,
			CROUCH_STAND,
			CROUCH_WALKING
		};
		State					_state;
		irr::scene::IAnimatedMeshSceneNode*	_node;
	};
}