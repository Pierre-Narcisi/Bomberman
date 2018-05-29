/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Settings.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include <string>
#include <unordered_map>

namespace ecs {

	namespace component {

		struct Settings {
			struct Action {
				irr::EKEY_CODE	key;
				bool		state;
			};
			Settings() = default;
			
			std::unordered_map<std::string, Action> actions;
		};

	}

	namespace system {

	}

	class InitSettings {
	public:
		InitSettings();
	protected:
		bool parsSettingsFile();
		entity::Id _settingsId;
	};


}