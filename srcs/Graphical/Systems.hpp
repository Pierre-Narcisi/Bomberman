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
		static entity::Id createPlayer(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
		{
			auto	id = entity::Manager::get().newEntity();
			bool 	_controller = false;
			irr::core::array<irr::SJoystickInfo> joystickInfo;
			device->activateJoysticks(joystickInfo);

			for (irr::u32 i = 0; i < joystickInfo.size(); i++)
				if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0)
					_controller = true;

			component::Manager<component::gi::Being>::get().addComponentForEntity(id, driver, smgr, mesh, texture, pos);

			if (_controller)
				component::Manager<component::gi::Controller360>::get().addComponentForEntity(id);
			else
				component::Manager<component::gi::Keyboard>::get().addComponentForEntity(id,
												 irr::EKEY_CODE::KEY_KEY_Z,
												 irr::EKEY_CODE::KEY_KEY_Q,
												 irr::EKEY_CODE::KEY_KEY_S,
												 irr::EKEY_CODE::KEY_KEY_D,
												 irr::EKEY_CODE::KEY_SPACE,
												 irr::EKEY_CODE::KEY_LCONTROL,
												 irr::EKEY_CODE::KEY_LSHIFT);

			component::Manager<component::gi::Camera>::get().addComponentForEntity(id, smgr, id);

			return id;
		}
	};

	class Routine {
	public:
		static void Deplacement() {
			entity::Filter<component::gi::Keyboard, component::gi::Being> fl;
			entity::Filter<component::gi::Controller360, component::gi::Being> list;

			auto &key = component::Manager<component::gi::Keyboard>::get();
			auto &being = component::Manager<component::gi::Being>::get();
			auto &control = component::Manager<component::gi::Controller360>::get();
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

			for (auto &id : list.list) {
				const irr::f32 DEAD_ZONE = 0.2f;

				irr::f32 moveHorizontal =
					(irr::f32)control[id].left.horizonal / 32767.f;
				if(fabs(moveHorizontal) < DEAD_ZONE)
					moveHorizontal = 0.f;

				irr::f32 moveVertical =
					(irr::f32)control[id].left.vertical / -32767.f;
				if(fabs(moveVertical) < DEAD_ZONE)
					moveVertical = 0.f;

				irr::f32 rotHorizontal =
					(irr::f32)control[id].right.horizonal / 32767.f;
				if(fabs(rotHorizontal) < DEAD_ZONE)
					rotHorizontal = 0.f;

				irr::f32 rotVertical =
					(irr::f32)control[id].right.vertical / -32767.f;
				if(fabs(rotVertical) < DEAD_ZONE)
					rotVertical = 0.f;

				if (rotHorizontal >= 0) {
					if (rotVertical >= 0)
						rot = 360 - static_cast<float>(atan(rotVertical/rotHorizontal) * (180 /M_PI));
					else
						rot = -static_cast<float>(atan((rotVertical)/rotHorizontal) * (180 /M_PI));
				} else {
					if (rotVertical >= 0)
						rot = 180 - static_cast<float>(atan(rotVertical/(rotHorizontal)) * (180 /M_PI));
					else
						rot = 180 - static_cast<float>(atan((rotVertical)/(rotHorizontal)) * (180 /M_PI));
				}

				if (rotHorizontal == 0 && rotVertical == 0)
					rot = being[id]._rotation;
				else
					being[id]._rotation = rot;

				being[id]._node->setRotation(irr::core::vector3df(0, rot, 0));

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
			} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT) {
				entity::Filter<component::gi::Controller360> fl;
				auto &key = component::Manager<component::gi::Controller360>::get();

				for (auto &id : fl.list) {
					key[id].left.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X];
					key[id].left.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y];
					key[id].right.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_R];
					key[id].right.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_U];

					key[id].buttons = event.JoystickEvent.ButtonStates;
				}
			}
		}
	};
}
