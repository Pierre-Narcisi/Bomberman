# SmartEvent

### **Qu'est ce que c'est ?**

C'est une petite lib C++ permettant la gestion d'evenements.

### **Quelles sont ses features ?**

SmartEvent contient 3 classes : _Event - Manager - HldCollector_

***

## Event

```c++
/*
 * Creer un handler dans l'Event
 * Retourne une fonction de suppression
 */
template <typename Ret, typename ...Args>
const evtHdlDestr&
Event::addHandler(typename Event::FctSign<std::function<Ret(Args...)>>::type const &hdl);

/*
 * Appel les handlers de l'Event
 * Ne fonctionne qu'avec les handlers qui retournent 'void'
 */
template <typename ...Args>
void
Event::fire(Args... args);

/*
 * Appel les handlers de l'Event et retourne un vector des resultats
 */
template <typename RetType, typename ...Args>
std::shared_ptr<std::vector<RetType>>
Event::fire(T... args);
```

```c++
#include <iostream>
#include "Event/Event.hpp"

int main()
{
	evt::Event	ah;

	ah.addHandler<void, int, int>([] (int a, int b) {
		for (int i = 0; i < b; i++)
			std::cout << a << std::endl;
	});

	// Un autre Handler;
	ah.addHandler<void, int, int>([] (int a, int b) {
		(void) a; (void) b;
		std::cout << "Hey :P" << std::endl;
	});

	ah.fire(10, 5);
	/*
	output:
		10
		10
		10
		10
		10
		Hey :P
	*/
	return (0);
}

```

Un handler peut avoir plusieurs signatures dans un même Event,  
Reprenons l'exemple du haut :

```c++
#include <iostream>
#include "Event/Event.hpp"

int main()
{
	evt::Event	ah;

	ah.addHandler<void, int, int>([] (int a, int b) {
		for (int i = 0; i < b; i++)
			std::cout << a << std::endl;
	});

	// Un autre Handler;
	ah.addHandler<>([] {
		std::cout << "Hey :P" << std::endl;
	});

	ah.fire(10, 5);
	std::cout << "And... " << std::endl;
	ah.fire();
	/*
	output:
		10
		10
		10
		10
		10
		
		And... 

		Hey :P
	*/
	return (0);
}

```

Comment retirer un Handler ?  
addHandler() retourne une fonction, il suffit de call cette fonction et c'est tout.

```c++
#include <iostream>
#include "Event/Event.hpp"

int main()
{
	evt::Event	ah;

	auto remove = ah.addHandler<>([] {
		std::cout << "1er hdl" << std::endl;
	});

	ah.addHandler<>([] {
		std::cout << "2eme hdl" << std::endl;
	});

	ah.fire();

	remove();
	std::cout << "Apres le call de remove()" << std::endl;
	ah.fire();
	/*
	output:
		1er hdl
		2eme hdl
		Apres le call de remove()
		2eme hdl
	*/
	return (0);
}
```

## Manager

C'est simplement une sorte de map d'Evenement avec quelques fonctionnalités permettant d'éviter les leaks de memoire.

```c++
/*
 * Retourne un Manager en globale
 */
static	Manager	&Manager::get(void)

/*
 * Permet la creation et l'acces a un Event a l'aide d'une clé
 * Retoune un Event dans un Wrapper.
 */
EventWrapper	Manager::operator[](std::string const &eventName);

/*
 * Supprime l'Event;
 */
void		Manager::removeEvent(std::string const &eventName);
```

Exemple :

```c++
evt::Manager	manager;
manager["Salut"]->addHandler<>([] {
	std::cout << "Ah." << std::endl;
});
```

## HdlCollector

Comme sont nom l'indique, il collecte des fonctions de suppression d'handler et les appel à sa destruction. Il permet une utilisation plus simple d'un Manager ou d'un Event quand il est passé entre plusieurs classes voués à être detruites.

```c++
/*
 * Ajoute un destructeur et l'overload.
 * A l'appel de la fonction overloadé, elle sera supprimer du Collecteur et de l'Event
 */
Event::evtHdlDestr	add(Event::evtHdlDestr const &);

/*
 * Ajoute un destructeur;
 */
HdlCollector		&operator<<(Event::evtHdlDestr const &);

/*
 * Appel tous les destructeurs sans detruire le collecteur;
 */
void			flush(void);
```

Exemple

```c++
#include <iostream>
#include "Manager/Manager.hpp"
#include "HdlCollector/HdlCollector.hpp"

class A
{
public:
	A()
	{
		auto &manager = evt::Manager::get();

		collector << manager["Salut"]->addHandler<>([] {
			std::cout << "Je suis dans A" << std::endl;
		});
	}
private:
	evt::HdlCollector	collector;
};

int main()
{
	auto &manager = evt::Manager::get();

	manager["Salut"]->addHandler<>([] {
		std::cout << "Je suis dans main()" << std::endl;
	});

	auto a = new A();
	manager["Salut"]->fire();

	std::cout << std::endl;
	delete a;
	manager["Salut"]->fire();	
	/*
	output:
		Je suis dans main()
		Je suis dans A

		Je suis dans main()
	*/
	return (0);
}
```