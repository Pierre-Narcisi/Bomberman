/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Inputs.cpp
*/

#include <algorithm>
#include "ECS/Entity/Filter.hpp"
#include "System/Update.hpp"

#include "Inputs.hpp"

namespace ecs::system {

	void Inputs::handle(irr::SEvent const &event)
	{
		entity::Filter<component::Input> fl;
		auto &input = component::Manager<component::Input>::get();

		for (auto &id : fl.list) {

			if (event.EventType == irr::EET_KEY_INPUT_EVENT
			&& input[id].mode == component::Input::Mode::Keybord) {
				if (input[id].up.key == event.KeyInput.Key)
					input[id].up.state = event.KeyInput.PressedDown;
				if (input[id].down.key == event.KeyInput.Key)
					input[id].down.state = event.KeyInput.PressedDown;
				if (input[id].left.key == event.KeyInput.Key)
					input[id].left.state = event.KeyInput.PressedDown;
				if (input[id].right.key == event.KeyInput.Key)
					input[id].right.state = event.KeyInput.PressedDown;
				if (input[id].attack.key == event.KeyInput.Key)
					input[id].attack.state = event.KeyInput.PressedDown;
				if (input[id].crouch.key == event.KeyInput.Key)
					input[id].crouch.state = event.KeyInput.PressedDown;
				if (input[id].sprint.key == event.KeyInput.Key)
					input[id].sprint.state = event.KeyInput.PressedDown;
			} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
			&& input[id].mode == component::Input::Mode::Controller
			&& input[id].controllerId == event.JoystickEvent.Joystick) {
				const irr::f32 DEAD_ZONE = 0.2f;
				irr::f32 rotHorizontal =
					event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
				if(fabs(rotHorizontal) < DEAD_ZONE)
					rotHorizontal = 0.f;
				irr::f32 rotVertical =
					event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
				if(fabs(rotVertical) < DEAD_ZONE)
					rotVertical = 0.f;

				input[id].crouch.state = (event.JoystickEvent.ButtonStates >> 1 & 1);
				input[id].sprint.state = (event.JoystickEvent.ButtonStates >> 9 & 1);
				input[id].up.state = (rotVertical >= 0.2f);
				input[id].down.state = (rotVertical <= -0.2f);
				input[id].right.state = (rotHorizontal >= 0.2f);
				input[id].left.state = (rotHorizontal <= -0.2f);
				input[id].attack.state = (event.JoystickEvent.Axis[irr::SEvent::SJoystickEvent::AXIS_V] == 32767);
			}
		}
		ecs::system::Update::Deplacement();
	}

	// void Inputs::handle(component::MenuInput &input, irr::SEvent const &event)
	// {
		// if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		// 	switch(event.MouseInput.Event) {
		// 		case irr::EMIE_LMOUSE_PRESSED_DOWN:
		// 			/* collide MousePos with buttons */
		// 			break;
		// 		case irr::EMIE_MOUSE_MOVED:
		// 			input.mouse.position.X = event.MouseInput.X;
		// 			input.mouse.position.Y = event.MouseInput.Y;
		// 			break;
		// 		default:
		// 			break;
		// 	}
		// } else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
		// && event.JoystickEvent.Joystick == 0) {
		// 	/* check joystick up down left right accept */
		// }
	// }

}
