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

		Keyboard(irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right, irr::EKEY_CODE attack, irr::EKEY_CODE crouch, irr::EKEY_CODE sprint)
		{
			actions = std::unordered_map<std::string, Action> {
				{"up", {up, false} },
				{"left", {left, false} },
				{"down", {down, false} },
				{"right", {right, false} },
				{"attack", {attack, false} },
				{"crouch", {crouch, false} },
				{"sprint", {sprint, false} }
			};
		};

		std::unordered_map<std::string, Action> actions;
	};
}
