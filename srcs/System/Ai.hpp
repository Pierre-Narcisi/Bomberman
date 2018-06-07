/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Ai.hpp
*/

#pragma once

#include "Component/Map.hpp"
#include <vector>
#include <irrlicht/irrlicht.h>
#include "ECS/Entity/Entity.hpp"
#include "System/Event.hpp"
#include "Component/Basics.hpp"

namespace ecs::system {

	class Ai {
		using map_t = std::vector<std::vector<int>>;
	public:
		static void updateAll(); // create map // boucle sur tout les ai
		static void update(entity::Id ai); // chercher le chemin // poser
		static void line(map_t &map, int y, int x);
		static void zone(map_t &map);
	};

}

