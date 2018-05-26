/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

namespace ecs::component::gi {
	struct Being {
		enum class State {
			STANDING,
			WALKKING,
			RUNNING,
			CROUCH_STAND,
			CROUCH_WALKING
		};

		Being(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
		{
			irr::scene::IAnimatedMesh*		_mesh;

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
			_state = ecs::component::gi::Being::State::STANDING;
			_lastMov = irr::scene::EMAT_STAND;
		}

		State					_state;
		irr::scene::IAnimatedMeshSceneNode*	_node;
		irr::scene::EMD2_ANIMATION_TYPE		_lastMov;
		float 					_rotation;
	};

	struct Keyboard {
		struct action {
			irr::EKEY_CODE	key;
			bool		state;
		};
		Keyboard(irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right, irr::EKEY_CODE attack, irr::EKEY_CODE crouch, irr::EKEY_CODE sprint)
		{
			actions = std::unordered_map<std::string, action> {
				{"up", {up, false} },
				{"left", {left, false} },
				{"down", {down, false} },
				{"right", {right, false} },
				{"attack", {attack, false} },
				{"crouch", {crouch, false} },
				{"sprint", {sprint, false} }
			};
		};
		std::unordered_map<std::string, action> actions;
	};
}