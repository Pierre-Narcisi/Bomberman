/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Filter.tpp
*/

#pragma once

#include <list>

#include "Filter.hpp"

namespace ecs::entity {

	template<class ...Ts>
	class Filter;

	template<class T>
	class Filter<T> {
	public:
		Filter<T>(std::list<Entity> *li = nullptr)
		{
			if (li == nullptr)
				list = EntityManager::get().list();
			else
				list = *li;
			list.remove_if([] (Entity const &e) {
				return !Storage<T>::get().hasEntityComponent(e.getId());
			});
		}
		std::list<Entity> list;
	};

	template<class T, class ...Ts>
	class Filter<T, Ts...> {
	public:
		Filter<T, Ts...>(std::list<Entity> *li = nullptr)
		{
			Filter<Ts...> filters(li);

			list = std::move(filters.list);
			list.remove_if([] (Entity const &e) {
				return !Storage<T>::get().hasEntityComponent(e.getId());
			});
		}
		std::list<Entity> list;
	};

}
