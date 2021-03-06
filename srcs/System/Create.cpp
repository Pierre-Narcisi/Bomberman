/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include <random>
#include "Constructors/Destructors.hpp"
#include "Settings/Inputs.hpp"
#include "ECS/Entity/Entity.hpp"
#include "ECS/Component/Component.hpp"
#include "Game/Game.hpp"

#include "Component/Basics.hpp"
#include "Constructors/BeingConsruct.hpp"
#include "Component/AttributeBomb.hpp"
#include "Component/Stat.hpp"
#include "Component/Map.hpp"
#include "Component/Graphicals.hpp"

#include "System/Create.hpp"

namespace ecs { namespace system {

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
			//worldSel->removeTriangleSelector(sel1);
		}
		return (worldSel);
	}

	entity::Id Create::createWall(irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id);
		component::Constructors::UnanimatedObject(id, "./assets/wall.jpg", pos);
		component::Manager<component::Type>::get().addComponentForEntity(id);
		component::Constructors::Type(id, component::Type::Enum::Wall);

		return id;
	}

	entity::Id Create::createDeletableWall(irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id);
		component::Constructors::UnanimatedObject(id, "./assets/crate.jpg", pos);
		component::Manager<component::Deletable>::get().addComponentForEntity(id);
		component::Manager<component::Type>::get().addComponentForEntity(id);
		component::Constructors::Type(id, component::Type::Enum::Wall);

		return id;
	}

	entity::Id Create::createAi(std::string const &mesh, std::string const &texture, irr::core::vector2df const &pos)
	{
		auto &game = indie::Game::get();
		auto	id = entity::Manager::get().newEntity();
		irr::u32 i;

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

		component::Manager<component::Stat>::get().addComponentForEntity(id);
		component::Manager<component::Ai>::get().addComponentForEntity(id);
		auto Ai = component::Manager<component::Ai>::get()[id];
		Ai.goal.Z = 100;
		Ai.goal.X = 100;
		Ai.free = 0;
		Ai.since = 0;
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

		for (i = 0; i < joystickInfo.size(); i++) {
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0) {
				entity::Filter<component::Input> list;
				auto &in = component::Manager<component::Input>::get();
				bool used = false;
				for (auto &ID : list.list) {
					if (in[ID].mode == ecs::component::Input::Mode::Controller && in[ID].controllerId == joystickInfo[i].Joystick)
						used = true;
				}
				if (used == false)
					_controller = true;
			}

		}

		component::Manager<component::Being>::get().addComponentForEntity(id);
		ecs::component::Constructors::Being(id, mesh, texture, pos);

		auto selector = ecs::system::Create::createCollision();
		auto max = component::Manager<component::Being>::get()[id]._node->getBoundingBox().MaxEdge;
		auto min = component::Manager<component::Being>::get()[id]._node->getBoundingBox().MinEdge;
		max.Z *= 15;
		max.X *= 15;
		max.Y *= 15;
		min.Z *= 15;
		min.X *= 15;
		min.Y *= 15;
		irr::scene::ISceneNodeAnimator *anim = game.getSmgr()->createCollisionResponseAnimator(selector,
												       component::Manager<component::Being>::get()[id]._node,
												       (max - min),
												       irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0));
		component::Manager<component::Being>::get()[id]._node->addAnimator(anim);
		selector->drop();
		anim->drop();

		for (i = 0; i < joystickInfo.size(); i++) {
			if (strcmp(joystickInfo[i].Name.c_str(), "Microsoft X-Box 360 pad") == 0) {
				entity::Filter<component::Input> list;
				auto &in = component::Manager<component::Input>::get();
				bool used = false;
				for (auto &ID : list.list) {
					if (in[ID].mode == ecs::component::Input::Mode::Controller && in[ID].controllerId == joystickInfo[i].Joystick)
						used = true;
				}
				if (used == false) {
					_controller = true;
					break;
				}
			}
		}


		if (_controller) {
			component::Manager<component::Input>::get().addComponentForEntity(id);
			component::Constructors::Input(id, joystickInfo[i].Joystick);
		} else {
			component::Manager<component::Input>::get().addComponentForEntity(id);
			component::Constructors::Input(id);
		}

		component::Manager<component::Stat>::get().addComponentForEntity(id);

		component::Manager<component::Camera>::get().addComponentForEntity(id);
		component::Constructors::Camera(id);

		return id;
	}

	entity::Id Create::createBomb(entity::Id ID, irr::core::vector2di pos)
	{
		auto &game = indie::Game::get();
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
											   game.getSmgr()->addParticleSystemSceneNode(false),
											   game.getSmgr()->addParticleSystemSceneNode(false),
											   game.getSmgr()->addParticleSystemSceneNode(false),
											   game.getSmgr()->addParticleSystemSceneNode(false));
		auto &ParticleSystemManager = component::Manager<component::ParticleSystem>::get();

		component::Manager<component::ParticleEmitter>::get().addComponentForEntity(id);
		auto &ParticleEmitterManager = component::Manager<component::ParticleEmitter>::get();

		component::Manager<component::ParticleAffector>::get().addComponentForEntity(id);
		auto &ParticleAffectorManager = component::Manager<component::ParticleAffector>::get();

		auto &POS = component::Manager<component::Position>::get();
		auto &TYPE = component::Manager<component::Type>::get();




		//Getting Bomb range

		int rangeLeft = 0;
		int rangeRight = 0;
		int rangeUp = 0;
		int rangeDown = 0;


		entity::Filter<component::UnanimatedObject, component::Deletable> walls;
		auto &wall = component::Manager<component::UnanimatedObject>::get();
		entity::Filter<component::Map> fl;
		for (auto &entit : fl.list) {
			auto &map = component::Manager<component::Map>::get()[entit].map;


			pos.x = pos.x / 100;
			pos.y = pos.y / 100;

			std::cout << "x:" << pos.x << " y:" << pos.y << std::endl;
			std::cout << map[pos.y][pos.x] << std::endl;

			for (rangeLeft = 0; rangeLeft < component::Manager<component::Attributes>::get()[ID].range; ++rangeLeft) {
				if (map[pos.y][pos.x - (rangeLeft + 1)] == 1) {
					break;
				} else if (map[pos.y][pos.x - (rangeLeft + 1)] == 2) {
					rangeLeft++;
					map[pos.y][pos.x - (rangeLeft + 1)] = 0;
					for (auto &Id: walls.list) {
						if (wall[Id]._node->getPosition().X/100 == pos.x - (rangeLeft) && wall[Id]._node->getPosition().Z/100 == pos.y)
							component::Destructors::UnanimatedObject(Id);
					}
					break;
				} else if (map[pos.y][pos.x - (rangeLeft + 1)] == 3) {
					entity::Filter<component::Position, component::Type>	poty;
					for (auto &bomb : poty.list){
						if (POS[bomb].x == (pos.x - (rangeLeft + 1)) * 100 && POS[bomb].y == pos.y * 100 && TYPE[bomb].t == ecs::component::Type::Enum::Bomb)
							component::Manager<component::Attributes>::get()[bomb].explode = true;
					}
				}
			}

			for (rangeRight = 0; rangeRight < component::Manager<component::Attributes>::get()[ID].range; ++rangeRight) {
				if (map[pos.y][pos.x + (rangeRight + 1)] == 1) {
					break;
				} else if (map[pos.y][pos.x + (rangeRight + 1)] == 2) {
					rangeRight++;
					map[pos.y][pos.x + (rangeRight + 1)] = 0;
					for (auto &Id: walls.list) {
						if (wall[Id]._node->getPosition().X/100 == pos.x + (rangeRight) && wall[Id]._node->getPosition().Z/100 == pos.y)
							component::Destructors::UnanimatedObject(Id);
					}
					break;
				} else if (map[pos.y][pos.x + (rangeRight + 1)] == 3) {
					entity::Filter<component::Position, component::Type>	poty;
					for (auto &bomb : poty.list){
						if (POS[bomb].x == (pos.x + (rangeRight + 1)) * 100 && POS[bomb].y == pos.y * 100 && TYPE[bomb].t == ecs::component::Type::Enum::Bomb)
							component::Manager<component::Attributes>::get()[bomb].explode = true;
					}
				}
			}

			for (rangeUp = 0; rangeUp < component::Manager<component::Attributes>::get()[ID].range; ++rangeUp) {
				if (map[pos.y + (rangeUp + 1)][pos.x] == 1) {
					break;
				} else if (map[pos.y + (rangeUp + 1)][pos.x] == 2) {
					rangeUp++;
					map[pos.y + (rangeUp + 1)][pos.x] = 0;
					for (auto &Id: walls.list) {
						if (wall[Id]._node->getPosition().X/100 == pos.x && wall[Id]._node->getPosition().Z/100 == pos.y + (rangeUp))
							component::Destructors::UnanimatedObject(Id);
					}
					break;
				} else if (map[pos.y + (rangeUp + 1)][pos.x] == 3) {
					entity::Filter<component::Position, component::Type>	poty;
					for (auto &bomb : poty.list){
						if (POS[bomb].x == pos.x * 100 && POS[bomb].y == (pos.y + (rangeUp + 1)) * 100 && TYPE[bomb].t == ecs::component::Type::Enum::Bomb)
							component::Manager<component::Attributes>::get()[bomb].explode = true;
					}
				}
			}

			for (rangeDown = 0; rangeDown < component::Manager<component::Attributes>::get()[ID].range; ++rangeDown) {
				if (map[pos.y - (rangeDown + 1)][pos.x] == 1) {
					break;
				} else if (map[pos.y - (rangeDown + 1)][pos.x] == 2) {
					rangeDown++;
					map[pos.y - (rangeDown + 1)][pos.x] = 0;
					for (auto &Id: walls.list) {
						if (wall[Id]._node->getPosition().X/100 == pos.x && wall[Id]._node->getPosition().Z/100 == pos.y - (rangeDown))
							component::Destructors::UnanimatedObject(Id);
					}
					break;
				} else if (map[pos.y - (rangeDown + 1)][pos.x] == 3) {
					entity::Filter<component::Position, component::Type>	poty;
					for (auto &bomb : poty.list){
						if (POS[bomb].x == pos.x * 100 && POS[bomb].y == (pos.y - (rangeDown + 1)) * 100 && TYPE[bomb].t == ecs::component::Type::Enum::Bomb)
							component::Manager<component::Attributes>::get()[bomb].explode = true;
					}
				}
			}
			pos.x = pos.x * 100;
			pos.y = pos.y * 100;
		}


		// Killing Beings in range

		entity::Filter<component::Being, component::Input> beings;
		auto &being = component::Manager<component::Being>::get();

		for (auto &me : beings.list) {
			if (being[me]._node->getPosition().X > pos.x - rangeLeft * 100 - 50 && being[me]._node->getPosition().X < pos.x + rangeRight * 100 + 50) {
				if (being[me]._node->getPosition().Z > pos.y - 50 && being[me]._node->getPosition().Z < pos.y + 50) {
					being[me]._node->setVisible(0);
					being[me]._node->setPosition(irr::core::vector3df(0, 500, 500));
					ecs::component::Manager<component::Input>::get().removeComponentForEntity(me);
				}
			}
			if (being[me]._node->getPosition().Z > pos.y - rangeUp * 100 - 50 && being[me]._node->getPosition().Z < pos.y + rangeDown * 100 + 50) {
				if (being[me]._node->getPosition().X > pos.x - 50 && being[me]._node->getPosition().X < pos.x + 50) {
					being[me]._node->setVisible(0);
					being[me]._node->setPosition(irr::core::vector3df(0, 500, 500));
					ecs::component::Manager<component::Input>::get().removeComponentForEntity(me);
				}
			}
		}


		entity::Filter<component::Being, component::Ai> ais;
		auto &ai = component::Manager<component::Being>::get();

		for (auto &me : ais.list) {
			if (ai[me]._node->getPosition().X > pos.x - rangeLeft * 100 - 50 && ai[me]._node->getPosition().X < pos.x + rangeRight * 100 + 50) {
				if (ai[me]._node->getPosition().Z > pos.y - 50 && ai[me]._node->getPosition().Z < pos.y + 50) {
					ai[me]._node->setVisible(0);
					ai[me]._node->setPosition(irr::core::vector3df(0, 500, 500));
					ecs::component::Manager<component::Ai>::get().removeComponentForEntity(me);
				}
			}
			if (ai[me]._node->getPosition().Z > pos.y - rangeUp * 100 - 50 && ai[me]._node->getPosition().Z < pos.y + rangeDown * 100 + 50) {
				if (ai[me]._node->getPosition().X > pos.x - 50 && ai[me]._node->getPosition().X < pos.x + 50) {
					ai[me]._node->setVisible(0);
					ai[me]._node->setPosition(irr::core::vector3df(0, 500, 500));
					ecs::component::Manager<component::Ai>::get().removeComponentForEntity(me);
				}
			}
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

	entity::Id Create::createGround(irr::core::vector2df pos)
	{
		auto	id = entity::Manager::get().newEntity();

		component::Manager<component::MeshStatic>::get().addComponentForEntity(id);
		component::Constructors::MeshStatic(id, "./assets/bloodground.png", pos);

		return id;
	}

	entity::Id Create::createBonus(component::Position pos) {

		auto id = entity::Manager::get().newEntity();

		component::Manager<component::Position>::get().addComponentForEntity(id, pos);
		component::Manager<component::UnanimatedObject>::get().addComponentForEntity(id);
		std::uniform_int_distribution<int> distribution(0, 3);
		std::random_device rd;
		std::mt19937 engine(rd());

		int ran = distribution(engine);
		if (ran == 0) {
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::BonusBomb);
			component::Constructors::Bonus(id, "./assets/BombBonus.png", {static_cast<float>(pos.x), static_cast<float>(pos.y)});
		} else if (ran == 1) {
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::BonusRange);
			component::Constructors::Bonus(id, "./assets/RangeBonus.png", {static_cast<float>(pos.x), static_cast<float>(pos.y)});
		} else {
			component::Manager<component::Type>::get().addComponentForEntity(id, component::Type::Enum::BonusSpeed);
			component::Constructors::Bonus(id, "./assets/SpeedBonus.png", {static_cast<float>(pos.x), static_cast<float>(pos.y)});
		}
		component::Manager<component::Position>::get().addComponentForEntity(id, pos);

		return id;
	}

}}
