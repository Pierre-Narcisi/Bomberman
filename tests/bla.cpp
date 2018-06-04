/*
** EPITECH PROJECT, 2017
** Client
** File description:
** bla.cpp
*/

#include <iostream>
#include <unordered_map>
#include <memory>
#include <functional>

struct A {
	explicit A(int, int)
	{
		id = ++i;
		std::cout << "construct A" << id << std::endl;
	}
	~A()
	{
		std::cout << "destruct A" << id << std::endl;
	}
	A(A const &a)
	{
		id = ++i;
		std::cout << "copy A" << a.id << " -> " << id << std::endl;
	}
	A(A &&a)
	{
		id = ++i;
		std::cout << "move A" << a.id << " -> " << id << std::endl;
	}
	A &operator=(A const &a)
	{
		id = ++i;
		std::cout << "operator copy A" << a.id << " -> " << id << std::endl;
		return *this;
	}
	A &operator=(A &&a)
	{
		id = ++i;
		std::cout << "operator move A" << a.id << " -> " << id << std::endl;
		return *this;
	}
	static int i;
	int id;
};
int A::i = 0;

struct B {
	explicit B(int, int)
	{
		id = ++i;
		std::cout << "construct B" << id << std::endl;
	}
	~B()
	{
		std::cout << "destruct B" << id << std::endl;
	}
	B(B const &a)
	{
		id = ++i;
		std::cout << "copy B" << a.id << " -> " << id << std::endl;
	}
	B(B &&a)
	{
		id = ++i;
		std::cout << "move B" << a.id << " -> " << id << std::endl;
	}
	B &operator=(B const &a)
	{
		id = ++i;
		std::cout << "operator copy B" << a.id << " -> " << id << std::endl;
		return *this;
	}
	B &operator=(B &&a)
	{
		id = ++i;
		std::cout << "operator move B" << a.id << " -> " << id << std::endl;
		return *this;
	}
	static int i;
	int id;
};
int B::i = 0;

int main()
{
	std::unordered_map<int, A> mapA;
	std::unordered_map<int, B> mapB;

	{
		// mapA.emplace(0, 1, 1); // compile // construct -> destroy
		// mapA.emplace(0, {1}); // doesn't compile // doesn't find constructor
		mapA.emplace(0, A(1, 1)); // compile // construct -> move -> destroy -> destroy
	}
}