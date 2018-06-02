/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Position.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::component
{
	struct ParticleEmitter
	{
		irr::scene::IParticleEmitter*	PEUp;
		irr::scene::IParticleEmitter*	PEDown;
		irr::scene::IParticleEmitter*	PELeft;
		irr::scene::IParticleEmitter*	PERight;
	};
}
