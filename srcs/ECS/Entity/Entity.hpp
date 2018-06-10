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

namespace ecs { namespace entity {

	using Id = std::size_t;

	class Manager {
	public:
		static Manager &get();

		~Manager()
		{
			std::cout << "destroy EntityManager" << std::endl;
		}

		Id newEntity();
		void deleteEntity(Id);

		std::list<Id> list() const;
		void serializeEntity(Id, std::ostream & = std::cout) const;

		/* Do not call it directly */
		template<class T>
		void setComponent(Id, std::function<void()> deleteFunc);
		/* Do not call it directly */
		template<class T>
		void removeComponent(Id);

	private:
		Manager()
		{
			std::cout << "init EntityManager" << std::endl;
		}

		Id generateId() const;

	private:
		std::unordered_map<Id, std::unordered_map<std::string, std::function<void ()>>> _components;
		std::list<Id> _entities;
	};

}}

#include "Entity.tpp"