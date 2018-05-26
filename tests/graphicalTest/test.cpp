/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <Graphical/Systems.hpp>
#include <Graphical/EventReceiver.hpp>

int main() {
	evt::Manager &m = evt::Manager::get();
	MyEventReceiver event;
	irr::IrrlichtDevice *device =
		irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1020, 1080), 16,
			     false, false, false, &event);

	m["event"]->addHandler<void, irr::SEvent&>((const std::function<void(irr::SEvent &)> &) [] (irr::SEvent &event) {
			ecs::system::gi::Events::Manager(event);
		});

	if (!device)
		return 1;
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	ecs::system::gi::Create::createPlayer(driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(0,0));

	while(device->run())
	{
		ecs::system::gi::Routine::Deplacement();
		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
}