/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "ECS/Entity/Filter.hpp"
#include "System/Update.hpp"

namespace ecs { namespace system {

	class Events {
	public:
		static void Manager(irr::SEvent const &event);
	};
}}