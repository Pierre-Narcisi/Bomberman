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

namespace ecs::component {

	struct Input {
		enum class Mode { None = 0, Keybord, Controler };

		struct Action {
			enum class Type { Up, Down, Left, Right, Attack, Crouch, Sprint };
			Type		type;
			irr::EKEY_CODE	key;
			bool		state;
		};
		struct JoyStick {
			short vertical;
			short horizonal;
		};

		Mode 			mode{};
		std::vector<Action>	actions;
		JoyStick		left{0, 0};
		JoyStick		right{0, 0};
		irr::u32		buttons{};
		irr::s16		leftT{-32767};
		irr::s16		rightT{-32767};
		irr::u8			controllerId{};
	};

	struct Mouse {
		irr::core::position2di position;
		bool leftButtonDown{false};
	};

	struct Button {
		enum class Type { None = 0, Quit, Play, Solo};
		Type		type;
		/* normalState // hoverState */
	};

}

namespace ecs::system {

	class Inputs {
	public:
		static void handle(component::Input &, irr::SEvent const &);
		// static void handle(component::MenuInput &, irr::SEvent const &);
	};

}
