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
		static irr::scene::IMetaTriangleSelector* createMap(irr::scene::ISceneManager *smgr);
		static entity::Id	createWall(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector2df pos);
		static entity::Id	createDeletableWall(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector2df pos);
		static entity::Id	createPlayer(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos);
		static entity::Id	createBomb(irr::scene::ISceneManager *scene_manager, irr::core::vector2di pos);
		static void		createExplosion(irr::scene::ISceneManager *scene_manager, irr::video::IVideoDriver *driver, component::Position pos, int range);
	};

}
