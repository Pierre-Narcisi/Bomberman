/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.tpp
*/

#pragma once

#include "Entity.hpp"

namespace ecs { namespace entity {

	template<class T>
	void Manager::setComponent(Id entity, std::function<void()> deleteFunc)
	{
		//std::cout << "set component" << std::endl;
		_components.at(entity).emplace(typeid(T).name(), deleteFunc);
	}

	template<class T>
	void Manager::removeComponent(Id entity)
	{
		//std::cout << "remove component to entity " << (long)entity << std::endl;
		_components.at(entity).at(typeid(T).name())();
		_components.at(entity).erase(typeid(T).name());
	}

}}