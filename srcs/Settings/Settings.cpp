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

#include "Entity/Entity.hpp"

#include "Settings.hpp"

namespace ecs {

	InitSettings::InitSettings()
	{
		auto id = entity::Manager::get().newEntity();

		component::Settings &settings = component::Manager<component::Settings>::get().addComponentForEntity(id);
		settings.actions = {
			{"p1_up", {irr::EKEY_CODE::KEY_KEY_Z, false}},
			{"p1_down", {irr::EKEY_CODE::KEY_KEY_S, false}},
			{"p1_right", {irr::EKEY_CODE::KEY_KEY_D, false}},
			{"p1_left", {irr::EKEY_CODE::KEY_KEY_Q, false}},
			{"p1_fire", {irr::EKEY_CODE::KEY_SPACE, false}},
			{"p1_event", {irr::EKEY_CODE::KEY_KEY_E, false}},
			{"p2_up", {irr::EKEY_CODE::KEY_UP, false}},
			{"p2_down", {irr::EKEY_CODE::KEY_DOWN, false}},
			{"p2_right", {irr::EKEY_CODE::KEY_RIGHT, false}},
			{"p2_left", {irr::EKEY_CODE::KEY_LEFT, false}},
			{"p2_fire", {irr::EKEY_CODE::KEY_KEY_M, false}},
			{"p2_event", {irr::EKEY_CODE::KEY_KEY_L, false}}
		};
		parsSettingsFile();
	}

	bool InitSettings::parsSettingsFile()
	{
		auto &actions = component::Manager<component::Settings>::get()[_settingsId].actions;
		auto file = std::ifstream{".settings"};

		if (!file.good())
			return false;
		std::string line;
		while (std::getline(file, line)) {
			auto key = line.substr(0, line.find(':'));
			if (actions.find(key) != actions.end()) {
				std::stringstream sstr{line.substr(line.find(':'))};
				std::string code;
				sstr >> code;
				// irr::EKEY_CODE keycode = find the matching code who match with the string code
				// actons[key] = {keycode, false};
			}
		}
		return true;
	}

}

/*
p1_up     -> fait bouger le joueur 1 le haut  // navigue dans les menus vers le haut
p1_down   -> fait bouger le joueur 1 le bas   // navigue dans les menus vers le bas
p1_right  -> fait bouger le joueur 1 la droite    // navigue dans les menus vers la droite
p1_left   -> fait bouger le joueur 1 la gauche    // navigue dans les menus vers la gauche
p1_fire   -> pose une bombe au pied du joueur 1   // active le bouton selectionné
p1_event  -> applique un effet 'in game' du joueur 1 (varie en fonction des bonus)
p2_up     -> fait bouger le joueur 2 le haut
p2_down   -> fait bouger le joueur 2 le bas
p2_right  -> fait bouger le joueur 2 le droite
p2_left   -> fait bouger le joueur 2 le gauche
p2_fire   -> pose une bombe au pied du joueur 2
p2_event  -> applique un effet 'in game' du joueur 2 (varie en fonction des bonus)
*/
