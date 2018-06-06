/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "ECS/Entity/Entity.hpp"
#include "Game/Game.hpp"

#include "Component/Basics.hpp"
#include "Constructors/BeingConsruct.hpp"
#include "Component/AttributeBomb.hpp"
#include "Component/Stat.hpp"
#include "Component/Map.hpp"
#include "Component/Graphicals.hpp"

#include "System/Create.hpp"

namespace ecs::system {

	irr::scene::IMetaTriangleSelector *Create::createCollision()
	{
		auto &game = indie::Game::get();
		irr::scene::IMetaTriangleSelector *worldSel = game.getSmgr()->createMetaTriangleSelector();
		entity::Filter<component::UnanimatedObject> fl;
		auto &map = component::Manager<component::UnanimatedObject>::get();
		irr::scene::ITriangleSelector *sel1;

		for (auto id : fl.list) {
			sel1 = game.getSmgr()->createTriangleSelectorFromBoundingBox(map[id]._node);
			worldSel->addTriangleSelector(sel1);
			// worldSel->removeTriangleSelector(sel1);
		}
		return (worldSel);
	}

	entity::Id Create::createWall(irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id);
		component::Constructors::UnanimatedObject(id, "./assets/cobblestone.jpg", pos);
		component::Manager<component::Type>::get().addComponentForEntity(id);
		component::Constructors::Type(id, component::Type::Enum::Wall);

