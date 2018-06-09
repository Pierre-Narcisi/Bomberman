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

#include "Graphical/EventReceiver.hpp"
#include "Score.hpp"

#include "ECS/Entity/Entity.hpp"
#include "Json/srcs/Entity/Entity.hpp"

namespace indie {

	class Game {
	public:
		void		gameLoop();
		void		save();
		void		load();
		void		updateScore();
		void		loadScore();

	public:
		static Game			&get();
		json::Entity const		&getSettings() const;
		irr::IrrlichtDevice		*getDevice() const;
		irr::video::IVideoDriver	*getDriver() const;
		irr::scene::ISceneManager	*getSmgr() const;
		ecs::entity::Id			getMouse() const;

	protected:
		json::Entity			_settings;
		MyEventReceiver			_event;
		irr::IrrlichtDevice		*_device;
		irr::video::IVideoDriver	*_driver;
		irr::scene::ISceneManager	*_smgr;
		irr::gui::IGUIEnvironment	*_guienv;
		ecs::entity::Id			_mouse;

		Score				_score;

	protected:
		/* init the window */
		Game();
		void drawAll() const;
		void setDefaultSettings();

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
