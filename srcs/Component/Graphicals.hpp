/*
** EPITECH PROJECT, 2017
** Client
** File description:
** ParticleComponents.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::component {

	struct Mesh {
		irr::scene::IAnimatedMeshSceneNode	*mesh;
	};

	struct MeshStatic {
		irr::scene::ISceneNode	*mesh;
	};

	struct ParticleAffector {
		irr::scene::IParticleAffector	*PAUp;
		irr::scene::IParticleAffector	*PADown;
		irr::scene::IParticleAffector	*PALeft;
		irr::scene::IParticleAffector	*PARight;
	};

	struct ParticleEmitter {
		irr::scene::IParticleEmitter	*PEUp;
		irr::scene::IParticleEmitter	*PEDown;
		irr::scene::IParticleEmitter	*PELeft;
		irr::scene::IParticleEmitter	*PERight;
	};

	struct ParticleSystem {
		irr::scene::IParticleSystemSceneNode	*PSUp;
		irr::scene::IParticleSystemSceneNode	*PSDown;
		irr::scene::IParticleSystemSceneNode	*PSLeft;
		irr::scene::IParticleSystemSceneNode	*PSRight;
	};

}