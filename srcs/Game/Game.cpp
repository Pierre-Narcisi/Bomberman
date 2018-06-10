/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Game.cpp
*/

#include <irrlicht/irrlicht.h>

#include "Game.hpp"
#include "ECS/Entity/Filter.hpp"

#include "Settings/Inputs.hpp"
#include "System/Explode.hpp"
#include "System/Update.hpp"
#include "System/Graphical.hpp"
#include "System/Collider.hpp"
#include "System/Destroyer.hpp"

#include "Component/Map.hpp"
#include "System/Ai.hpp"
#include "Json/Parser.hpp"

#include <chrono>
#include <thread>

namespace indie {

	Game::Game()
	{
		try {
			_settings = json::Parser::fromFile(".settings.json")["settings"];
			if (_settings["display"]["width"].isNumber() == false
			|| _settings["display"]["height"].isNumber() == false) {
				_settings["display"]["width"] = 1000;
				_settings["display"]["height"] = 1000;
			}
			_settings["gameName"].isString();
		} catch (json::Parser::ParserException &e) {
			setDefaultSettings();
		}
		_device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(_settings["display"]["width"].to<int>(), _settings["display"]["height"].to<int>()),
			16, false, false, false, &_event);
		if (_device == nullptr)
			throw GameException{"Error when create device"};
		irr::core::stringw gameName = L"";
		gameName += _settings["gameName"].to<std::string>().c_str();
		_device->setWindowCaption(gameName.c_str());
		_driver = _device->getVideoDriver();
		_smgr = _device->getSceneManager();
		_guienv = _device->getGUIEnvironment();
		_mouse = ecs::entity::Manager::get().newEntity();
		ecs::component::Manager<ecs::component::Mouse>::get().addComponentForEntity(_mouse);

