/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Game.cpp
*/

#include <irrlicht/irrlicht.h>

#include "Parser.hpp"
#include "Game.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Settings/Inputs.hpp"
#include "System/Explode.hpp"
#include "System/Update.hpp"
#include "System/Collider.hpp"
#include "System/Destroyer.hpp"

namespace indie {

	Game::Game()
	{
		try {
			_settings = json::Parser::fromFile(".settings");
		} catch (json::Parser::ParserException &e) {
			/* set default settings */
		}
		/* change width and height by the settings-width and settings-height */
		_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 16,
					false, false, false, &_event);

		if (_device == nullptr)
			throw GameException{"Error when create device"};
		/* change name by the settings-gameName */
		_device->setWindowCaption(L"Bomberman");
		_driver = _device->getVideoDriver();
		_smgr = _device->getSceneManager();
		_guienv = _device->getGUIEnvironment();
		_mouse = ecs::entity::Manager::get().newEntity();
		ecs::component::Manager<ecs::component::Mouse>::get().addComponentForEntity(_mouse);
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

	ecs::entity::Id		Game::getMouse() const
	{
		return _mouse;
	}

	void Game::gameLoop()
	{
		while(_device->run() == true) {
			_driver->beginScene(true, true, irr::video::SColor(255,100,101,140));

			/* Set the game loop here */
			ecs::system::Explode::update();
			ecs::system::Update::Bomb();
			ecs::system::Destroyer::update();
			ecs::system::Collider::update();
/*
	update background
	update bombes
	update deletable
*/
			drawAll();
			_driver->endScene();
		}
	}

	void Game::drawAll()
	{
		ecs::entity::Filter<ecs::component::Image> fl;
		ecs::entity::Filter<ecs::component::HoverImage> fl2;
		auto &imgManager = ecs::component::Manager<ecs::component::Image>::get();
		auto &hoverImgManager = ecs::component::Manager<ecs::component::HoverImage>::get();

		_smgr->drawAll();
		_guienv->drawAll();
		for (auto e : fl.list) {
			auto const &img = imgManager[e];
			if (img.draw == true) {
				_driver->draw2DImage(img.image, irr::core::position2d<irr::s32>(img.rect.xs, img.rect.ys),
						irr::core::rect<irr::s32>(0, 0, img.rect.xi, img.rect.yi), 0,
						irr::video::SColor(255, 255, 255, 255), true);
			} else if (hoverImgManager.hasComponent(e) == true) {
				auto const &hoverImg = hoverImgManager[e];
				_driver->draw2DImage(hoverImg.image, irr::core::position2d<irr::s32>(img.rect.xs, img.rect.ys),
					irr::core::rect<irr::s32>(0, 0, img.rect.xi, img.rect.yi), 0,
					irr::video::SColor(255, 255, 255, 255), true);
			}
		}
	}

}