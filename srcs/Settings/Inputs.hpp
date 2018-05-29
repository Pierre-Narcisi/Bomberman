/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Actions.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::system {

	class Inputs {
	public:
		static void handle(irr::EKEY_CODE key);
	};

}