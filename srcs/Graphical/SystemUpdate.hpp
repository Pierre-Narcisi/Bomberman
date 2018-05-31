/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <ECS/Entity/Filter.hpp>
#include "ComponentBeing.hpp"
#include "ComponentKeyboard.hpp"
#include "ComponentController360.hpp"
#include "ComponentCamera.hpp"

namespace ecs::system {
	class Update {
	public:
		static void Deplacement();
	};
}
