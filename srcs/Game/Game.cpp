/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Game.cpp
*/

#include "Parser.hpp"
#include "Game.hpp"
#include "Explode.hpp"
#include "Update.hpp"
#include "Destroyer.hpp"

#include "Component/Map.hpp"
#include "System/Ai.hpp"

namespace indie {

	Game::Game()
	{
		try {
			_settings = json::Parser::fromFile(".settings");
		} catch (json::Parser::ParserException &e) {
			/* set default settings */
		}
		/* change width and height by the settings-width and settings-height */
		_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1020, 1080), 16,
					false, false, false, &_event);

		if (_device == nullptr)
			throw GameException{"Error when create device"};
		/* change name by the settings-gameName */
		_device->setWindowCaption(L"Bomberman");
		_driver = _device->getVideoDriver();
		_smgr = _device->getSceneManager();
		_guienv = _device->getGUIEnvironment();
	}

	Game &Game::get()
	{
		static Game game;

		return game;
	}

	json::Entity const &Game::getSettings() const
	{
		return _settings;
	}

	irr::IrrlichtDevice *Game::getDevice() const
	{
		return _device;
	}

	irr::video::IVideoDriver *Game::getDriver() const
	{
		return _driver;
	}

	irr::scene::ISceneManager *Game::getSmgr() const
	{
		return _smgr;
	}

	void Game::gameLoop()
	{
		while(_device->run() == true) {
			_driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
			/* Set the game loop here */

			ecs::entity::Filter<ecs::component::Map> fl;
			//for (auto id : fl.list) {


			//}

			ecs::system::Explode::update();
			ecs::system::Update::Bomb();
			ecs::system::Destroyer::update();
			ecs::system::Ai::updateAll();
			ecs::system::Ai::update(10);
/*
	update background
	update bombes
	update deletable
*/

			_smgr->drawAll();
			_guienv->drawAll();
			_driver->endScene();
		}
	}

}
