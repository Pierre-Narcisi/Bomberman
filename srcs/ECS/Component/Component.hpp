/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Manager.hpp
*/

#pragma once

#include <vector>
#include <unordered_map>

#include "ECS/Entity/Entity.hpp"

namespace ecs { namespace component {

	template<class T>
	class Manager {
	public:
		static Manager<T> &get();

		~Manager();

		template<typename ...Args>
		T &addComponentForEntity(entity::Id, Args &&...args);

		void removeComponentForEntity(entity::Id);

		T &operator[](entity::Id);

		bool hasComponent(entity::Id) const;
		void callBackremoveEntity(entity::Id);

	private:
		std::unordered_map<entity::Id, T> _components;
	};

}}

#include "Component.tpp"