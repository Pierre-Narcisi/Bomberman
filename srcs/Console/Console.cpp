/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Console.cpp
*/

#include <unistd.h>
#include <fcntl.h>
#include <iostream>

#include "Console.hpp"

namespace indie {

	Console::Console():
	_thread{ [this](){shell();} }
	{
	}

	Console::~Console()
	{
		_exit = true;
		_thread.join();
	}

	void Console::shell()
	{
		while (_exit == false) {
			std::string line;
			std::cin >> line;
			std::cout << line << std::endl;
		}
	}

}
