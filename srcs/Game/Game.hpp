/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Game.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>
#include <exception>

#include "JsonEntity.hpp"
#include "EventReceiver.hpp"
#include "Score.hpp"

namespace indie {

	class Game {
	public:
		void		gameLoop();
		void		save();
		void		load();
		void		updateScore();
		void		loadScore();

	public:
		static Game		&get();
		json::Entity		&getSettings();
		irr::IrrlichtDevice	*getDevice();
		irr::IVideoDriver	*getDriver();
		irr::ISceneManager	*getSmgr();

	protected:
		json::Entity			settings;
		MyEventReceiver			event;
		irr::IrrlichtDevice		*device;
		irr::video::IVideoDriver	*driver;
		irr::scene::ISceneManager	*smgr;
		irr::gui::IGUIEnvironment	*guienv;

		Score				score;

	private:
		/* init the window */
		Game();

	public:
		struct GameException : public std::exception
		{
		public:
			GameException(std::string const &msg):_msg{msg} {}

			const char	*what() const throw();
		private:
			std::string	_msg;
		};
	};

}