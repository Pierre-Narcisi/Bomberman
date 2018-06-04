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

#include "ECS/Entity/Entity.hpp"
#include "ECS/Component/Component.hpp"

#include "Settings.hpp"

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

namespace ecs::system {

	void InitInputs::CreateInputsForPlayer(entity::Id id, std::string const &player)
	{
		component::Input &inputs = component::Manager<component::Input>::get().addComponentForEntity(id);
		json::Entity settings = getSettings();

		/* json::Entity serializer(json::makeObject {
			{"Entity", json::Entity::ARR},
			{"Components", json::Entity::OBJ}
		});
		serializer["Components"]["position"].push(json::makeObject {
			{"id", 12},

		})
		std::cout << serializer << std::endl;
		std::string a(json::Entity(12).to<std::string>());
		serializer = serializer.getData<json::Object>().get(); */
	}

}