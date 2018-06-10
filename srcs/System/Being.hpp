/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Being.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Component/Being.hpp"

namespace ecs { namespace system {

	class Being {
	public:
		static void updateState(component::Being &, irr::scene::EMD2_ANIMATION_TYPE);
	};

}}