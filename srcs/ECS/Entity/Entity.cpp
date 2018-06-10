/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.cpp
*/

#include <iostream>

#include "Entity.hpp"

namespace ecs { namespace entity {

		Manager &Manager::get()
		{
			static Manager em;

			return em;
		}

		std::list<Id> Manager::list() const
		{
			return _entities;
		}

		Id Manager::newEntity()
		{
			_entities.emplace_back( generateId() );
			_components[_entities.back()];

			return _entities.back();
		}

		void Manager::deleteEntity(Id entity)
		{
			std::cerr << "delete entity " << entity << std::endl;
			for (auto &component : _components.at(entity))
				component.second();
			_components.erase(entity);
			_entities.remove_if([entity] (Id e) {
				return (e == entity);
			});
		}

		void Manager::serializeEntity(Id entity, std::ostream &os) const
		{
			std::cout << "component map size : " << _components.size() << std::endl;
			os << "Id n°" << static_cast<long long>(entity) << " {\n";
			for (auto &component : _components.at(entity))
				os << "\t" << component.first << std::endl;
			os << "}" << std::endl;
		}

		Id Manager::generateId() const
		{
			static Id idCounter = 0;
			return idCounter++;
		}

}}

/*
{
	Entity: [
		ID1,
		id2,
		...
	},
	components: {
		templateName: [
			{
				id: num,
				vars...
			}
			...
		]
		...
	}
}
*/