		return id;
	}

	entity::Id Create::createDeletableWall(irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id);
		component::Constructors::UnanimatedObject(id, "./assets/wooddencreate.png", pos);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);
		component::Manager<component::Type>::get().addComponentForEntity(id);
		component::Constructors::Type(id, component::Type::Enum::Wall);

		return id;
	}

	entity::Id Create::createPlayer(std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
	{
		auto &game = indie::Game::get();
		auto	id = entity::Manager::get().newEntity();
		bool	_controller = false;
		irr::core::array<irr::SJoystickInfo> joystickInfo;
		game.getDevice()->activateJoysticks(joystickInfo);
		irr::u32 i;

		for (i = 0; i < joystickInfo.size(); i++)
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0)
				_controller = true;

		// component::Manager<component::Being>::get().addComponentForEntity(id, mesh, texture, pos);
		// component::Manager<component::Stat>::get().addComponentForEntity();
		component::Manager<component::Being>::get().addComponentForEntity(id);
		ecs::component::Constructors::Being(id, mesh, texture, pos);

		auto selector = ecs::system::Create::createCollision();
		irr::scene::ISceneNodeAnimator *anim = game.getSmgr()->createCollisionResponseAnimator(selector,
													component::Manager<component::Being>::get()[id]._node,
													(component::Manager<component::Being>::get()[id]._node->getBoundingBox().MaxEdge
													- component::Manager<component::Being>::get()[id]._node->getBoundingBox().MinEdge),
													irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0));
		component::Manager<component::Being>::get()[id]._node->addAnimator(anim);
		selector->drop();
		anim->drop();

		for (i = 0; i < joystickInfo.size(); i++) {
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0) {
				_controller = true;
				break;
			}
		}

		if (_controller) {
			component::Manager<component::Controller360>::get().addComponentForEntity(id);
			component::Constructors::Controller360(id, joystickInfo[i].Joystick);
		} else {
			component::Manager<component::Keyboard>::get().addComponentForEntity(id);
			component::Constructors::Keyboard(id,
							  irr::EKEY_CODE::KEY_KEY_Z,
							  irr::EKEY_CODE::KEY_KEY_Q,
							  irr::EKEY_CODE::KEY_KEY_S,
							  irr::EKEY_CODE::KEY_KEY_D,
							  irr::EKEY_CODE::KEY_SPACE,
							  irr::EKEY_CODE::KEY_LCONTROL,
							  irr::EKEY_CODE::KEY_LSHIFT);
		}

		component::Manager<component::Stat>::get().addComponentForEntity(id);

		component::Manager<component::Camera>::get().addComponentForEntity(id);
		component::Constructors::Camera(id);

		return id;
	}

	entity::Id Create::createBomb(entity::Id ID, irr::core::vector2di pos)
	{
		auto &game = indie::Game::get();

		// component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Bomb);
		// component::Manager<component::Position>::get().addComponentForEntity(id, pos.X, pos.Y);
		// component::Manager<component::Attributes>::get().addComponentForEntity(id, (long double) time(NULL) + 2, range, component::Attributes::Enum::Default);
		// component::Manager<component::Mesh>::get().addComponentForEntity(id, game.getSmgr()->addAnimatedMeshSceneNode(game.getSmgr()->getMesh("../../assets/bomb.obj")));
		// component::Manager<component::Mesh>::get()[id].mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		// component::Manager<component::Mesh>::get()[id].mesh->setPosition({static_cast<float>(pos.X), 0, static_cast<float>(pos.Y)});
		// component::Manager<component::Mesh>::get()[id].mesh->setScale({25, 25, 25});
		// component::Manager<component::Deletable>::get().addComponentForEntity(id);
		// return id;
		entity::Filter<component::Type, component::Mesh> fl;
		auto &mesh = component::Manager<component::Mesh>::get();
		auto &type = component::Manager<component::Type>::get();
		bool existing = true;

		if (component::Manager<component::Stat>::get()[ID].bombMax == 0)
			existing = false;

		for (auto &id : fl.list) {
			if (pos.X == mesh[id].mesh->getPosition().X && pos.Y == mesh[id].mesh->getPosition().Z)
				existing = false;
		}

		if (existing) {
			auto id = entity::Manager::get().newEntity();
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Bomb);
			component::Manager<component::Position>::get().addComponentForEntity(id, pos.X, pos.Y);
			component::Manager<component::Attributes>::get().addComponentForEntity(id, (long double) time(NULL) + 2, component::Manager<component::Stat>::get()[ID].range, component::Attributes::Enum::Default, ID);
			component::Manager<component::Mesh>::get().addComponentForEntity(id, game.getSmgr()->addAnimatedMeshSceneNode(game.getSmgr()->getMesh("./assets/bomb.obj")));
			component::Manager<component::Mesh>::get()[id].mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			component::Manager<component::Mesh>::get()[id].mesh->setPosition({static_cast<float>(pos.X), 0, static_cast<float>(pos.Y)});
			component::Manager<component::Mesh>::get()[id].mesh->setScale({25, 25, 25});
			component::Manager<component::Deletable>::get().addComponentForEntity(id);
			component::Manager<component::Stat>::get()[ID].bombMax -= 1;
			return id;
		}
		return static_cast<unsigned int>(-1);
	}

	void Create::createExplosion(entity::Id ID, component::Position pos) {
		auto &game = indie::Game::get();
		auto id = entity::Manager::get().newEntity();

		component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::Explosion);
		component::Manager<component::Position>::get().addComponentForEntity(id, pos.x, pos.y);
		component::Manager<component::Attributes>::get().addComponentForEntity(id, (long double) time(NULL) + 1,
										       component::Manager<component::Attributes>::get()[ID].range,
										       component::Attributes::Enum::Default);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);

		component::Manager<component::ParticleSystem>::get().addComponentForEntity(id,
											   game.getSmgr()->addParticleSystemSceneNode(
												   false),
											   game.getSmgr()->addParticleSystemSceneNode(
												   false),
											   game.getSmgr()->addParticleSystemSceneNode(
												   false),
											   game.getSmgr()->addParticleSystemSceneNode(
												   false));
		auto &ParticleSystemManager = component::Manager<component::ParticleSystem>::get();

		component::Manager<component::ParticleEmitter>::get().addComponentForEntity(id);
		auto &ParticleEmitterManager = component::Manager<component::ParticleEmitter>::get();

		component::Manager<component::ParticleAffector>::get().addComponentForEntity(id);
		auto &ParticleAffectorManager = component::Manager<component::ParticleAffector>::get();







		int rangeLeft = 0;
		int rangeRight = 0;
		int rangeUp = 0;
		int rangeDown = 0;

		entity::Filter<component::Map> fl;
		for (auto &entit : fl.list) {
			auto &map = component::Manager<component::Map>::get()[entit].map;

			std::cout << pos.x / 100 << std::endl;
			std::cout << pos.y / 100 << std::endl;

			std::cout << "OUI: " << map[(pos.y / 100) + 1][(pos.x / 100) + 1] << std::endl;

			for (; map[(pos.y / 100) + 1 - rangeLeft][(pos.x / 100) + 1] != 1 && map[(pos.y / 100) + 1 - rangeLeft][(pos.x / 100) + 1] != 2; rangeLeft++) {
				std::cout << "1" << std::endl;
			}
			for (; map[(pos.y / 100) + 1 + rangeRight][(pos.x / 100) + 1] != 1 && map[(pos.y / 100) + 1 + rangeRight][(pos.x / 100) + 1] != 2; rangeRight++) {
				std::cout << "2" << std::endl;
			}
			for (; map[(pos.y / 100) + 1][(pos.x / 100) + 1 + rangeUp] != 1 && map[(pos.y / 100) + 1][(pos.x / 100) + 1 + rangeUp] != 2; rangeUp++) {
				std::cout << "3" << std::endl;
			}
			for (; map[(pos.y / 100) + 1][(pos.x / 100) + 1 - rangeDown] != 1 && map[(pos.y / 100) + 1][(pos.x / 100) + 1 - rangeDown] != 2; rangeDown++) {
				std::cout << "4" << std::endl;
			}

			std::cout << rangeLeft << std::endl;
			std::cout << rangeRight << std::endl;
			std::cout << rangeUp << std::endl;
			std::cout << rangeDown << std::endl;

		}









		ParticleEmitterManager[id].PEUp = ParticleSystemManager[id].PSUp->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(-10, -1, -10, 10, 0, 10),
			irr::core::vector3df(0.0f,0.0f,0.6f),
			8000,10000,
			irr::video::SColor(0,255,255,255),
			irr::video::SColor(0,255,255,255),
			80 + (150 * (rangeUp - 1)), 200 + (150 * (rangeUp - 1)),0,
			irr::core::dimension2df(10.f,10.f),
			irr::core::dimension2df(20.f,20.f)
		);

		ParticleEmitterManager[id].PEDown = ParticleSystemManager[id].PSDown->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
			irr::core::vector3df(0.0f,0.0f,-0.6f),
			8000,10000,
			irr::video::SColor(0,255,255,255),
			irr::video::SColor(0,255,255,255),
			80 + (150 * (rangeDown - 1)), 200 + (150 * (rangeDown - 1)),0,
			irr::core::dimension2df(10.f,10.f),
			irr::core::dimension2df(20.f,20.f)
		);

		ParticleEmitterManager[id].PELeft = ParticleSystemManager[id].PSLeft->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
			irr::core::vector3df(0.6f,0.0f,0.0f),
			8000,10000,
			irr::video::SColor(0,255,255,255),
			irr::video::SColor(0,255,255,255),
			80 + (150 * (rangeRight - 1)), 200 + (150 * (rangeRight - 1)),0,
			irr::core::dimension2df(10.f,10.f),
			irr::core::dimension2df(20.f,20.f)
		);

		ParticleEmitterManager[id].PERight = ParticleSystemManager[id].PSRight->createBoxEmitter(
			irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
			irr::core::vector3df(-0.6f,0.0f,0.0f),
			8000,10000,
			irr::video::SColor(0,255,255,255),
			irr::video::SColor(0,255,255,255),
			80 + (150 * (rangeLeft - 1)), 200 + (150 * (rangeLeft - 1)),0,
			irr::core::dimension2df(10.f,10.f),
			irr::core::dimension2df(20.f,20.f)
		);

		ParticleSystemManager[id].PSUp->setEmitter(ParticleEmitterManager[id].PEUp);
		ParticleSystemManager[id].PSDown->setEmitter(ParticleEmitterManager[id].PEDown);
		ParticleSystemManager[id].PSLeft->setEmitter(ParticleEmitterManager[id].PELeft);
		ParticleSystemManager[id].PSRight->setEmitter(ParticleEmitterManager[id].PERight);

		ParticleAffectorManager[id].PAUp = ParticleSystemManager[id].PSUp->createFadeOutParticleAffector();
		ParticleAffectorManager[id].PADown = ParticleSystemManager[id].PSDown->createFadeOutParticleAffector();
		ParticleAffectorManager[id].PALeft = ParticleSystemManager[id].PSLeft->createFadeOutParticleAffector();
		ParticleAffectorManager[id].PARight = ParticleSystemManager[id].PSRight->createFadeOutParticleAffector();

		ParticleSystemManager[id].PSUp->setPosition(irr::core::vector3df(pos.x,0,pos.y));
		ParticleSystemManager[id].PSUp->setScale(irr::core::vector3df(2,2,2));
		ParticleSystemManager[id].PSUp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		ParticleSystemManager[id].PSUp->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
		ParticleSystemManager[id].PSUp->setMaterialTexture(0, game.getDriver()->getTexture("./assets/fire.bmp"));
		ParticleSystemManager[id].PSUp->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

		ParticleSystemManager[id].PSDown->setPosition(irr::core::vector3df(pos.x,0,pos.y));
		ParticleSystemManager[id].PSDown->setScale(irr::core::vector3df(2,2,2));
		ParticleSystemManager[id].PSDown->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		ParticleSystemManager[id].PSDown->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
		ParticleSystemManager[id].PSDown->setMaterialTexture(0, game.getDriver()->getTexture("./assets/fire.bmp"));
		ParticleSystemManager[id].PSDown->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

		ParticleSystemManager[id].PSLeft->setPosition(irr::core::vector3df(pos.x,0,pos.y));
		ParticleSystemManager[id].PSLeft->setScale(irr::core::vector3df(2,2,2));
		ParticleSystemManager[id].PSLeft->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		ParticleSystemManager[id].PSLeft->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
		ParticleSystemManager[id].PSLeft->setMaterialTexture(0, game.getDriver()->getTexture("./assets/fire.bmp"));
		ParticleSystemManager[id].PSLeft->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

		ParticleSystemManager[id].PSRight->setPosition(irr::core::vector3df(pos.x,0,pos.y));
		ParticleSystemManager[id].PSRight->setScale(irr::core::vector3df(2,2,2));
		ParticleSystemManager[id].PSRight->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		ParticleSystemManager[id].PSRight->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
		ParticleSystemManager[id].PSRight->setMaterialTexture(0, game.getDriver()->getTexture("./assets/fire.bmp"));
		ParticleSystemManager[id].PSRight->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	}

	entity::Id Create::createMap(std::vector<std::vector<int>> map) {
		auto id = entity::Manager::get().newEntity();

		component::Manager<component::Map>::get().addComponentForEntity(id, map);

		return id;
	}

}
