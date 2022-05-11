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
	vector<Personnage*> listeJoueurs;
	for (int i = 0; i < 2; i++)
	{
		listeJoueurs.push_back(creePersonnage(i));
		listeJoueurs[i]->affichageFormatee();
		system("PAUSE");
		system("cls");
	}
	
	/*************FIN DE LA SELECTION*************/
	int tourJ = 0;
	
	/************* TOURS DES JOUEURS ***********/
	do
	{
		listeJoueurs[0]->affichageFormatee();
		listeJoueurs[1]->affichageFormatee();
		if (tourJ == 0) {
			tourJoueur(listeJoueurs, tourJ);
			tourJ = 1;
		}
		else {
			tourJoueur(listeJoueurs, tourJ);
			tourJ = 0;
		}
		system("cls");
	} while (listeJoueurs[0]->estVivant() && listeJoueurs[1]->estVivant());
	/************* FIN DES TOURS ***********/
	

	/************* DÉTERMINATION DU GAGNANT *********************/
	Personnage* gagnant = listeJoueurs[determinerGagnant(listeJoueurs)];
	cout << gagnant->getNom() << " a gagné !!!" << endl;
	cout << "Il lui restait " << gagnant->getVie() << " points de vie!" << endl;
	cout << "Bien joué !" << endl;
	/************* FIN DE LA DÉTERMINATION DU GAGNANT ***********/

	/************* SUPRESSION DES JOUEURS  *********************/
	for (int i = 0; i < listeJoueurs.size(); i++)
	{
		delete listeJoueurs[i];
		listeJoueurs[i] = 0;
	}
	/************* FIN DESUPRESSION DES JOUEURS ***************/
	system("PAUSE");

	return 0;
}