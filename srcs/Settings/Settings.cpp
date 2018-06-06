/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Settings.cpp
*/

#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Json/srcs/Entity/Entity.hpp"
#include "ECS/Entity/Entity.hpp"

json::Entity getSettings()
{
	json::Entity serializer(json::makeObject {
		{"Settings", json::makeObject {
			{"gameName", "VoodooBomber"},
			{"display", json::makeObject {
				{"width", 1920},
				{"height", 1080},
				{"fps-max", 60}
			}},
			{"Input", json::makeObject {
				{"player1", json::makeObject {
					{"up", "Z"},
					{"down", "S"},
					{"right", "D"},
					{"left", "Q"},
					{"fire", "SPACE"},
					{"event", "E"}
				}},
				{"player2", json::makeObject {
					{"up", "UP"},
					{"down", "DOWN"},
					{"right", "RIGHT"},
					{"left", "LEFT"},
					{"fire", "M"},
					{"event", "L"}
				}}
			}}
		}}
	});
	return json::Entity();
}
json::Entity saveSettings()
{
	return json::Entity();
}