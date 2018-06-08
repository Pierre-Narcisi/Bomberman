/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Collider.cpp
*/

#include "Game/Game.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Component/Basics.hpp"
#include "Component/Graphicals.hpp"
#include "System/Graphical.hpp"
#include "Settings/Inputs.hpp"

#include "System/Collider.hpp"

#include <iostream>

namespace ecs::system {

	void Collider::update()
	{
		auto const &mouse = component::Manager<component::Mouse>::get()[indie::Game::get().getMouse()];
		entity::Filter<component::Button, component::Image> fl;
		auto &imgManager = component::Manager<component::Image>::get();
		auto &hoverManager = component::Manager<component::HoverImage>::get();

		for (auto &e : fl.list) {
			auto &img = imgManager[e];
			if (rectCollide(mouse, img.rect) == true) {
				if (hoverManager.hasComponent(e) == true) {
					img.draw = false;
				}
			} else {
				if (hoverManager.hasComponent(e) == true && img.draw == false) {
					img.draw = true;
				}
			}
		}
	}

	void Collider::click()
	{
		auto const &mouse = component::Manager<component::Mouse>::get()[indie::Game::get().getMouse()];
		entity::Filter<component::Button, component::Image> fl;
		auto &buttonManager = component::Manager<component::Button>::get();
		auto &imgManager = component::Manager<component::Image>::get();
		auto &delManager = component::Manager<component::Deletable>::get();

		for (auto &e : fl.list) {
			auto &img = imgManager[e];
			if (img.draw == false && delManager[e].del == false) {
				if (buttonManager[e].type == ecs::component::Button::Type::Quit) {
					indie::Game::get().getDevice()->closeDevice();
				} else if (buttonManager[e].type == ecs::component::Button::Type::Play) {
					ecs::system::Deletable::button();
					ecs::system::Scene::loadSceneTwo();
				} else if (buttonManager[e].type == ecs::component::Button::Type::Solo) {
					ecs::system::Deletable::all();
					ecs::system::Scene::loadGame();
				}
			}
		}
	}

	bool Collider::rectCollide(component::Mouse const &mouse, component::Rect const &rect)
	{
		return	mouse.position.X >= rect.xs &&
			mouse.position.X <= rect.xs + rect.xi &&
			mouse.position.Y >= rect.ys &&
			mouse.position.Y <= rect.ys + rect.yi;
	}

}
