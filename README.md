entity = std::size_t
	sert de block comportant plusieurs component

component = 
	un truc qui a  de la data, permet de donné des characteristiques à une entity

système =
	algorithme. 
	permet de faire vivre les entities, de les faire interagir.


exemple :

voiture = entity

voiture.speed = component

voiture.move(3, 4) = system

player = entity
weapon = entity

player.weapon = component
player.hold(weapon) = system

Entity :
	can get it ID
	can get linked with a component (can be triggered only by Storage) (Do not construct a component in Storage)
	can remove a linked with a component (can be triggered by Storage or by destructor) (Destroy the component in Storage only if it called in destructor)
	on remove :
		delete all components linked

EntityManager :
	can create a new Entity
	can remove an Entity/ID
	can get an Entity with an id
	on remove :
		delete all Entities (implicite)
		be sur Storage wasn't destroyed before (??)

Storage :
	can link a component with an Entity/ID (trigger also the link in the Entity linked)
	can remove link with an Entity/ID (trigger also the removeLink in the Entity linked)
	get a Component linked to a given Entity/ID
	on remove :
		remove all link for all ID