Cahier des charges
==================

### jeu :  
Bomberman

## assets 3d :  
- perso * nb chroma
- block plein
- caisse cassable
- bombe
- mur exterieur
thème : épouvantail

## menu :  
boutons :
	reprendre		-> reprend une partie en cours
	partie solo		-> créer une partie solo
	partie multijoueur	-> rentre dans le menu du multijoueur
	settings		-> lance le menu des settings (détailé plus bas)
	quitter			-> quite le jeu après validation
#### menu multijoueur :
boutons :
	choix du nombre de joueurs max (2-4)
	choix du nombre de joueur local (1-2) (si le nombre de joueur local != nombre de joueur max -> lancer le mode multi)
	partie coop		-> lance une partie coop
	partie vs		-> lance une partie versus
	retour			-> retourne au menu principale


## animations 2d :
splash sreen		-> non déterminé
transition		-> non déterminé

## settings :
changement de touches:
	touches :
		p1_up		-> fait bouger le joueur 1 le haut	// navigue dans les menus vers le haut
		p1_down		-> fait bouger le joueur 1 le bas	// navigue dans les menus vers le bas
		p1_right	-> fait bouger le joueur 1 la droite	// navigue dans les menus vers la droite
		p1_left		-> fait bouger le joueur 1 la gauche	// navigue dans les menus vers la gauche
		p1_fire		-> pose une bombe au pied du joueur 1	// active le bouton selectionné
		p1_event	-> applique un effet 'in game' du joueur 1 (varie en fonction des bonus)
		p2_up		-> fait bouger le joueur 2 le haut
		p2_down		-> fait bouger le joueur 2 le bas
		p2_right	-> fait bouger le joueur 2 le droite
		p2_left		-> fait bouger le joueur 2 le gauche
		p2_fire		-> pose une bombe au pied du joueur 2
		p2_event	-> applique un effet 'in game' du joueur 2 (varie en fonction des bonus)
		menu		-> en jeu : ouvre le menu // dans les menu : retourne au menu principale // dans le menu principale : selectionne le bouton quitter // refuse les 'oui-non'
choix de la langue	-> selecteur de langue
volume sonore		-> choix en 100% + mute la musique + mute les bruits
multiplayer		-> non déterminé

## characters (technical part) :
	players

## objects (technical part) :
	camera

## quest/goal :
mode survie :
	mode solo :
		vs ia		-> mode classique : le joueur se bat contre 1 à 3 ia et doit le survivant gagne
		règles :
		survie		-> des ennemis apparaissent sur la carte, après tous les avoir tué la porte du niveau suivant souvre
		règles :
	mode multijoueur :
		vs ia		-> même règles que le mode solo mais avec plus de joueurs

## network :
	implémentation du réseau (boost ??)
	serialisation // déserialisation de l'état du jeu

## ai :
	implémentation d'ia en lua ou en python.
	l'ia du joueur :
		- personnage mobile pouvant se déplacer
		- poser des bombes
		- comprends le système de stats et les prends en compte dans ces calculs
	l'ia des ennemis (mode survie) :
		- déplacement linéaire

#### à faire en fin de semaine 18.05 :
trouver les assets 3d animées (axel pierre)
launcher bien avancé (benjamin)
comprendre déplacements de perso, mouvement de camera, création de map, avec irlish  (sebastien loick)
finir l'ECS (alexandre)