assets 3d :
	perso * nb chroma
	block plein
	caisse cassable
	bombe
	mur exterieur

	theme épouvantail

menu:
	bouttons :
		reprendre
		partie coop
		partie vs
		settings
		exit

animations 2d:
	splash sreen
	transition des bouttons

settings:
	changement de touches:
		player 1 up/down/left/right/lancer bombe/event1
		player 2 up/down/left/right/lancer bombe/event1

	langues
	volume sonore
	multiplayer


characters (technical part):
	players

objects (technical part):
	camera


quest/goal:
	survivre
	sur le theme de Saw

multiplayer:
	mode coop

network:
	class network
	serializasion

ai:
	lua

à faire en fin de semaine 18.05 :
trouver les assets 3d animées (axel pierre)
launcher bien avancé (benjamin)
comprendre déplacements de perso, mouvement de camera, création de map, avec irlish  (sebastien loick)
finir l'ECS (alexandre)