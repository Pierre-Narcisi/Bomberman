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

#include "JsonEntity.hpp"
#include "Entity.hpp"
#include "Component.hpp"

#include "Settings.hpp"

json::Entity getSettings()
{
	json::Entity serializer(json::makeObject {
		{"Settings", json::Entity::OBJ},
		{"Components", json::Entity::OBJ}
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