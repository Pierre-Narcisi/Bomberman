/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "System/Explode.hpp"
#include "System/Event.hpp"
#include "System/Graphical.hpp"

namespace ecs::system {

	void Events::Manager(irr::SEvent const &event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			entity::Filter<component::Keyboard> fl;
			auto &key = component::Manager<component::Keyboard>::get();

			for (auto id : fl.list) {
				for (auto &cpn : key[id].actions) {
					if (cpn.second.key == event.KeyInput.Key)
						cpn.second.state = event.KeyInput.PressedDown;
				}
			}

			if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE
			&& event.KeyInput.PressedDown == false)
				ecs::system::HandleMenu::update();

			ecs::system::Update::Deplacement();
		} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT) {
			entity::Filter<component::Controller360> fl;
			auto &key = component::Manager<component::Controller360>::get();

			for (auto id : fl.list) {
				if (event.JoystickEvent.Joystick == key[id].id) {
					key[id].left.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X];
					key[id].left.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y];
					key[id].right.horizonal = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_R];
					key[id].right.vertical = event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_U];

					if (event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_V] == 32767)
						key[id].rightT = true;
					else
						key[id].rightT = false;
					if (event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Z] == 32767)
						key[id].leftT = true;
					else
						key[id].leftT = false;

					key[id].buttons = event.JoystickEvent.ButtonStates;
				}
			}
			ecs::system::Update::Deplacement();
		}
	}

}
