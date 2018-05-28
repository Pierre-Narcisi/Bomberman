/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Main.cpp
*/

#include <unistd.h>

#include "Systems.hpp"
#include "Components.hpp"

int help()
{
	std::cerr << "\nje sousigné, avoir lu les conditions d'utilisations.\n";
	std::cerr << "\tdéplacement : [ZQSD]\n";
	std::cerr << "\tbut du jeux : tuer un maximum de monstres !\n";
	std::cerr << "\tpour lancer le jeux: rentre les 42 décimals de pi.\n" << std::endl;
	return (1);
}

int main(int ac, char __attribute__((unused))**av)
{
	if (ac == 1)
		return (help());
	ecs::system::Create::createPlayer();
	ecs::system::Create::createMonster();

	while (std::cin.eof() == false) {
		std::cout << "loop" << std::endl;
		ecs::system::Move::update();
		ecs::system::Position::update();
		ecs::system::Destroyer::update();
		ecs::system::Render::update();
	}
}