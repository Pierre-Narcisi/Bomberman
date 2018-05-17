/*
** EPITECH PROJECT, 2017
** Client
** File description:
** implementComponent.cpp
*/

#include <iostream>
#include <functional>
#include <algorithm>
#include <memory>
#include <list>
#include <vector>
#include <unordered_map>

class EntityManager;
template<class T>
class Storage;

using Id = std::size_t;

/**** Entity ****/

class Entity {
public:
	Entity(Id id) :
	_id{ id },
	_components{std::make_shared<std::unordered_map<std::string, std::function<void()>>>()}
	{}

	~Entity()
	{
		if (_components.use_count() == 1) {
			for (auto &component : *_components) {
				component.second();
			}
		}
	}

	Entity(Entity const &other):
	_id{other._id},
	_components{ other._components }
	{}

	Entity &operator=(Entity const &other)
	{
		_id = other._id;
		_components = other._components;
		return *this;
	}

	Id getId() const
	{
		return _id;
	}

	/* Do not call it directly */
	template<class T>
	void setComponent(std::function<void()> &&deleteFunc)
	{
		_components->emplace(typeid(T).name(), deleteFunc);
	}

	/* Do not call it directly */
	template<class T>
	void removeComponent()
	{
		if (_components->find(typeid(T).name()) != _components->end())
			_components->erase(typeid(T).name());
	}

	/* Only for debug */
	friend std::ostream &operator<<(std::ostream &os, Entity const &e)
	{
		os << "Entity n°" << e._id << " {\n";
		for (auto const &component : *e._components)
			os << "\t" << component.first << std::endl;
		return os << "}";
	}

private:	
	Id _id;
	std::shared_ptr<std::unordered_map<std::string, std::function<void()>>> _components;
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

	Entity &newEntity()
	{
		_entities.emplace_back( generateId() );

		return _entities.back();
	}

	void deleteEntity(Entity const &entity)
	{
		deleteEntity( entity.getId() );
	}

	void deleteEntity(Id entityId)
	{
		_entities.remove_if([entityId] (Entity const &e) {
			return (e.getId() == entityId);
		});
	}

	Entity &operator[](Id entityId)
	{
		auto it = std::find_if(_entities.begin(), _entities.end(),
			[entityId] (Entity const &e) {
				return (e.getId() == entityId);
			});
		if (it == _entities.end())
			throw "Id not Found";
		return *it;
	}

	Entity const &operator[](Id entityId) const
	{
		auto const it = std::find_if(_entities.begin(), _entities.end(),
		[entityId] (Entity const &e) {
			return (e.getId() == entityId);
			});
		if (it == _entities.end())
			throw "Id not Found";
		return *it;
	}

private:
	EntityManager() = default;

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

	~Storage()
	{
		auto &manager = EntityManager::get();

		for (auto const &e : _store)
			manager[e.first].removeComponent<T>();
	}

	template<typename ...Args>
	void addComponentForEntity(Entity &entity, Args &&...args)
	{
		if (_store.find(entity.getId()) != _store.end()) {
			_components[_store[entity.getId()]] = T(args...);
		} else {
			_components.emplace_back( std::forward<Args>(args)... );
			_components.back().entityId = entity.getId();
			entity.setComponent<T>(
				std::bind( &Storage<T>::removeComponentForEntityId, this, entity.getId() )
			);

			_store[entity.getId()] = _components.size() - 1;
		}
	}

	template<typename ...Args>
	void addComponentForEntity(Id entityId, Args &&...args)
	{
		addComponentForEntity( EntityManager::get()[entityId], std::forward<Args>(args)... );
	}

	void removeComponentForEntity(Entity &entity)
	{
		auto removeIndex = _store[entity.getId()];

		entity.removeComponent<T>();
		_store[_components.back().entityId] = removeIndex;
		std::swap(_components[removeIndex], _components.back());
		_components.pop_back();

		_store.erase(entity.getId());
	}

	void removeComponentForEntityId(Id entityId)
	{
		try {
			removeComponentForEntity(EntityManager::get()[entityId]);
		} catch (char const *) {
			auto removeIndex = _store[entityId];
			_store[_components.back().entityId] = removeIndex;
			std::swap(_components[removeIndex], _components.back());
			_components.pop_back();

			_store.erase(entityId);			
		}
		
	}