		irr::video::ITexture* images = _driver->getTexture("./assets/splash.jpg");
		_driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		_driver->draw2DImage(images, irr::core::position2d<irr::s32>(0, 0),
				irr::core::rect<irr::s32>(0, 0, 1920, 1080), 0,
				irr::video::SColor(255, 255, 255, 255), true);
		_driver->endScene();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}

	Game &Game::get()
	{
		static Game game;

		return game;
	}

	json::Entity &Game::getSettings()
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
			auto Res = _driver->getScreenSize();
			_driver->setViewPort(irr::core::rect<irr::s32>(0,0,Res.Width,Res.Height));
			_driver->beginScene(true, true, irr::video::SColor(255,30,0,0));

			/* menu loop */
			ecs::system::Blur::update();

			/* camera loop */
			ecs::entity::Filter<ecs::component::Being, ecs::component::Ai> ai;
			ecs::entity::Filter<ecs::component::Camera> fl;
			auto &cam = ecs::component::Manager<ecs::component::Camera>::get();

			if (fl.list.size() == 1) {
				auto it = fl.list.begin();

				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(0,0,Res.Width,Res.Height));
				_smgr->drawAll();
			}

			if (fl.list.size() == 2) {
				auto it = fl.list.begin();

				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(0,Res.Height/4,Res.Width/2,Res.Height/2 + Res.Height/4));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(Res.Width/2,Res.Height/4,Res.Width,Res.Height/2 + Res.Height/4));
				_smgr->drawAll();
			}

			if (fl.list.size() == 3) {
				auto it = fl.list.begin();

				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(0,0,Res.Width/2,Res.Height/2));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(Res.Width/2,0,Res.Width,Res.Height/2));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(Res.Width/4,Res.Height/2,Res.Width/2 + Res.Width/4,Res.Height));
				_smgr->drawAll();
			}

			if (fl.list.size() == 4) {
				auto it = fl.list.begin();

				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(0,0,Res.Width/2,Res.Height/2));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(Res.Width/2,0,Res.Width,Res.Height/2));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(0,Res.Height/2,Res.Width/2,Res.Height));
				_smgr->drawAll();
				it++;
				_smgr->setActiveCamera(cam[*it]._camera);
				_driver->setViewPort(irr::core::rect<irr::s32>(Res.Width/2,Res.Height/2,Res.Width,Res.Height));
				_smgr->drawAll();
			}

			ecs::entity::Filter<ecs::component::Input> in;
			if (fl.list.size() != 0 && in.list.size() == 0)
				_device->closeDevice();

			ecs::entity::Filter<ecs::component::Position, ecs::component::UnanimatedObject, ecs::component::Type> bonus;
			ecs::entity::Filter<ecs::component::Being, ecs::component::Stat> taker;
			auto &bpos = ecs::component::Manager<ecs::component::Position>::get();
			auto &btype = ecs::component::Manager<ecs::component::Type>::get();
			auto &boite = ecs::component::Manager<ecs::component::UnanimatedObject>::get();
			auto &ptake = ecs::component::Manager<ecs::component::Being>::get();
			auto &pstat = ecs::component::Manager<ecs::component::Stat>::get();
			for (auto &id : bonus.list) {
				if (btype[id].t == ecs::component::Type::Enum::BonusBomb ||
					btype[id].t == ecs::component::Type::Enum::BonusRange ||
					btype[id].t == ecs::component::Type::Enum::BonusSpeed) {
					std::cout << std::endl << "pos x:" << bpos[id].x << " pos y:" << bpos[id].y << std::endl;
					for (auto &ID : taker.list) {
						if (ptake[ID]._node->getPosition().X > bpos[id].x - 50 && ptake[ID]._node->getPosition().X > bpos[id].x + 50) {
							if (ptake[ID]._node->getPosition().Z > bpos[id].y - 50 && ptake[ID]._node->getPosition().Z > bpos[id].y + 50) {
								std::cout << "pos x:" << ptake[ID]._node->getPosition().X << " pos y:" << ptake[ID]._node->getPosition().Z << std::endl;
								if (btype[id].t == ecs::component::Type::Enum::BonusBomb)
									pstat[ID].bombMax += 1;
								else if (btype[id].t == ecs::component::Type::Enum::BonusRange)
									pstat[ID].range += 1;
								else if (btype[id].t == ecs::component::Type::Enum::BonusSpeed)
									pstat[ID].speed += 0.001;
								boite[id]._node->setPosition(irr::core::vector3df(10000,10000,10000));
							}
						}
					}
				}
			}


			/* Set the game loop here */

			ecs::system::Explode::update();
			ecs::system::Update::Bomb();
			ecs::system::Collider::update();
			ecs::system::Ai::updateAll();
			for (auto &id : ai.list) {
				ecs::system::Ai::update(id);
			}
			/*
				update background
				update bombes
				update deletable
			*/
			ecs::system::Destroyer::update();
			drawAll();
			_driver->endScene();
		}
	}

	void Game::drawAll() const
	{
		ecs::entity::Filter<ecs::component::Image> fl;
		ecs::entity::Filter<ecs::component::HoverImage> fl2;
		auto &imgManager = ecs::component::Manager<ecs::component::Image>::get();
		auto &colorManager = ecs::component::Manager<ecs::component::Color>::get();
		auto &delManager = ecs::component::Manager<ecs::component::Deletable>::get();
		auto &hoverImgManager = ecs::component::Manager<ecs::component::HoverImage>::get();

		_smgr->drawAll();
		_guienv->drawAll();
		for (auto e : fl.list) {
			auto const &img = imgManager[e];
			ecs::component::Color color{255, 255, 255, 255};
			if (delManager[e].del == true) {
					_driver->removeTexture(img.image);
					continue;
			}
			if (colorManager.hasComponent(e) == true)
				color = colorManager[e];
			if (img.draw == true) {
				_driver->draw2DImage(img.image, irr::core::position2d<irr::s32>(img.rect.xs, img.rect.ys),
						irr::core::rect<irr::s32>(0, 0, img.rect.xi, img.rect.yi), 0,
						irr::video::SColor(color.a, color.r, color.g, color.b), true);
			} else if (hoverImgManager.hasComponent(e) == true) {
				auto const &hoverImg = hoverImgManager[e];
				_driver->draw2DImage(hoverImg.image, irr::core::position2d<irr::s32>(img.rect.xs, img.rect.ys),
					irr::core::rect<irr::s32>(0, 0, img.rect.xi, img.rect.yi), 0,
					irr::video::SColor(color.a, color.r, color.g, color.b), true);
			}
		}
	}

	void Game::setDefaultSettings()
	{
		_settings = json::makeObject {
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
		};
	}

}
