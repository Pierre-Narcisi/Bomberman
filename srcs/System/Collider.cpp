/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Collider.cpp
*/

#include "Game/Game.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Settings/Inputs.hpp"

#include "System/Collider.hpp"

namespace ecs::system {

	void Collider::update()
	{
		auto const &mouse = indie::Game::get().getMouse();
		entity::Filter<component::Button> fl;

		for (auto &e : fl.list) {
			if (1/* verif collide */) {
				/* apply button */
			}
		}
	}

}