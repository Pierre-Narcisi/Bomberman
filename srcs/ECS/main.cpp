/*
** EPITECH PROJECT, 2017
** Client
** File description:
** main.cpp
*/

#include "Entity.hpp"
#include "Component.hpp"
#include "Filter.hpp"

struct Position {
	int x;
	int y;
};

int main()
{
	ecs::entity::Manager &instance = ecs::entity::Manager::get();
	ecs::entity::Entity &player1 = instance.newEntity();

	ecs::component::Manager<Position>::get().addComponentForEntity(player1);

	std::cout << player1 << std::endl;
	Position &myPositionComponent = ecs::component::Manager<Position>::get().getComponentForEntity( player1.getId() );
	myPositionComponent.x = 100;
	myPositionComponent.y = 300;

	ecs::entity::Manager::get().deleteEntity(player1);

}