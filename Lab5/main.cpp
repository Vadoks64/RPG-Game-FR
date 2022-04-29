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

using namespace std;

int main() {
	srand(time(NULL));
	locale::global(locale{ "" }); // Gestion des accents
	affichageIntro(); // Affichage de l'intro
	
	/********** S�LECTION DU NOM DES JOUEURS****************/
	string nomPretre;
	cout << "Nom du Pr�tre: ";
	cin >> nomPretre;
	system("cls");
	string nomDruide;
	cout << "Nom du Druide: ";
	cin >> nomDruide;
	system("cls");
	/*************FIN DE LA SELECTION*************/

	Pretre p1(nomPretre);
	Druide p2(nomDruide);
	bool tourp1 = true;

	
	/************* TOURS DES JOUEURS ***********/
	while (p1.estVivant() && p2.estVivant()) { 
		cout << p1.affichageFormatee() << "\n" << endl; // Affiche les stats du Pr�tre
		cout << p2.affichageFormatee() << "\n" << endl; // Affiche les stats du Druide
		
		if (tourp1 == true) { // Tour du pr�tre
			p1.choixAttaque(p2);
			tourp1 = false;
		}

		else if (tourp1 == false) { // Tour du Druide
			p2.choixAttaque(p1);
			tourp1 = true;
		}
		system("PAUSE");
		system("cls");
	}
	/************* FIN DES TOURS ***********/

	/************* D�TERMINATION DU GAGNANT *********************/
	if (p1.estVivant()) { // Cas o� Pr�tre est gagnant
		cout << "Le Pr�tre " << nomPretre << " a gagn�!" << endl;
		cout << "Il lui restait " << p1.getVie() << " points de vie" << endl;
	}

	if (p2.estVivant()) { // Cas o� Druide est gagnant
		cout << "Le Druide " << nomDruide << " a gagn�!" << endl;
		cout << "Il lui restait " << p2.getVie() << " points de vie" << endl;
	}
	/************* FIN DE LA D�TERMINATION DU GAGNANT ***********/

	system("PAUSE");

	return 0;
}