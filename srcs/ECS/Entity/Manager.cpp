/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Manager.cpp
*/

#include <algorithm>

#include "Entity.hpp"

namespace ecs::entity {

		Manager &Manager::get()
		{
			static Manager em;

			return em;
		}

		std::list<Entity> Manager::list() const
		{
			return _entities;
		}

		Entity &Manager::newEntity()
		{
			_entities.emplace_back( generateId() );

			return _entities.back();
		}

		void Manager::deleteEntity(Entity const &entity)
		{
			deleteEntity( entity.getId() );
		}

		void Manager::deleteEntity(Id entityId)
		{
			_entities.remove_if([entityId] (Entity const &e) {
				return (e.getId() == entityId);
			});
		}

		Entity &Manager::operator[](Id entityId)
		{
			auto it = std::find_if(_entities.begin(), _entities.end(),
				[entityId] (Entity const &e) {
					return (e.getId() == entityId);
				});
			if (it == _entities.end())
				throw "Id not Found";
			return *it;
		}

		Entity const &Manager::operator[](Id entityId) const
		{
			auto const it = std::find_if(_entities.begin(), _entities.end(),
			[entityId] (Entity const &e) {
				return (e.getId() == entityId);
				});
			if (it == _entities.end())
				throw "Id not Found";
			return *it;
		}

		Id Manager::generateId()
		{
			return _idCounter++;
		}

}