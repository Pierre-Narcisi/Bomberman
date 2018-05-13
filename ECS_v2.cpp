/*
** EPITECH PROJECT, 2017
** Client
** File description:
** implementComponent.cpp
*/

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

class EntityManager;

using Id = std::size_t;

/**** Entity ****/

class Entity {
public:
	Entity(Id id) :
	id{ id }
	{}

	Entity(Entity const &other):
	id{other.id}
	{}

	Entity &operator=(Entity const &other)
	{
		this->id = other.id;
		return *this;
	}
	
	Id id;
};

/**** EntityManager ****/

class EntityManager {
public:
	static EntityManager &get()
	{
		static EntityManager em;

		return em;
	}

	std::list<Entity> list() const
	{
		return _entities;
	}

	Entity newEntity()
	{
		_entities.push_back({ generateId() });

		return _entities.back();
	}

	Id generateId()
	{
		return _idCounter++;
	}

private:
	Id _idCounter = 0;
	std::list<Entity> _entities;
};

/**** Storage ****/

template<class T>
class Storage {
public:
	static Storage<T> &get()
	{
		static Storage<T> st;

		return st;
	}

	template<typename ...Args>
	void addComponentForEntity(Id entityId, Args ...args)
	{
		_components.push_back( {args...} );
		_components.back().entityId = entityId;

		_store[entityId] = _components.size() - 1;
	}

	void removeComponentForEntity(Id entityId)
	{
		auto removeIndex = _store[entityId];

		_store[_components.back().entityId] = removeIndex;
		std::swap(_components[removeIndex], _components.back);
		_components.pop_back();

		_store.erase(entityId);
	}

	T &getComponentForEntity(Id entityId)
	{
		return _components[_store[entityId]];
	}

	bool hasEntityComponent(Id entityId) const
	{
		return _store.find(entityId) != _store.end();
	}

private:
	std::vector<T> _components;
	std::unordered_map<Id, std::size_t> _store;
};

/**** Components ****/

struct Component {
	Id entityId = 0;
};

struct Position : public Component{
	Position(int x = 0, int y = 0):
	x{x}, y{y}
	{}
	int x;
	int y;
};

struct BoxColide : public Component{
	BoxColide(int p1 = 0, int p2 = 0, int s1 = 0, int s2 = 0):
	p1{p1}, p2{p2}, s1{s1}, s2{s2}
	{}
	int p1;
	int p2;
	int s1;
	int s2;
};

/**** Printer ****/

template<class ...Ts>
struct Printer;

template<class T>
struct Printer<T> {
	static void print(Entity const &e, int i = 0)
	{
		if (i == 0)
			std::cout << "Id: " << e.id << " = {";
		if (Storage<T>::get().hasEntityComponent(e.id))
			std::cout << (i != 0 ? ", " : "") << typeid(T).name();
		if (i == 0)
			std::cout << "}" << std::endl;
	}
};

template<class T, class ...Ts>
struct Printer<T, Ts...> {
	static void print(Entity const &e, int i = 0)
	{
		if (i == 0)
			std::cout << "Id: " << e.id << " = {";
		if (Storage<T>::get().hasEntityComponent(e.id))
			std::cout << (i != 0 ? ", " : "") << typeid(T).name();
		Printer<Ts...>::print(e, i + 1);
		if (i == 0)
			std::cout << "}" << std::endl;
	}
};

/**** Filter ****/

template<class ...Ts>
class Filter;

template<class T>
class Filter<T> {
public:
	Filter<T>(std::list<Entity> *li = nullptr)
	{
		if (li == nullptr)
			list = EntityManager::get().list();
		else
			list = *li;
		list.remove_if( [] (Entity const &e) {
			return !Storage<T>::get().hasEntityComponent(e.id);
		});
	}
	std::list<Entity> list;
};

template<class T, class ...Ts>
class Filter<T, Ts...> {
public:
	Filter<T, Ts...>(std::list<Entity> *li = nullptr)
	{
		Filter<Ts...> filters(li);

		list = std::move(filters.list);
		list.remove_if( [] (Entity const &e) {
			return !Storage<T>::get().hasEntityComponent(e.id);
		});
	}
	std::list<Entity> list;
};

/**** main ****/

int main()
{
	EntityManager &instance = EntityManager::get();
	Entity player1 = instance.newEntity();
	Entity player2 = instance.newEntity();
	Entity player3 = instance.newEntity();
	Entity player4 = instance.newEntity();
	Entity player5 = instance.newEntity();
	Entity player6 = instance.newEntity();

	Storage<Position>::get().addComponentForEntity( player1.id );
	Storage<BoxColide>::get().addComponentForEntity( player1.id );
	Storage<BoxColide>::get().addComponentForEntity( player2.id );
	Storage<BoxColide>::get().addComponentForEntity( player3.id );
	Storage<BoxColide>::get().addComponentForEntity( player4.id );
	Storage<Position>::get().addComponentForEntity( player4.id );
	Storage<Position>::get().addComponentForEntity( player5.id );
	Storage<Position>::get().addComponentForEntity( player6.id );

	Position &myPositionComponent = Storage<Position>::get().getComponentForEntity( player1.id );
	myPositionComponent.x = 100;
	myPositionComponent.y = 300;

	Printer<BoxColide, Position>::print(player1);
	Printer<BoxColide, Position>::print(player2);

	Filter<BoxColide> fl;
	Filter<Position> fl2(&fl.list);
	std::cout << "filter1 : ";
	for (auto &e : fl.list) {
		std::cout << e.id << " ";
	}
	std::cout << std::endl;
	std::cout << "filter2 : ";
	for (auto &e : fl2.list) {
		std::cout << e.id << " ";
	}
	std::cout << std::endl;
}