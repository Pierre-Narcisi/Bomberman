/*
** EPITECH PROJECT, 2017
** Client
** File description:
** main.cpp
*/

#include "Entity.hpp"
#include "Component.hpp"
#include "Filter.hpp"

struct Test {

};

int main()
{
	auto &entityManager = ecs::entity::Manager::get();
	auto &componentManager = ecs::component::Manager<Test>::get();
}