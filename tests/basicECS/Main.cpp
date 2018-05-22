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
	ecs::system::Create::createPlayer();
	ecs::system::Create::createMonster();

	while (std::cin.eof() == false) {
		std::cout << "loop" << std::endl;
		ecs::system::Position::update();
		ecs::system::Move::update();
		ecs::system::Destroyer::update();
		ecs::system::Render::update();
	}
}