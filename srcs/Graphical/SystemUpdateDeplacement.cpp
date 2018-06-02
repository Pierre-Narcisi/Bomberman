/*
** EPITECH PROJECT, 2021
** Client
** File description:
** Created by seb,
*/

#include "SystemUpdate.hpp"

namespace ecs::system {
	void Update::Deplacement() {
		entity::Filter<component::Keyboard, component::Being> fl;
		entity::Filter<component::Controller360, component::Being> list;
		entity::Filter<component::Camera, component::Being> player;

		auto &key = component::Manager<component::Keyboard>::get();
		auto &being = component::Manager<component::Being>::get();
		auto &control = component::Manager<component::Controller360>::get();
		auto &camera = component::Manager<component::Camera>::get();
		irr::f32 deltatime;
		irr::core::vector3df pos;
		irr::f32 speed = 300.f;
		float rot;
		bool moving;

		for(auto id : player.list) {
			pos = being[id]._node->getPosition();
			camera[id]._camera->setPosition(irr::core::vector3df(pos.X, pos.Y + 250, pos.Z - 250));
			camera[id]._camera->setTarget(pos);
		}

		for (auto id : fl.list) {
			rot = being[id]._rotation;
			moving = key[id].actions["up"].state || key[id].actions["down"].state || key[id].actions["left"].state || key[id].actions["right"].state;
			deltatime = static_cast<irr::f32>((being[id]._device->getTimer()->getTime() - being[id]._then) / 1000.f);
			being[id]._then = being[id]._device->getTimer()->getTime();

			// Set Rotation
			if (key[id].actions["up"].state)
				rot = 270;
			else if (key[id].actions["down"].state)
				rot = 90;
			if (key[id].actions["left"].state) {
				if (rot == 270)
					rot = 225;
				else if (rot == 90)
					rot = 135;
				else
					rot = 180;
			} else if (key[id].actions["right"].state) {
				if (rot == 270)
					rot = 315;
				else if (rot == 90)
					rot = 45;
				else
					rot = 0;
			}

			being[id]._node->setRotation(irr::core::vector3df(0, rot, 0));

			// Set Speed

			if (key[id].actions["crouch"].state)
				speed = speed / 2;
			if (key[id].actions["sprint"].state)
				speed = speed * 2;

			// Set Animation
			if (moving == 0) {
				if (key[id].actions["crouch"].state && being[id]._lastMov != irr::scene::EMAT_CROUCH_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
					being[id]._lastMov = irr::scene::EMAT_CROUCH_STAND;
				}
				else if (key[id].actions["sprint"].state && being[id]._lastMov != irr::scene::EMAT_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
					being[id]._lastMov = irr::scene::EMAT_STAND;
				} else if (key[id].actions["crouch"].state == 0 && key[id].actions["sprint"].state == 0 && being[id]._lastMov != irr::scene::EMAT_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
					being[id]._lastMov = irr::scene::EMAT_STAND;
				}
			} else {
				if (key[id].actions["crouch"].state && being[id]._lastMov != irr::scene::EMAT_CROUCH_WALK) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_WALK);
					being[id]._lastMov = irr::scene::EMAT_CROUCH_WALK;
				}
				else if (key[id].actions["sprint"].state && being[id]._lastMov != irr::scene::EMAT_RUN) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
					being[id]._lastMov = irr::scene::EMAT_RUN;
				} else if (key[id].actions["crouch"].state == 0 && key[id].actions["sprint"].state == 0 && being[id]._lastMov != irr::scene::EMAT_RUN) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
					being[id]._lastMov = irr::scene::EMAT_RUN;
				}

				being[id]._rotation = rot;
				pos = being[id]._node->getPosition();
				pos.X = pos.X + static_cast<float>(cos(rot * M_PI / 180)) * speed * deltatime;
				pos.Z = pos.Z - static_cast<float>(sin(rot * M_PI / 180)) * speed * deltatime;
				being[id]._node->setPosition(pos);
			}
		}

		for (auto id : list.list) {
			const irr::f32 DEAD_ZONE = 0.2f;
			deltatime = static_cast<irr::f32>((being[id]._device->getTimer()->getTime() - being[id]._then) / 1000.f);
			being[id]._then = being[id]._device->getTimer()->getTime();

			irr::f32 rotHorizontal =
				(irr::f32)control[id].left.horizonal / 32767.f;
			if(fabs(rotHorizontal) < DEAD_ZONE)
				rotHorizontal = 0.f;

			irr::f32 rotVertical =
				(irr::f32)control[id].left.vertical / -32767.f;
			if(fabs(rotVertical) < DEAD_ZONE)
				rotVertical = 0.f;

			if (rotHorizontal >= 0) {
				if (rotVertical >= 0)
					rot = 360 - static_cast<float>(atan(rotVertical/rotHorizontal) * (180 /M_PI));
				else
					rot = -static_cast<float>(atan((rotVertical)/rotHorizontal) * (180 /M_PI));
			} else {
				if (rotVertical >= 0)
					rot = 180 - static_cast<float>(atan(rotVertical/(rotHorizontal)) * (180 /M_PI));
				else
					rot = 180 - static_cast<float>(atan((rotVertical)/(rotHorizontal)) * (180 /M_PI));
			}

			if (rotHorizontal == 0 && rotVertical == 0)
				rot = being[id]._rotation;
			else
				being[id]._rotation = rot;

			being[id]._node->setRotation(irr::core::vector3df(0, rot, 0));

			// Set Speed
			if ((control[id].buttons >> 1 & 1))
				speed = speed / 2;
			if ((control[id].buttons >> 9 & 1))
				speed = speed * 2;

			// Set Animation
			if (rotHorizontal == 0 && rotVertical == 0) {
				if ((control[id].buttons >> 1 & 1) && being[id]._lastMov != irr::scene::EMAT_CROUCH_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
					being[id]._lastMov = irr::scene::EMAT_CROUCH_STAND;
				}
				else if ((control[id].buttons >> 9 & 1) && being[id]._lastMov != irr::scene::EMAT_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
					being[id]._lastMov = irr::scene::EMAT_STAND;
				} else if ((control[id].buttons >> 9 & 1) == 0 && (control[id].buttons >> 1 & 1) == 0 && being[id]._lastMov != irr::scene::EMAT_STAND) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_STAND);
					being[id]._lastMov = irr::scene::EMAT_STAND;
				}
			} else {
				if ((control[id].buttons >> 1 & 1) && being[id]._lastMov != irr::scene::EMAT_CROUCH_WALK) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_CROUCH_WALK);
					being[id]._lastMov = irr::scene::EMAT_CROUCH_WALK;
				}
				else if ((control[id].buttons >> 9 & 1) && being[id]._lastMov != irr::scene::EMAT_RUN) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
					being[id]._lastMov = irr::scene::EMAT_RUN;
				} else if ((control[id].buttons >> 9 & 1) == 0 && (control[id].buttons >> 1 & 1) == 0 && being[id]._lastMov != irr::scene::EMAT_RUN) {
					being[id]._node->setMD2Animation(irr::scene::EMAT_RUN);
					being[id]._lastMov = irr::scene::EMAT_RUN;
				}

				being[id]._rotation = rot;
				pos = being[id]._node->getPosition();
				pos.X = pos.X + static_cast<float>(cos(rot * M_PI / 180)) * speed * deltatime;
				pos.Z = pos.Z - static_cast<float>(sin(rot * M_PI / 180)) * speed * deltatime;
				being[id]._node->setPosition(pos);
			}
		}
	}
}