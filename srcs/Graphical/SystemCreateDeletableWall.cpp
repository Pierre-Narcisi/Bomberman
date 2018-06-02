/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemCreate.hpp"

namespace ecs::system {

	entity::Id Create::createDeletableWall(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id, driver, smgr, "../../assets/wooddencreate.png", pos);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);

		return id;
	}

}