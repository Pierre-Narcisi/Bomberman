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

#include "Json/Entity.hpp"
#include "Graphical/EventReceiver.hpp"
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
		irr::video::IVideoDriver	*getDriver();
		irr::scene::ISceneManager	*getSmgr();

	protected:
		json::Entity			_settings;
		MyEventReceiver			_event;
		irr::IrrlichtDevice		*_device;
		irr::video::IVideoDriver	*_driver;
		irr::scene::ISceneManager	*_smgr;
		irr::gui::IGUIEnvironment	*_guienv;

		Score				_score;

	private:
		/* init the window */
		Game();

	public:
		struct GameException : public std::exception {
		public:
			GameException(std::string const &msg):_msg{msg} {}
			virtual ~GameException() throw(){}

			const char	*what() const throw() override
			{
				return _msg.c_str();
			}
		private:
			std::string	_msg;
		};
	};

}