/*
** EPITECH PROJECT, 2021
** irrlichtWrapper
** File description:
** Created by seb,
*/
#include "EventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
{
	for (irr::u32 i=0; i < irr::KEY_KEY_CODES_COUNT; ++i)
		_keyIsDown[i] = false;
}

irr::SEvent MyEventReceiver::getEvent() {
	return _event;
}