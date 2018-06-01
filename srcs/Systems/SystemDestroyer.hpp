/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include "Entity.hpp"
#include "Filter.hpp"
#include "Component.hpp"

#include "Deletable.hpp"
//#include "Components.hpp"

namespace ecs::system {

	class Destroyer {
	public:
		static void update()
		{
			entity::Filter<component::Deletable> fl;
			auto &deleteManager = component::Manager<component::Deletable>::get();

			for (auto &id : fl.list) {
				if (deleteManager[id].del == true)
					entity::Manager::get().deleteEntity(id);
			}
		}
	};

}
