/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.tpp
*/

#pragma once

#include "Entity.hpp"

namespace ecs::entity {

	template<class T>
	void Entity::setComponent(std::function<void()> deleteFunc)
	{
		_components->emplace(typeid(T).name(), deleteFunc);
	}

	template<class T>
	void Entity::removeComponent()
	{
		if (_components->find(typeid(T).name()) != _components->end())
			_components->erase(typeid(T).name());
	}

}