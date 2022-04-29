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

using namespace std;

int main() {
	srand(time(NULL));
	locale::global(locale{ "" }); // Gestion des accents
	affichageIntro(); // Affichage de l'intro
	
	/********** SÉLECTION DU NOM DES JOUEURS****************/
	string nomPretre;
	cout << "Nom du Prêtre: ";
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
		cout << p1.affichageFormatee() << "\n" << endl; // Affiche les stats du Prêtre
		cout << p2.affichageFormatee() << "\n" << endl; // Affiche les stats du Druide
		
		if (tourp1 == true) { // Tour du prêtre
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

	/************* DÉTERMINATION DU GAGNANT *********************/
	if (p1.estVivant()) { // Cas où Prêtre est gagnant
		cout << "Le Prêtre " << nomPretre << " a gagné!" << endl;
		cout << "Il lui restait " << p1.getVie() << " points de vie" << endl;
	}

	if (p2.estVivant()) { // Cas où Druide est gagnant
		cout << "Le Druide " << nomDruide << " a gagné!" << endl;
		cout << "Il lui restait " << p2.getVie() << " points de vie" << endl;
	}
	/************* FIN DE LA DÉTERMINATION DU GAGNANT ***********/

	system("PAUSE");

	return 0;
}