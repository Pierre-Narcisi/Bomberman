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
#include <iostream>
#include <Manager.hpp>
#include "irrlicht/driverChoice.h"

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver();

	virtual bool OnEvent(const irr::SEvent& event)
	{
		m["event"]->fire(event);
		return false;
	}

private:
	evt::Manager &m = evt::Manager::get();
};

#endif //IRRLICHTWRAPPER_EVENTRECEIVER_HPP
