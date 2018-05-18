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

struct BoxCollider {
	int x;
	int y;
};

int main()
{
	ecs::entity::Manager &instance = ecs::entity::Manager::get();
	ecs::entity::Id p0 = instance.newEntity();
	ecs::entity::Id p1 = instance.newEntity();
	ecs::entity::Id p2 = instance.newEntity();
	ecs::entity::Id p3 = instance.newEntity();
	ecs::entity::Id p4 = instance.newEntity();
	ecs::entity::Id p5 = instance.newEntity();

	ecs::component::Manager<Position>::get().addComponentForEntity(p0);
	ecs::component::Manager<Position>::get().addComponentForEntity(p1);
	ecs::component::Manager<Position>::get().addComponentForEntity(p3);
	ecs::component::Manager<Position>::get().addComponentForEntity(p4);
	ecs::component::Manager<BoxCollider>::get().addComponentForEntity(p1);
	ecs::component::Manager<BoxCollider>::get().addComponentForEntity(p2);
	ecs::component::Manager<BoxCollider>::get().addComponentForEntity(p4);
	ecs::component::Manager<BoxCollider>::get().addComponentForEntity(p5);

	ecs::entity::Manager::get().deleteEntity(p1);
	ecs::entity::Filter<Position> fl;
	std::cout << "print filter 1" << std::endl;
	for (auto e : fl.list) {
		ecs::entity::Manager::get().serializeEntity(e);
	}

	ecs::entity::Filter<Position, BoxCollider> fl2;
	std::cout << "print filter 2" << std::endl;
	for (auto e : fl2.list) {
		ecs::entity::Manager::get().serializeEntity(e);
	}

	ecs::entity::Filter<BoxCollider> fl3(fl.list);
	std::cout << "print filter 3" << std::endl;
	for (auto e : fl3.list) {
		ecs::entity::Manager::get().serializeEntity(e);
	}

}