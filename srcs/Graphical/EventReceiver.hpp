/*
** EPITECH PROJECT, 2021
** irrlichtWrapper
** File description:
** Created by seb,
*/

#ifndef IRRLICHTWRAPPER_EVENTRECEIVER_HPP
#define IRRLICHTWRAPPER_EVENTRECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include <irrlicht/IEventReceiver.h>
#include <irrlicht/driverChoice.h>

#include "System/Event.hpp"

namespace indie {

	class MyEventReceiver : public irr::IEventReceiver {
	public:
		MyEventReceiver() = default;

		virtual bool OnEvent(irr::SEvent const &event)
		{
			ecs::system::Events::Manager(event);
			return false;
		}
	};

}

#endif //IRRLICHTWRAPPER_EVENTRECEIVER_HPP
