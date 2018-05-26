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

	irr::core::array<irr::SJoystickInfo> joystickInfo;
	device->activateJoysticks(joystickInfo);

	for (irr::u32 i = 0; i < joystickInfo.size() ; i++) {
		printf("%s--%d--%d\n", joystickInfo[i].Name.c_str(), joystickInfo[i].Axes, joystickInfo[i].Buttons);
	}

	ecs::system::gi::Create::createPlayer(device, driver, smgr, "../../assets/sydney.md2", "../../assets/sydney.bmp", irr::core::vector2df(0,0));

	while(device->run())
	{
		ecs::system::gi::Routine::Deplacement();
		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->draw2DPolygon(irr::core::position2d<irr::s32>(500, 500), 100, irr::video::SColor(255, 255, 0, 0), 30);
		driver->endScene();
	}
}