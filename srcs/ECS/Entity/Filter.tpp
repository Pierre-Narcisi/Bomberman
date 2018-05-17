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

	template<class T>
	class Filter<T> {
	public:
		Filter<T>():
		list{ entity::Manager::get().list() }
		{
			list.remove_if([] (Id e) {
				return !component::Manager<T>::get().hasEntityComponent(e);
			});
		}
		Filter<T>(std::list<Id> &li):
		list { std::move(li) }
		{
			list.remove_if([] (Id e) {
				return !component::Manager<T>::get().hasEntityComponent(e);
			});
		}
		std::list<Id> list;
	};

	template<class T, class ...Ts>
	class Filter<T, Ts...> {
	public:
		Filter<T, Ts...>():
		list{ entity::Manager::get().list() }
		{
			Filter<Ts...> filters(list);

			list = std::move(filters.list);
			list.remove_if([] (Id e) {
				return !component::Manager<T>::get().hasEntityComponent(e);
			});
		}
		Filter<T, Ts...>(std::list<Id> &li)
		{
			Filter<Ts...> filters(li);

			list = std::move(filters.list);
			list.remove_if([] (Id e) {
				return !component::Manager<T>::get().hasEntityComponent(e);
			});
		}
		std::list<Id> list;
	};

}
