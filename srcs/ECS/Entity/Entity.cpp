/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.cpp
*/

#include <iostream>
#include "JsonEntity.hpp"
#include "Entity.hpp"

namespace ecs::entity {

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
			for (auto &component : _components.at(entity))
				component.second();
			_components.erase(entity);
			_entities.remove_if([entity] (Id e) {
				return (e == entity);
			});
		}

		void Manager::serializeEntity(Id entity, std::ostream &os) const
		{
			/* json::Entity serializer(json::makeObject {
				{"Entity", json::Entity::ARR},
				{"Components", json::Entity::OBJ}
			});
			serializer["Components"]["position"].push(json::makeObject {
				{"id", 12},

			})
			std::cout << serializer << std::endl;
			std::string a(json::Entity(12).to<std::string>());
			serializer = serializer.getData<json::Object>().get(); */
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

}

/*
{
	Entity: [
		ID1,
		id2,
		...
	},
	components: {
		tempateName: [
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