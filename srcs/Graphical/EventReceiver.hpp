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
		evt::Manager &m = evt::Manager::get();

		if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			m["event"]->fire(event);
			_keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		}
		if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT) {
			_joystickState = event.JoystickEvent;
		}
		_event = event;
		return false;
	}

	irr::SEvent getEvent();



private:
	irr::SEvent _event;
	bool				_keyIsDown[irr::KEY_KEY_CODES_COUNT];
	irr::SEvent::SJoystickEvent	_joystickState;
};

#endif //IRRLICHTWRAPPER_EVENTRECEIVER_HPP
