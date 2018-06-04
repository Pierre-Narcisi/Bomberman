/*
** EPITECH PROJECT, 2017
** Client
** File description:
** EventReceiver.cpp
*/

#include "System/Event.hpp"
#include "EventReceiver.hpp"
#include "Settings/Inputs.hpp"
#include "System/CreateButton.hpp"

#include "Game/Game.hpp"

namespace indie {

		bool MyEventReceiver::OnEvent(irr::SEvent const &event)
		{
			/* boucle sur les inputs */
			ecs::system::Events::Manager(event);
			/* boucle sur les Mouse */
			auto &mouse = ecs::component::Manager<ecs::component::Mouse>::get()[Game::get().getMouse()];
			if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
				switch(event.MouseInput.Event) {
					case irr::EMIE_LMOUSE_LEFT_UP:
						/* collide MousePos with buttons */
						break;
					case irr::EMIE_MOUSE_MOVED:
						mouse.position.X = event.MouseInput.X;
						mouse.position.Y = event.MouseInput.Y;
						break;
					default:
						break;
			}
			return false;
		}


}