/*
** EPITECH PROJECT, 2017
** Client
** File description:
** System.hpp
*/

#pragma once

#include "ECS/Entity/Entity.hpp"
#include "ECS/Entity/Filter.hpp"
#include "ECS/Component/Component.hpp"

#include "Component/Basics.hpp"

namespace ecs { namespace system {

	class Destroyer {
	public:
		static void update()
		{
			entity::Filter<component::Deletable> fl;
			auto &deleteManager = component::Manager<component::Deletable>::get();

			for (auto id : fl.list) {
				// std::cout << "delete " << deleteManager[id].del << std::endl;
				if (deleteManager[id].del)
					entity::Manager::get().deleteEntity(id);
			}
		}
	};

}}