/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "ECS/Entity/Filter.hpp"

#include "Component/Basics.hpp"
#include "Component/UnanimatedObject.hpp"
#include "Component/Being.hpp"
#include "Component/Controller360.hpp"
#include "Component/Keyboard.hpp"
#include "Component/Camera.hpp"

namespace ecs::system {

	class Create {
	public:
		static irr::scene::IMetaTriangleSelector* createCollision();
		static entity::Id	createWall(irr::core::vector2df pos);
		static entity::Id	createDeletableWall(irr::core::vector2df pos);
		static entity::Id	createPlayer(std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos);
		static entity::Id	createBomb(entity::Id id, irr::core::vector2di pos);
		static void		createExplosion(entity::Id id, component::Position pos);
		static entity::Id	createMap(std::vector<std::vector<int>>);
	};

}
