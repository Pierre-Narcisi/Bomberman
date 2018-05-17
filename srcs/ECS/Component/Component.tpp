/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Component.tpp
*/

#pragma once

#include <functional>

#include "Component.hpp"
#include "Entity.hpp"

struct bla {};

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

		while (_components.size() != 0)
			manager.template removeComponent<T>(_components.begin()->first);
	}

	template<class T>
	template<typename ...Args>
	void Manager<T>::addComponentForEntity(entity::Id entity, Args &&...args)
	{
		_components[entity] = T(std::forward<Args>(args)... );
		entity::Manager::get().template setComponent<T>(entity,
		std::bind(&Manager::callBackremoveEntity, this, entity));
	}

	template<class T>
	void Manager<T>::removeComponentForEntity(entity::Id entity)
	{
		_components.erase(entity);
		entity::Manager::get().removeComponent<T>(entity);
	}

	template<class T>
	T &Manager<T>::getComponentForEntity(entity::Id entity)
	{
		return _components.at(entity);
	}

	template<class T>
	bool Manager<T>::hasEntityComponent(entity::Id entity) const
	{
		return _components.find(entity) != _components.end();
	}

	template<class T>
	void Manager<T>::callBackremoveEntity(entity::Id entity)
	{
		if (_components.find(entity) != _components.end())
			_components.erase(entity);
	}

}