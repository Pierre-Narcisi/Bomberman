/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <ECS/Entity/Filter.hpp>
#include <Settings/Settings.hpp>
#include "Component/Camera.hpp"
#include "Component/UnanimatedObject.hpp"
#include "Component/Being.hpp"
#include "Settings/Inputs.hpp"
#include "ECS/Component/Component.hpp"


namespace ecs::component {
	class Constructors {
	public:
		static void Being(entity::Id id, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
		{
			auto &game = indie::Game::get();
			auto &be = component::Manager<component::Being>::get();

			irr::scene::IAnimatedMesh *_mesh;

			_mesh = game.getSmgr()->getMesh(mesh.c_str());
			if (_mesh == nullptr)
				exit(84);
			be[id]._node = game.getSmgr()->addAnimatedMeshSceneNode(_mesh);
			if (be[id]._node == nullptr)
				exit(84);
			be[id]._node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			be[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
			be[id]._node->setMaterialTexture(0, game.getDriver()->getTexture(texture.c_str()));
			be[id]._node->setPosition(irr::core::vector3df(pos.X, -50, pos.Y));

			be[id]._node->setScale(irr::core::vector3df(30, 30, 30));

			be[id]._state = ecs::component::Being::State::STANDING;
			be[id]._lastMov = irr::scene::EMAT_STAND;
			be[id]._then = game.getDevice()->getTimer()->getTime();
		}

		static void Camera(entity::Id id)
		{
			auto &game = indie::Game::get();
			auto &cam = component::Manager<component::Camera>::get();

			irr::core::vector3df pos = ecs::component::Manager<ecs::component::Being>::get()[id]._node->getPosition();
			cam[id]._camera = game.getSmgr()->addCameraSceneNode();
			cam[id]._camera->setPosition(irr::core::vector3df(pos.X + 0, pos.Y + 500,pos.Z - 500));
			cam[id]._camera->setTarget(pos);
		};

		static void Input(entity::Id ID, irr::u8 joy)
		{
			auto &ctrl = component::Manager<component::Input>::get();

			ctrl[ID].mode = ecs::component::Input::Mode::Controller;
			ctrl[ID].controllerId = joy;
		};

		static void Input(entity::Id ID)
		{
			entity::Filter<component::Input> fl;
			auto &ctrl = component::Manager<component::Input>::get();
			int conf = 1;
			std::string player("player");

			for (auto &id : fl.list) {
				if (ctrl[id].mode == ecs::component::Input::Mode::Keybord)
					conf++;
			}
			ctrl[ID].mode = ecs::component::Input::Mode::Keybord;
			player += std::to_string(conf);
			auto it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
						[player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["up"].to<std::string>();} );
			ctrl[ID].up.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
						[player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["down"].to<std::string>();} );
			ctrl[ID].down.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
					   [player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["left"].to<std::string>();} );
			ctrl[ID].left.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
					   [player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["right"].to<std::string>();} );
			ctrl[ID].right.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
					   [player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["attack"].to<std::string>();} );
			ctrl[ID].attack.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
					   [player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["crouch"].to<std::string>();} );
			ctrl[ID].crouch.key = (*it).second;
			it = std::find_if( ecs::keyRef_g.begin(), ecs::keyRef_g.end(),
					   [player](const std::pair<std::string, int>& element){ return element.first == indie::Game::get().getSettings()["inputs"][player]["sprint"].to<std::string>();} );
			ctrl[ID].sprint.key = (*it).second;
		};

		static void UnanimatedObject(entity::Id id, std::string const &texture, irr::core::vector2df const &pos)
		{
			auto &game = indie::Game::get();
			auto &obj = component::Manager<component::UnanimatedObject>::get();

			obj[id]._node = game.getSmgr()->addCubeSceneNode(100);
			obj[id]._node->setMaterialTexture(0, game.getDriver()->getTexture(texture.c_str()));
			obj[id]._node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			obj[id]._node->setPosition(irr::core::vector3df(pos.X, 0, pos.Y));
		};

		static void Type(entity::Id id, ecs::component::Type::Enum type) {
			auto &obj = component::Manager<component::Type>::get();

			obj[id].t = type;
		};
	};
}

