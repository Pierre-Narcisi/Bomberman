/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.hpp
*/

#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include <list>
#include <unordered_map>

#include "EntityErrors.hpp"

namespace ecs::entity {

	using Id = std::size_t;

	class Entity {
	public:
		Entity(Id id);
		~Entity();
		Entity(Entity const &other);
		Entity(Entity &&other) = default;
		Entity &operator=(Entity const &other);
		Entity &operator=(Entity &&other) = default;

		Id getId() const;
		void serialize(std::ostream & = std::cout) const;

		/* Do not call it directly */
		template<class T>
		void setComponent(std::function<void()> deleteFunc);
		/* Do not call it directly */
		template<class T>
		void removeComponent();

	private:	
		Id _id;
		std::shared_ptr<std::unordered_map<std::string, std::function<void()>>> _components;
	};

	class Manager {
	public:
		static Manager &get();

		Entity &newEntity();
		void deleteEntity(Entity const &entity);
		void deleteEntity(Id entityId);

		Entity &operator[](Id entityId);
		Entity const &operator[](Id entityId) const;
		std::list<Entity> list() const;

	private:
		Manager() = default;

		Id generateId();

	private:
		Id _idCounter = 0;
		std::list<Entity> _entities;
	};

}

std::ostream &operator<<(std::ostream &, ecs::entity::Entity const &);

#include "Entity.tpp"