	T &getComponentForEntity(Entity const &entity)
	{
		return _components[_store[entity.getId()]];
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

struct Position : public Component {
	Position(int x = 0, int y = 0):
	x{x}, y{y}
	{}
	int x;
	int y;
};

struct BoxCollide : public Component {
	BoxCollide(int p1 = 0, int p2 = 0, int s1 = 0, int s2 = 0):
	p1{p1}, p2{p2}, s1{s1}, s2{s2}
	{}
	int p1;
	int p2;
	int s1;
	int s2;
};

struct Name : public Component {
	Name(std::string name):
	name{name}
	{}
	std::string name;
};

/**** Printer ****/

template<class ...Ts>
struct Printer;

template<class T>
struct Printer<T> {
	static void print(Entity const &e, int i = 0)
	{
		if (i == 0)
			std::cout << "Id: " << e.getId() << " = {";
		if (Storage<T>::get().hasEntityComponent(e.getId()))
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
			std::cout << "Id: " << e.getId() << " = {";
		if (Storage<T>::get().hasEntityComponent(e.getId()))
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
		list.remove_if([] (Entity const &e) {
			return !Storage<T>::get().hasEntityComponent(e.getId());
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
		list.remove_if([] (Entity const &e) {
			return !Storage<T>::get().hasEntityComponent(e.getId());
		});
	}
	std::list<Entity> list;
};

/**** System ****/

class System {
public:
	System(Entity &entity):
	_this{ entity }
	{}
	virtual ~System() = default;

	virtual void update() = 0;

protected:
	Entity &_this;
};

class HelloSystem : public System {
public:
	HelloSystem(Entity &entity): System{entity} {}
	virtual ~HelloSystem() = default;

	void update() override
	{
		std::cout << "Hello " << _this.getId() << " !" << std::endl;
	}

private:

};

class PrintSystem {
	static void printName(Name name) {
		std::cout << name.name << std::endl;
	}
};

class PositionSystem {
	public:
	static void updatePosition(Position &pos, int x = 0, int y = 0) {
		pos.x += x;
		pos.y += y;
	}

	static void updateAllPosition() {
		Filter<Position> fl;

		for (auto &e : fl.list)
			updatePosition(Storage<Position>::get().getComponentForEntity(e), 1, 0);
	}
};

/**** main ****/


int main()
{
	EntityManager &instance = EntityManager::get();
	Entity &player1 = instance.newEntity();

	Storage<Position>::get().addComponentForEntity( player1 );
	Storage<BoxCollide>::get().addComponentForEntity( player1 );

	std::cout << player1 << std::endl;

	auto &pos1 = Storage<Position>::get().getComponentForEntity(player1);
	pos1.x = 350;
	pos1.y = -120;


	auto &posToPrint = Storage<Position>::get().getComponentForEntity(player1);
	std::cout << posToPrint.x << "  " << posToPrint.y << std::endl;

	Entity &player2 = instance.newEntity();
	Entity &player3 = instance.newEntity();
	Entity &player4 = instance.newEntity();
	
	Storage<Position>::get().addComponentForEntity( player2 );
	Storage<Position>::get().addComponentForEntity( player4 );

	Filter<Position> fl;

	for (auto &e : fl.list) {
		std::cout << e << std::endl;
	}

	Filter<BoxCollide> fl1(&fl.list);

	Storage<Name>::get().addComponentForEntity(player1, "Toto");

	PositionSystem::updateAllPosition();

	for (auto &e : EntityManager::get().list()) {
		auto &a = Storage<Position>::get().getComponentForEntity( e );
		std::cout << a.x << "  " << a.y << std::endl;
	}

	// Position &myPositionComponent = Storage<Position>::get().getComponentForEntity( player1.getId() );
	// myPositionComponent.x = 100;
	// myPositionComponent.y = 300;

	// Printer<BoxCollide, Position>::print(player1);
	// Printer<BoxCollide, Position>::print(player2);

	// EntityManager::get().deleteEntity(player4);

	// Filter<BoxCollide> fl;
	// Filter<Position> fl2(&fl.list);
	// std::cout << "filter1 : ";
	// for (auto &e : fl.list) {
	// 	std::cout << e << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "filter2 : ";
	// for (auto &e : fl2.list) {
	// 	std::cout << e.getId() << " ";
	// }
	// std::cout << std::endl;
	// std::unique_ptr<System> sys = std::make_unique<HelloSystem>(HelloSystem{player1});
	// sys->update();
	// sys->update();
}

/*
int main()
{
	Entity p1 = EntityManager::get().newEntity();
	Entity p2 = EntityManager::get().newEntity();

	Storage<Position>::addComponentForEntity(p1);
}*/