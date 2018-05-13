#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
	
/******* Entity *******/

using Entity = size_t;
	
/******* Entities *******/
	
class Entities {
public:
	Entities(size_t size = 1000);
	Entity create();
	void remove(Entity entity);
	void print() const;

private:
	std::vector<Entity> m_entities{};	   // sorted array (use std::set?)
};
	
Entities::Entities(size_t size) {
	m_entities.reserve(size);
}
	
Entity Entities::create() {
	const auto it = std::adjacent_find(begin(m_entities), end(m_entities), 
			[] (Entity lhs, Entity rhs) {
				return (lhs+1 != rhs);
			});
	
	if (it == end(m_entities)) {
		m_entities.push_back(m_entities.size());
		return m_entities.back();
	} else {
		const auto result = m_entities.insert(it+1, (*it)+1);
		return *result;
	}
}
	
void Entities::remove(Entity entity) {
	const auto it = std::find(begin(m_entities), end(m_entities), entity);

	if (it != end(m_entities)) {
		m_entities.erase(it);
	}
}
	
void Entities::print() const {
	for(auto i: m_entities) { 
		std::cout << i << ' '; 
	}; 
	std::cout << std::endl;
}
	
/******* Component *******/
	
class Component {
public:
	Entity entity() const;

protected:
	Component(Entity entity);	  // disable instanciation of base Component

private:
	Entity m_entity{};
};
	
Component::Component(Entity entity) : m_entity(entity) {
}
	
Entity Component::entity() const {
	return m_entity;
}
	
struct PositionComponent : public Component {
	int x{};
	int y{};
};
	
struct StateComponent : public Component {
	enum class State { Waiting, Walking, Running, Dead };
	State state { State::Waiting };
};
	
/******* Components *******/
	
template<class ConcretComponent>
class Components {
public:
	Components(size_t size = 1000);
	ConcretComponent& create(Entity entity);
	void remove(Entity entity);

protected:	  // can add algos in derived classes
	std::vector<ConcretComponent> m_components{};   // not sorted array
};
	
template<class ConcretComponent>
Components<ConcretComponent>::Components(size_t size) {
	m_components.reserve(size);
}
	
template<class ConcretComponent>
ConcretComponent &Components<ConcretComponent>::create(Entity entity) {
	m_components.push_back(ConcretComponent(entity));
}
	
template<class ConcretComponent>
void Components<ConcretComponent>::remove(Entity entity) {
	std::remove_if(begin(m_components), end(m_components), 
	[entity](const ConcretComponent &component){ return (component.entity() == entity); });
}
	
/******* System *******/

template<class T>	
class System {
public:
	
private:
	Components<T> m_components;
};
	
template<class T>	
class System2 {
public:
	System2(Components<T>& attachedComponents);
private:
	Components<T>& m_components;
};
	
/******* Main *******/
	
int main() {
	// entities
	Entities entities;
	auto me = entities.create();
	auto you = entities.create();
	entities.print();
	std::vector<Entity> badGuys;
	for(auto i=0; i<10; ++i) { badGuys.push_back(entities.create()); }
	entities.print();
	entities.remove(you); // you're killed!!!
	entities.print();
	you = entities.create(); // but you're a survivor
	entities.print();
}