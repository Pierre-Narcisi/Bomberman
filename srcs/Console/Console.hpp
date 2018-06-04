/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Console.hpp
*/

#pragma once

#include <thread>

namespace indie {

	class Console {
	public:
		Console();
		~Console();

	private:
		void shell();

	private:
		bool _exit = false;
		std::thread _thread;
	};

}
