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
#include "Component/Graphicals.hpp"
#include "Component/Ai.hpp"
#include "System/Being.hpp"

namespace ecs { namespace system {

	class Ai {
		using map_t = std::vector<std::vector<int>>;
	public:
		static void updateAll(); // create map // boucle sur tout les ai
		static void update(entity::Id ai); // chercher le chemin // poser
		static irr::core::vector3df findSafe(map_t map, irr::core::vector3df pos);
		static irr::core::vector3df findSpot(map_t map, irr::core::vector3df pos);
		static int isViable(map_t map, int y, int x, int size);
		static void moveTo(irr::core::vector3df to, irr::core::vector3df pos, int &free, entity::Id id);
		static void setGoal(irr::core::vector3df &goal, int &free, map_t map, irr::core::vector3df pos, entity::Id id);
		static void bomb(int id, irr::core::vector3df pos);
		static void deplacement(int y, int x, int moving, entity::Id id);
		static int getPos(float pos);
		static void line(map_t &map, int y, int x);
		static void zone(map_t &map);
	};

}}