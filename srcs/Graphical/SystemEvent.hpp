/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <ECS/Entity/Filter.hpp>
#include "ComponentKeyboard.hpp"
#include "ComponentController360.hpp"
#include "SystemUpdate.hpp"

namespace ecs::system {
	class Events {
	public:
		static void Manager(irr::SEvent event);
	};
}