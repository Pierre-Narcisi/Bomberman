/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Component.tpp
*/

#pragma once

#include <functional>

#include "Component.hpp"

namespace ecs::component {

	template<class T>
	Manager<T> &Manager<T>::get()
	{
		static Manager<T> st;

		return st;
	}

	template<class T>
	Manager<T>::~Manager()
	{
		auto &manager = entity::Manager::get();

		for (auto const &e : _store)
			manager[e.first].removeComponent<T>();
	}

	template<class T>
	template<typename ...Args>
	void Manager<T>::addComponentForEntity(entity::Entity &entity, Args &&...args)
	{
		if (_store.find(entity.getId()) != _store.end()) {
			_components[_store[entity.getId()]] = T(args...);
		} else {
			_components.emplace_back( std::forward<Args>(args)... );
			entity.setComponent<T>(
				std::bind( &Manager<T>::removeComponentForEntityId, this, entity.getId() )
			);

			_store[entity.getId()] = _components.size() - 1;
		}
	}

	template<class T>
	template<typename ...Args>
	void Manager<T>::addComponentForEntity(entity::Id entityId, Args &&...args)
	{
		addComponentForEntity( entity::Manager::get()[entityId], std::forward<Args>(args)... );
	}

	template<class T>
	void Manager<T>::removeComponentForEntity(entity::Entity &entity)
	{
		auto removeIndex = _store[entity.getId()];

		entity.removeComponent<T>();
		_store[_components.back().entityId] = removeIndex;
		std::swap(_components[removeIndex], _components.back());
		_components.pop_back();

		_store.erase(entity.getId());
	}

	template<class T>
	void Manager<T>::removeComponentForEntityId(entity::Id entityId)
	{
		try {
			removeComponentForEntity(entity::Manager::get()[entityId]);
		} catch (entity::EntityError const &) {
			auto removeIndex = _store[entityId];
			_store[_components.back().entityId] = removeIndex;
			std::swap(_components[removeIndex], _components.back());
			_components.pop_back();

			_store.erase(entityId);			
		}
	}

	template<class T>
	T &Manager<T>::getComponentForEntity(entity::Entity const &entity)
	{
		return _components[_store[entity.getId()]];
	}

	template<class T>
	T &Manager<T>::getComponentForEntity(entity::Id entityId)
	{
		return _components[_store[entityId]];
	}

	template<class T>
	bool Manager<T>::hasEntityComponent(entity::Id entityId) const
	{
		return _store.find(entityId) != _store.end();
	}

}