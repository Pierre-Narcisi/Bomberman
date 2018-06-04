/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Inputs.cpp
*/

#include <algorithm>

#include "Inputs.hpp"

namespace ecs::system {

	void Inputs::handle(component::Input &input, irr::SEvent const &event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT
		&& input.mode == component::Input::Mode::Keybord) {
			for (auto &cpn : input.actions) {
				if (cpn.key == event.KeyInput.Key)
					cpn.state = event.KeyInput.PressedDown;
			}
		} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
		&& input.mode == component::Input::Mode::Controler
		&& input.controllerId == event.JoystickEvent.Joystick) {
			std::for_each(input.actions.begin(), input.actions.end(), [&event](auto &a) {
				if (a.type == component::Input::Action::Type::Crouch)
					a.state = (event.JoystickEvent.ButtonStates >> 1 & 1);
				else if (a.type != component::Input::Action::Type::Sprint)
					a.state = (event.JoystickEvent.ButtonStates >> 9 & 1);
			});
		}
	}

	void Inputs::handle(component::MenuInput &input, irr::SEvent const &event)
	{
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
			switch(event.MouseInput.Event) {
				case irr::EMIE_LMOUSE_PRESSED_DOWN:
					/* collide MousePos with buttons */
					break;
				case irr::EMIE_MOUSE_MOVED:
					input.mouse.position.X = event.MouseInput.X;
					input.mouse.position.Y = event.MouseInput.Y;
					break;
				default:
					break;
			}
		} else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
		&& event.JoystickEvent.Joystick == 0) {
			/* check joystick up down left right accept */
		}
	}

}