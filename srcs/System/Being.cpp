/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Being.cpp
*/

#include "System/Being.hpp"

namespace ecs::system {

	void Being::updateState(component::Being &being, irr::scene::EMD2_ANIMATION_TYPE state)
	{
		being._node->setMD2Animation(state);
		being._lastMov = state;
	}

}