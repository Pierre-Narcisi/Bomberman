/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Manager.hpp
*/

#pragma once

#include <vector>
#include <unordered_map>

namespace ecs::component {

	template<class T>
	class Manager {
	public:
		static Manager<T> &get();

		~Manager();

		template<typename ...Args>
		void addComponentForEntity(entity::Entity &entity, Args &&...args);
		template<typename ...Args>
		void addComponentForEntity(entity::Id entityId, Args &&...args);

		void removeComponentForEntity(entity::Entity &entity);
		void removeComponentForEntityId(entity::Id entityId);

		T &getComponentForEntity(entity::Entity const &entity);
		T &getComponentForEntity(entity::Id entityId);

		bool hasEntityComponent(entity::Id entityId) const;

	private:
		std::vector<T> _components;
		std::unordered_map<entity::Id, std::size_t> _store;
	};

}

#include "Component.tpp"