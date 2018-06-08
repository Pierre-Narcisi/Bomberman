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

	static entity::Id createBackground(std::string const &image, component::Rect const &rect,
		component::Color const &color)
	{
		auto &game = indie::Game::get();
		auto id = entity::Manager::get().newEntity();

		irr::video::ITexture *texture = game.getDriver()->getTexture(image.c_str());
		component::Manager<component::Image>::get().addComponentForEntity(id, texture, rect);
		component::Manager<component::Color>::get().addComponentForEntity(id, color);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);
		return id;
	}

	static entity::Id createButton(component::Button::Type const &type,
		std::string const &image, component::Rect const &rect,
		std::string const &hover = "")
	{
		auto &game = indie::Game::get();
		auto id = entity::Manager::get().newEntity();

		irr::video::ITexture *texture = game.getDriver()->getTexture(image.c_str());
		component::Manager<component::Button>::get().addComponentForEntity(id, type);
		component::Manager<component::Image>::get().addComponentForEntity(id, texture, rect);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);
		if (hover != "") {
			irr::video::ITexture *hoverTexture = game.getDriver()->getTexture(hover.c_str());
			component::Manager<component::HoverImage>::get().addComponentForEntity(id, hoverTexture, rect);
		}
		return id;
	}

}
