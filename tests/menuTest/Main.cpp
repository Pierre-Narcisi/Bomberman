/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Main.cpp
*/

#include <unistd.h>

#include "Systems.hpp"
#include "Components.hpp"

int main()
{
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(1920, 1080));

	if (device == 0)
		return 1;

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::video::ITexture* background = driver->getTexture("./assets/maxresdefault.jpg");
	irr::video::ITexture* blur = driver->getTexture("./assets/flou.jpg");
	irr::video::ITexture* playWhite = driver->getTexture("./assets/playWhite1.png");
	irr::video::ITexture* exitWhite = driver->getTexture("./assets/exitWhite1.png");

	ecs::system::Create::createBackground(background, ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{255, 255, 255, 255});
	auto blurBackId = ecs::system::Create::createBackground(blur, ecs::component::Rect{0, 0, 1920, 1080}, ecs::component::Color{0, 255, 255, 255});
	auto playWhiteId = ecs::system::Create::createButton(playWhite, ecs::component::Rect{0, 0, 420, 150}, ecs::component::Color{0, 255, 255, 255}, ecs::component::Position{700, 500});
	auto exitWhiteId = ecs::system::Create::createButton(exitWhite, ecs::component::Rect{0, 0, 400, 150}, ecs::component::Color{0, 255, 255, 255}, ecs::component::Position{700, 750});

	while (device->run() && driver) {
		driver->beginScene(true, true, irr::video::SColor(255,120,102,136));
		ecs::system::Render::update(driver);
		ecs::system::Update::update(blurBackId);
		ecs::system::Update::update(playWhiteId);
		ecs::system::Update::update(exitWhiteId);
		driver->endScene();
	}
}
