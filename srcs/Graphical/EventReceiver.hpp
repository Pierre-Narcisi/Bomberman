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
#include "SystemEvent.hpp"

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver();

	virtual bool OnEvent(const irr::SEvent& event)
	{
		ecs::system::Events::Manager(event);
		return false;
	}
};

#endif //IRRLICHTWRAPPER_EVENTRECEIVER_HPP
