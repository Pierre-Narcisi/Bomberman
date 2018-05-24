/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include "Entity.hpp"
#include "Component.hpp"
#include "Graphical/Components.hpp"

namespace ecs::system {
	namespace gi {
		class Create {
		public:
			static entity::Id createPlayer(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string mesh, std::string texture, irr::core::vector2df pos)
			{
				auto id = entity::Manager::get().newEntity();
				irr::scene::IAnimatedMesh*		_mesh;
				irr::scene::IAnimatedMeshSceneNode*	_node;

				_mesh = smgr->getMesh(mesh.c_str());
				if (!_mesh)
					exit(84);
				_node = smgr->addAnimatedMeshSceneNode(_mesh);
				if (!_node)
					exit(84);
				_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				_node->setMD2Animation(irr::scene::EMAT_STAND);
				_node->setMaterialTexture( 0, driver->getTexture(texture.c_str()));
				_node->setRotation(irr::core::vector3df(0,90,0));
				_node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));

				irr::scene::ICameraSceneNode* _camera;
				_camera = smgr->addCameraSceneNode();
				_camera->setPosition(irr::core::vector3df(0,50,-50));
				_camera->setTarget(_node->getPosition());

				component::Manager<component::gi::Being>::get().addComponentForEntity(id, ecs::component::gi::Being::State::STANDING, _node);
				return id;
			}
		};
	}
}
