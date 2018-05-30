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
	struct Being {
		enum class State {
			STANDING,
			WALKKING,
			RUNNING,
			CROUCH_STAND,
			CROUCH_WALKING
		};

		Being(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr,
		      std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos) {
			irr::scene::IAnimatedMesh *_mesh;
			_device = device;

			_mesh = smgr->getMesh(mesh.c_str());
			if (!_mesh)
				exit(84);
			_node = smgr->addAnimatedMeshSceneNode(_mesh);
			if (!_node)
				exit(84);
			_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_node->setMD2Animation(irr::scene::EMAT_STAND);
			_node->setMaterialTexture(0, driver->getTexture(texture.c_str()));
			_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));

			_node->setScale(irr::core::vector3df(1.5, 1.5, 1.5));

			_state = ecs::component::Being::State::STANDING;
			_lastMov = irr::scene::EMAT_STAND;
			_then = device->getTimer()->getTime();
		}

		irr::IrrlichtDevice *_device;
		State _state;
		irr::scene::IAnimatedMeshSceneNode *_node;
		irr::scene::EMD2_ANIMATION_TYPE _lastMov;
		float _rotation;
		irr::u32 _then;
	};
}
