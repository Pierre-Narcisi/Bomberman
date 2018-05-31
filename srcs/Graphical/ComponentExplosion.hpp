/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#pragma once

#include <irrlicht/irrlicht.h>

namespace ecs::component {
	struct Explosion {
		Explosion(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver) {
			fire_up = smgr->addParticleSystemSceneNode(false);
			fire_left = smgr->addParticleSystemSceneNode(false);
			fire_down = smgr->addParticleSystemSceneNode(false);
			fire_right = smgr->addParticleSystemSceneNode(false);

			irr::scene::IParticleEmitter* em_up = fire_up->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
				irr::core::vector3df(0.0f,0.0f,0.6f),
				8000,10000,
				irr::video::SColor(0,255,255,255),
				irr::video::SColor(0,255,255,255),
				80,200,0,
				irr::core::dimension2df(10.f,10.f),
				irr::core::dimension2df(20.f,20.f));

			irr::scene::IParticleEmitter* em_left = fire_left->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
				irr::core::vector3df(0.6f,0.0f,0.0f),
				8000,10000,
				irr::video::SColor(0,255,255,255),
				irr::video::SColor(0,255,255,255),
				80,200,0,
				irr::core::dimension2df(10.f,10.f),
				irr::core::dimension2df(20.f,20.f));

			irr::scene::IParticleEmitter* em_down = fire_down->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
				irr::core::vector3df(0.0f,0.0f,-0.6f),
				8000,10000,
				irr::video::SColor(0,255,255,255),
				irr::video::SColor(0,255,255,255),
				80,200,0,
				irr::core::dimension2df(10.f,10.f),
				irr::core::dimension2df(20.f,20.f));

			irr::scene::IParticleEmitter* em_right = fire_right->createBoxEmitter(
				irr::core::aabbox3d<irr::f32>(-10,-1,-10,10,0,10),
				irr::core::vector3df(-0.6f,0.0f,0.0f),
				8000,10000,
				irr::video::SColor(0,255,255,255),
				irr::video::SColor(0,255,255,255),
				80,200,0,
				irr::core::dimension2df(10.f,10.f),
				irr::core::dimension2df(20.f,20.f));

			fire_up->setEmitter(em_up);
			fire_left->setEmitter(em_left);
			fire_down->setEmitter(em_down);
			fire_right->setEmitter(em_right);
			em_up->drop();
			em_left->drop();
			em_down->drop();
			em_right->drop();

			irr::scene::IParticleAffector* paf = fire_up->createFadeOutParticleAffector();

			fire_up->addAffector(paf);
			fire_left->addAffector(paf);
			fire_down->addAffector(paf);
			fire_right->addAffector(paf);
			paf->drop();

			fire_up->setPosition(irr::core::vector3df(0,0,0));
			fire_up->setRotation(irr::core::vector3df(0,0,0));
			fire_up->setScale(irr::core::vector3df(2,2,2));
			fire_up->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			fire_up->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			fire_up->setMaterialTexture(0, driver->getTexture("../../assets/fire.bmp"));
			fire_up->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

			fire_left->setPosition(irr::core::vector3df(0,0,0));
			fire_left->setRotation(irr::core::vector3df(0,0,0));
			fire_left->setScale(irr::core::vector3df(2,2,2));
			fire_left->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			fire_left->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			fire_left->setMaterialTexture(0, driver->getTexture("../../assets/fire.bmp"));
			fire_left->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

			fire_down->setPosition(irr::core::vector3df(0,0,0));
			fire_down->setRotation(irr::core::vector3df(0,0,0));
			fire_down->setScale(irr::core::vector3df(2,2,2));
			fire_down->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			fire_down->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			fire_down->setMaterialTexture(0, driver->getTexture("../../assets/fire.bmp"));
			fire_down->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

			fire_right->setPosition(irr::core::vector3df(0,0,0));
			fire_right->setRotation(irr::core::vector3df(0,0,0));
			fire_right->setScale(irr::core::vector3df(2,2,2));
			fire_right->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			fire_right->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
			fire_right->setMaterialTexture(0, driver->getTexture("../../assets/fire.bmp"));
			fire_right->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
		};
		irr::scene::IParticleSystemSceneNode* fire_up;
		irr::scene::IParticleSystemSceneNode* fire_left;
		irr::scene::IParticleSystemSceneNode* fire_down;
		irr::scene::IParticleSystemSceneNode* fire_right;
	};
}
