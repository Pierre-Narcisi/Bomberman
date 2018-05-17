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
	class Filter {
	public:
		std::list<Id> list;
	};

}

#include "Filter.tpp"