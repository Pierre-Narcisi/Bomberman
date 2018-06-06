/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Collider.hpp
*/

#pragma once

#include "Component/Graphicals.hpp"
#include "Settings/Inputs.hpp"

namespace ecs::system {

	class Collider {
	public:
		static void update();
		static bool rectCollide(component::Mouse const &, component::Rect const &);
	};

}