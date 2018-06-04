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
		Controller360(irr::u8 id)
		{
			left.horizonal = 0;
			left.vertical = 0;
			right.horizonal = 0;
			right.vertical = 0;
			leftT = -32767;
			rightT = -32767;
			this->id = id;
		};
		joyStick	left;
		joyStick	right;
		irr::u32	buttons;
		irr::s16	leftT;
		irr::s16	rightT;
		irr::u8		id;
	};
}