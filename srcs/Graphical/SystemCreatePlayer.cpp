/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemCreate.hpp"
#include "ComponentExplosion.hpp"

namespace ecs::system {

	entity::Id Create::createPlayer(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
	{
		auto	id = entity::Manager::get().newEntity();
		bool	_controller = false;
		irr::core::array<irr::SJoystickInfo> joystickInfo;
		device->activateJoysticks(joystickInfo);
		irr::u32 i;

		for (i = 0; i < joystickInfo.size(); i++)
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0)
				_controller = true;

		component::Manager<component::Being>::get().addComponentForEntity(id, device, driver, smgr, mesh, texture, pos);

		auto selector = ecs::system::Create::createMap(smgr);
		irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(selector, component::Manager<component::Being>::get()[id]._node, (component::Manager<component::Being>::get()[id]._node->getBoundingBox().MaxEdge - component::Manager<component::Being>::get()[id]._node->getBoundingBox().MinEdge), irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0));
		component::Manager<component::Being>::get()[id]._node->addAnimator(anim);
		selector->drop();
		anim->drop();

		for (i = 0; i < joystickInfo.size(); i++) {
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0) {
				_controller = true;
				break;
			}
		}

		component::Manager<component::Explosion>::get().addComponentForEntity(id, smgr, driver);

		if (_controller)
			component::Manager<component::Controller360>::get().addComponentForEntity(id, joystickInfo[i].Joystick);
		else
			component::Manager<component::Keyboard>::get().addComponentForEntity(id,
										irr::EKEY_CODE::KEY_KEY_Z,
										irr::EKEY_CODE::KEY_KEY_Q,
										irr::EKEY_CODE::KEY_KEY_S,
										irr::EKEY_CODE::KEY_KEY_D,
										irr::EKEY_CODE::KEY_SPACE,
										irr::EKEY_CODE::KEY_LCONTROL,
										irr::EKEY_CODE::KEY_LSHIFT);
		component::Manager<component::Camera>::get().addComponentForEntity(id, smgr, id);

		return id;
	}

}
