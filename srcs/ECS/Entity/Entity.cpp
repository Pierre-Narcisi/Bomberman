/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Entity.cpp
*/

#include <iostream>

#include "Entity.hpp"

namespace ecs::entity {

	Entity::Entity(Id id) :
	_id{ id },
	_components{std::make_shared<std::unordered_map<std::string, std::function<void()>>>()}
	{
	}

	Entity::~Entity()
	{
		if (_components.use_count() == 1)
			for (auto &component : *_components)
				component.second();
	}

	Entity::Entity(Entity const &other):
	_id{other._id},
	_components{ other._components }
	{
	}

	Entity &Entity::operator=(Entity const &other)
	{
		_id = other._id;
		_components = other._components;
		return *this;
	}

	Id Entity::getId() const
	{
		return _id;
	}

	void Entity::serialize(std::ostream &os) const
	{
		os << "Entity n°" << _id << " {\n";
		for (auto const &component : *_components)
			os << "\t" << component.first << std::endl;
		os << "}";
	}

}

std::ostream &operator<<(std::ostream &os, ecs::entity::Entity const &entity)
{
	entity.serialize();
	return os;
}
