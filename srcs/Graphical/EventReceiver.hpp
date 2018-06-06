/*
** EPITECH PROJECT, 2021
** irrlichtWrapper
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <irrlicht/IEventReceiver.h>
#include <irrlicht/driverChoice.h>

namespace indie {

	class MyEventReceiver : public irr::IEventReceiver {
	public:
		MyEventReceiver() = default;

		virtual bool OnEvent(irr::SEvent const &event);
	};

}