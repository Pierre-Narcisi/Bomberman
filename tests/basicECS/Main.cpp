/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Main.cpp
*/

#include <unistd.h>

#include "Systems.hpp"
#include "Components.hpp"

int main()
{
	auto id = ecs::system::Create::createPlayer();
	auto id2 = ecs::system::Create::createMonster();

	while (1) {
		ecs::system::Position::update();
		ecs::system::Move::update();
		ecs::system::Render::update();
	}
}