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
	struct ParticleAffector
	{
		irr::scene::IParticleAffector*		PAUp;
		irr::scene::IParticleAffector*		PADown;
		irr::scene::IParticleAffector*		PALeft;
		irr::scene::IParticleAffector*		PARight;
	};
}
