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
		listeJoueur[i]->affichageFormatee();
		system("PAUSE");
		system("cls");
	}
	
	/*************FIN DE LA SELECTION*************/
	bool tourp1 = true;
	
	/************* TOURS DES JOUEURS ***********/
	do
	{
		listeJoueur[0]->affichageFormatee();
		listeJoueur[1]->affichageFormatee();
		if (tourp1) {
			listeJoueur[0]->choixAttaque(listeJoueur[1]);
			tourp1 = false;
			
			system("PAUSE");
			system("cls");
			listeJoueur[0]->affichageFormatee();
			listeJoueur[1]->affichageFormatee();
			system("PAUSE");
		}
		else {
			listeJoueur[1]->choixAttaque(listeJoueur[0]);
			tourp1 = true;
			
			system("PAUSE");
			system("cls");
			listeJoueur[0]->affichageFormatee();
			listeJoueur[1]->affichageFormatee();
			system("PAUSE");
		}
		system("cls");
	} while (listeJoueur[0]->estVivant() && listeJoueur[1]->estVivant());
	/************* FIN DES TOURS ***********/
	

	/************* D�TERMINATION DU GAGNANT *********************/
	
	/************* FIN DE LA D�TERMINATION DU GAGNANT ***********/

	/************* SUPRESSION DES JOUEURS  *********************/
	for (int i = 0; i < listeJoueur.size(); i++)
	{
		delete listeJoueur[i];
		listeJoueur[i] = 0;
	}
	/************* FIN DESUPRESSION DES JOUEURS ***************/
	system("PAUSE");

	return 0;
}