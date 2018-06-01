/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <Graphical/EventReceiver.hpp>
#include "MapGen/mapGen.hpp"
#include <ctime>
#include <Graphical/SystemCreate.hpp>
#include <Systems/SystemExplode.hpp>
#include <basicECS/Systems.hpp>

int main() {
	srand(time(NULL));
	MyEventReceiver event;
	irr::IrrlichtDevice *device =
		irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1020, 1080), 16,
			     false, false, false, &event);

	if (!device)
		return 1;
	device->setWindowCaption(L"Bomberman");

	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	mapGen(10, 10, smgr, driver);

	irr::core::array<irr::SJoystickInfo> joystickInfo;
	device->activateJoysticks(joystickInfo);

	ecs::system::Create::createPlayer(device, driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(100,100));

	while(device->run())
	{
		ecs::system::Explode::update(smgr, driver);
		ecs::system::Update::Bomb(smgr);
		ecs::system::Destroyer::update();

		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
}
