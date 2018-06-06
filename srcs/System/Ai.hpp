/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.hpp
*/

#pragma once

#include <vector>
#include <irrlicht/irrlicht.h>
#include "ECS/Entity/Entity.hpp"

namespace ecs::component {

	struct Ai {
	
	};

}

namespace ecs::system {

	class Ai {
		using map_t = std::vector<std::vector<int>>;
	public:
		static void updateAll(); // create map // boucle sur tout les ai
		static void update(entity::Id ai, map_t const &map); // chercher le chemin // poser
	};

}

