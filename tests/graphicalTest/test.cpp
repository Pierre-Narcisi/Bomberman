/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <Graphical/Systems.hpp>

int main() {
	irr::IrrlichtDevice *device =
		irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1080, 720), 16,
			     false, false, false, 0);

	if (!device)
		return 1;
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(0,0));
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(10,0));
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(20,0));
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(30,0));
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(40,0));
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(50,0));

	while(device->run())
	{
		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
}