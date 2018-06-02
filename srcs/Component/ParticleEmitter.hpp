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
	struct ParticleSystem
	{
		irr::scene::IParticleSystemSceneNode*	PSUp;
		irr::scene::IParticleSystemSceneNode*	PSDown;
		irr::scene::IParticleSystemSceneNode*	PSLeft;
		irr::scene::IParticleSystemSceneNode*	PSRight;
	};
}
