/************************************************************
* fichier : main.cpp
* R�le : Ex�cution du programme
* Auteur : �lie Charles D�saulniers
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

	/********** S�LECTION DES JOUEURS****************/
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
	

	/************* D�TERMINATION DU GAGNANT *********************/
	
	/************* FIN DE LA D�TERMINATION DU GAGNANT ***********/

	system("PAUSE");

	return 0;
}