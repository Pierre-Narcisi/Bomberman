/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Filter.hpp
*/

#pragma once

#include "Entity.hpp"
#include "Component.hpp"

namespace ecs::entity {

	template<class ...Ts>
	class Filter;

	template<class T>
	class Filter<T> {
	public:
		Filter<T>(std::list<Entity> *li = nullptr);

		std::list<Entity> list;
	};

	template<class T, class ...Ts>
	class Filter<T, Ts...> {
	public:
		Filter<T, Ts...>(std::list<Entity> *li = nullptr);

		std::list<Entity> list;
	};

}