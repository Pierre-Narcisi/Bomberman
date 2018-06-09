/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <Component/Camera.hpp>
#include <Component/Controller360.hpp>
#include <Component/Keyboard.hpp>
#include <Component/UnanimatedObject.hpp>
#include "Component/Being.hpp"
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

		static void Input(entity::Id ID, bool controll, irr::u8 joy)
		{
			auto &ctrl = component::Manager<component::Input>::get();

			if (controll) {
				ctrl[ID].mode = ecs::component::Input::Mode::Controller;
				ctrl[ID].controllerId = joy;
			}
		};

		static void Keyboard(entity::Id id, irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right, irr::EKEY_CODE attack, irr::EKEY_CODE crouch, irr::EKEY_CODE sprint)
		{
			auto &key = component::Manager<component::Keyboard>::get();

			key[id].actions = std::unordered_map<std::string, ecs::component::Keyboard::Action> {
				{"up", {up, false} },
				{"left", {left, false} },
				{"down", {down, false} },
				{"right", {right, false} },
				{"attack", {attack, false} },
				{"crouch", {crouch, false} },
				{"sprint", {sprint, false} }
			};
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

