/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Actions.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <vector>

#include "ECS/Entity/Entity.hpp"

namespace ecs { namespace component {

	struct Input {
		enum class Mode { None = 0, Keybord, Controller };

		struct Action {
			irr::EKEY_CODE	key;
			bool		state;
		};
		struct JoyStick {
			short vertical;
			short horizonal;
		};

		Mode 			mode{};
		Action			up;
		Action			down;
		Action			left;
		Action			right;
		Action			attack;
		Action			crouch;
		Action			sprint;
		irr::u8			controllerId{};
	};

	struct Mouse {
		irr::core::position2di position;
		bool leftButtonDown{false};
	};

	struct Button {
		enum class Type { None = 0, Quit, Play, Solo, Start, MusicUp, MusicDown, Red, Green, Blue, Yellow};
		Type		type;
		/* normalState // hoverState */
	};

}}

namespace ecs { namespace system {

	class Inputs {
	public:
		static void handle(irr::SEvent const &);
		// static void handle(component::MenuInput &, irr::SEvent const &);
	};

}}