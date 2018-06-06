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
#include "Settings/Inputs.hpp"

#include "System/Collider.hpp"

namespace ecs::system {

	void Collider::update()
	{
		auto const &mouse = component::Manager<component::Mouse>::get()[indie::Game::get().getMouse()];
		entity::Filter<component::Button, component::Image> fl;
		auto &buttonManager = component::Manager<component::Button>::get();
		auto &imgManager = component::Manager<component::Image>::get();
		auto &hoverManager = component::Manager<component::HoverImage>::get();

		for (auto &e : fl.list) {
			auto &img = imgManager[e];
			if (rectCollide(mouse, img.rect) == true) {
				if (hoverManager.hasComponent(e) == true) {
					img.draw = false;
					/* applique system qui fait bougé hoverState */
				}
			} else {
				if (hoverManager.hasComponent(e) == true && img.draw == false) {
					img.draw = true;
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