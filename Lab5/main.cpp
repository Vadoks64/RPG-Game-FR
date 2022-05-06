/************************************************************
* fichier : main.cpp
* Rôle : Exécution du programme
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

#include <iostream>
#include "Personnage.h"
#include "Pretre.h"
#include "fonctions.h"
#include "Arme.h"
#include "Druide.h"
#include <string>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

int main() {
	srand(time(NULL));
	locale::global(locale{ "" }); // Gestion des accents
	affichageIntro(); // Affichage de l'intro

	/********** SÉLECTION DES JOUEURS****************/
	vector<Personnage*> listeJoueur;
	for (int i = 0; i < 2; i++)
	{
		listeJoueur.push_back(creePersonnage(i));
	}

	listeJoueur[0]->affichageFormatee();
	listeJoueur[1]->affichageFormatee();
	
	/*************FIN DE LA SELECTION*************/
	bool tourp1 = true;

	
	/************* TOURS DES JOUEURS ***********/
	
	/************* FIN DES TOURS ***********/
	

	/************* DÉTERMINATION DU GAGNANT *********************/
	
	/************* FIN DE LA DÉTERMINATION DU GAGNANT ***********/

	system("PAUSE");

	return 0;
}