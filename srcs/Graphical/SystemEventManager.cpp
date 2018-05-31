/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemEvent.hpp"

namespace ecs::system {
	void Events::Manager(irr::SEvent event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			entity::Filter<component::Keyboard> fl;
			auto &key = component::Manager<component::Keyboard>::get();

			for (auto &id : fl.list) {
				for (auto &cpn : key[id].actions) {
					if (cpn.second.key == event.KeyInput.Key)
						cpn.second.state = event.KeyInput.PressedDown;
				}
			}
			ecs::system::Update::Deplacement();
		} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT) {
			entity::Filter<component::Controller360> fl;
			auto &key = component::Manager<component::Controller360>::get();

			for (auto &id : fl.list) {
				if (event.JoystickEvent.Joystick == key[id].id) {
					key[id].left.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X];
					key[id].left.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y];
					key[id].right.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_R];
					key[id].right.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_U];

					key[id].buttons = event.JoystickEvent.ButtonStates;
				}
			}
			ecs::system::Update::Deplacement();
		} else if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
			entity::Filter<component::Mouse> fl;
			auto &mouse = component::Manager<component::Mouse>::get();

			for (auto &id: fl.list) {
				switch(event.MouseInput.Event)
				{
					case irr::EMIE_LMOUSE_PRESSED_DOWN:
						mouse[id].rightClick = true;
						break;

					case irr::EMIE_LMOUSE_LEFT_UP:
						mouse[id].leftClick = false;
						break;

					case irr::EMIE_MOUSE_MOVED:
						mouse[id].position.X = event.MouseInput.X;
						mouse[id].position.Y = event.MouseInput.Y;
						break;

					default:
						break;
				}
			}
		}
	}
}