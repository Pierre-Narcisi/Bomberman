/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemCreate.hpp"

namespace ecs::system {
	entity::Id Create::createWall(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id, driver, smgr, "../../assets/cobblestone.jpg", pos);
		component::Manager<component::Position>::get().addComponentForEntity(id, static_cast<int>(pos.X), static_cast<int>(pos.Y));

		return id;
	}
}