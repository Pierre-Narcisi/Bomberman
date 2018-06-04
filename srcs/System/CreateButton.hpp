/*
** EPITECH PROJECT, 2017
** Client
** File description:
** CreateSystem.hpp
*/



#pragma once

#include "ECS/Entity/Entity.hpp"
#include "ECS/Entity/Filter.hpp"
#include "ECS/Component/Component.hpp"

#include "Component/Graphicals.hpp"
#include "Component/Basics.hpp"
#include "Settings/Inputs.hpp"

#include "Game/Game.hpp"

namespace ecs::system {

	static void createBackground(std::string const &image, component::Rect rect, component::Color color)
	{
		auto &game = indie::Game::get();
		auto id = entity::Manager::get().newEntity();

		irr::video::ITexture *texture = game.getDriver()->getTexture(image.c_str());
		// component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Background);
		component::Manager<component::Image>::get().addComponentForEntity(id, texture, rect, color);
	}

	static void createButton(std::string const &image, component::Rect rect, component::Color color, component::Button::Type type)
	{
		auto &game = indie::Game::get();
		auto id = entity::Manager::get().newEntity();

		irr::video::ITexture *texture = game.getDriver()->getTexture(image.c_str());
		// component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Background);
		component::Manager<component::Image>::get().addComponentForEntity(id, texture, rect, color);
		component::Manager<component::Button>::get().addComponentForEntity(id, type, id);
		// ecs::entity::Filter<component::MenuInput> fl;
		// auto &menu = component::Manager<component::MenuInput>::get()[*fl.list.begin()];
	}

}