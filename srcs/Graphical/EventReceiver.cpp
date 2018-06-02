/*
** EPITECH PROJECT, 2017
** Client
** File description:
** EventReceiver.cpp
*/

#include "System/Event.hpp"
#include "EventReceiver.hpp"

namespace indie {

		bool MyEventReceiver::OnEvent(irr::SEvent const &event)
		{
			ecs::system::Events::Manager(event);
			return false;
		}


}