/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::component {

	struct Controller360 {
		struct joyStick {
			short vertical;
			short horizonal;
		};

		joyStick	left{};
		joyStick	right{};
		irr::u32	buttons{};
		irr::s16	leftT{-32767};
		irr::s16	rightT{-32767};
		irr::u8		id;
	};

}