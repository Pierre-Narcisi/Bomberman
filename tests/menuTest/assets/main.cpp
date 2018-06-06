#include <irrlicht/irrlicht.h>
#include "irrlicht/driverChoice.h"

using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

int main()
{
	int pass = 0;

	IrrlichtDevice *device = createDevice(irr::video::EDT_OPENGL,
		core::dimension2d<u32>(1920, 1080));

	if (device == 0)
		return 1;

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	video::IVideoDriver* driver = device->getVideoDriver();
	video::ITexture* images = driver->getTexture("./assets/maxresdefault.jpg");
	video::ITexture* blur = driver->getTexture("./assets/flou.jpg");
	video::ITexture* exitWhite = driver->getTexture("./assets/exitWhite1.png");
	video::ITexture* exitBlack = driver->getTexture("./assets/exitBlack1.png");
	video::ITexture* playWhite = driver->getTexture("./assets/playWhite1.png");
	video::ITexture* playBlack = driver->getTexture("./assets/playBlack1.png");

	while(device->run() && driver) {
		if (device->isWindowActive()) {
				u32 time = device->getTimer()->getTime();

				driver->beginScene(true, true, video::SColor(255,120,102,136));

				driver->draw2DImage(images, core::position2d<s32>(0,0),
						core::rect<s32>(0, 0, 1920, 1080), 0,
						video::SColor(255, 255, 255, 255), true);

				driver->draw2DImage(blur, core::position2d<s32>(0,0),
						core::rect<s32>(0, 0, 1920, 1080), 0,
						video::SColor(pass, 255, 255, 255), true);
				if (pass < 252)
					pass += 2;

				driver->draw2DImage(exitWhite, core::position2d<s32>(700, 750),
						core::rect<s32>(0, 0, 400, 150), 0,
						video::SColor(pass, 255, 255, 255), true);

				// driver->draw2DImage(, core::position2d<s32>(0,0),
				// 		core::rect<s32>(0, 0, 1920, 1080), 0,
				// 		video::SColor(pass, 255, 255, 255), true);

				driver->draw2DImage(playWhite, core::position2d<s32>(700, 500),
						core::rect<s32>(0, 0, 420, 150), 0,
						video::SColor(pass, 255, 255, 255), true);

				// driver->draw2DImage(blur, core::position2d<s32>(0,0),
				// 		core::rect<s32>(0, 0, 1920, 1080), 0,
				// 		video::SColor(pass, 255, 255, 255), true);

				driver->endScene();
		}
	}
	device->drop();
	return 0;
}
