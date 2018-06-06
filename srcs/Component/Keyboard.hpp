/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>
#include <unordered_map>

namespace ecs::component {
	struct Keyboard {
		struct Action {
			irr::EKEY_CODE	key;
			bool		state;
		};

		std::unordered_map<std::string, Action> actions;
	};
}
