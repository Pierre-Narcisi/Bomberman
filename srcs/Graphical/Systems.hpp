/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <ECS/Entity/Filter.hpp>
#include "Entity.hpp"
#include "Component.hpp"
#include "Graphical/Components.hpp"
#include "EventReceiver.hpp"

namespace ecs::system::gi {
	class Create {
	public:
		static entity::Id createPlayer(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
		{
			auto id = entity::Manager::get().newEntity();

			component::Manager<component::gi::Being>::get().addComponentForEntity(id, driver, smgr, mesh, texture, pos);
			component::Manager<component::gi::Keyboard>::get().addComponentForEntity(id,
												 irr::EKEY_CODE::KEY_KEY_Z,
												 irr::EKEY_CODE::KEY_KEY_Q,
												 irr::EKEY_CODE::KEY_KEY_S,
												 irr::EKEY_CODE::KEY_KEY_D,
												 irr::EKEY_CODE::KEY_SPACE,
												 irr::EKEY_CODE::KEY_LCONTROL,
												 irr::EKEY_CODE::KEY_LSHIFT);

			return id;
		}
	};

	class Routine {
	public:
		static void Deplacement() {
			entity::Filter<component::gi::Keyboard, component::gi::Being> fl;
			auto &key = component::Manager<component::gi::Keyboard>::get();
			auto &being = component::Manager<component::gi::Being>::get();
			float rot;
			bool moving;

			for (auto id : fl.list) {
				rot = being[id]._rotation;
				moving = key[id].actions["up"].state || key[id].actions["down"].state || key[id].actions["left"].state || key[id].actions["right"].state;

				// Set Rotation
				if (key[id].actions["up"].state)
					rot = 270;
				else if (key[id].actions["down"].state)
					rot = 90;
				if (key[id].actions["left"].state) {
					if (rot == 270)
						rot = 225;
					else if (rot == 90)
						rot = 135;
					else
						rot = 180;
				} else if (key[id].actions["right"].state) {
					if (rot == 270)
						rot = 315;
					else if (rot == 90)
						rot = 45;
					else
						rot = 0;
				}

				being[id]._node->setRotation(irr::core::vector3df(0, rot, 0));

				// Set Animation
				if (moving == 0) {
					if (key[id].actions["crouch"].state && being[id]._lastMov != irr::scene::EMAT_CROUCH_STAND) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
						being[id]._lastMov = irr::scene::EMAT_CROUCH_STAND;
					}
					else if (key[id].actions["sprint"].state && being[id]._lastMov != irr::scene::EMAT_STAND) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
						being[id]._lastMov = irr::scene::EMAT_STAND;
					} else if (key[id].actions["crouch"].state == 0 && key[id].actions["sprint"].state == 0 && being[id]._lastMov != irr::scene::EMAT_STAND) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
						being[id]._lastMov = irr::scene::EMAT_STAND;
					}
				} else {
					if (key[id].actions["crouch"].state && being[id]._lastMov != irr::scene::EMAT_CROUCH_WALK) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_WALK);
						being[id]._lastMov = irr::scene::EMAT_CROUCH_WALK;
					}
					else if (key[id].actions["sprint"].state && being[id]._lastMov != irr::scene::EMAT_RUN) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
						being[id]._lastMov = irr::scene::EMAT_RUN;
					} else if (key[id].actions["crouch"].state == 0 && key[id].actions["sprint"].state == 0 && being[id]._lastMov != irr::scene::EMAT_RUN) {
						being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
						being[id]._lastMov = irr::scene::EMAT_RUN;
					}
					being[id]._rotation = rot;
				}

				// Set Speed
			}
		}
	};

	class Events {
	public:
		static void Manager(irr::SEvent event)
		{
			if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
				entity::Filter<component::gi::Keyboard> fl;
				auto &key = component::Manager<component::gi::Keyboard>::get();

				for (auto &id : fl.list) {
					for (auto &cpn : key[id].actions) {
						if (cpn.second.key == event.KeyInput.Key)
							cpn.second.state = event.KeyInput.PressedDown;
					}
				}
			}
		}
	};
}
