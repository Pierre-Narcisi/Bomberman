/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

namespace ecs::system {
	namespace gi {
		class Create {
		public:
			static entity::Id createPlayer(irr::scene::ISceneManager *smgr, std::string mesh, std::string texture, irr::core::vector2df pos)
			{
				auto id = entity::Manager::get().newEntity();
				component::Manager<component::Being>::get().addComponentForEntity(id, smgr, mesh, texture, pos);
				return id;
			}
		};
	}
}
