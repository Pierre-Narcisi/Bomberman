/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <Graphical/EventReceiver.hpp>
#include <ctime>
#include <Graphical/SystemCreate.hpp>

int main() {
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

	irr::core::array<irr::SJoystickInfo> joystickInfo;
	device->activateJoysticks(joystickInfo);

	ecs::system::Create::createWall(driver, smgr, irr::core::vector2df(200, 200));
	ecs::system::Create::createDeletableWall(driver, smgr, irr::core::vector2df(300, 200));

	ecs::system::Create::createPlayer(device, driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(0,0));

	while(device->run())
	{
		irr::core::stringw str = L"Bomberman :";
		str += driver->getFPS();
		str += " fps";
		device->setWindowCaption(str.c_str());

		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
}