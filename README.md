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