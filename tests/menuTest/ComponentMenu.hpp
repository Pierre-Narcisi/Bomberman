/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Component.hpp
*/

#pragma once

namespace ecs::component {

	struct Type {
		enum class Enum {
			Background, Button, Mouse
		};
		Enum t;
	};

	struct Position {
		int x{};
		int y{};
	};

	struct Rect {
		int xs{};
		int ys{};
		int xi{};
		int yi{};
	};

	struct Color {
		int a = 255;
		int r = 255;
		int g = 255;
		int b = 255;
	};

	struct Image {
		irr::video::ITexture *image;
		Rect rect;
		Color color;
		Position pos{};
		int i{};
		bool last{};
		bool draw{};
	};

	struct Mouse {
		Position pos{};
		bool leftClick = false;
		bool rightClick = false;
	};

	struct Deletable {
		bool del = false;
	};

}
