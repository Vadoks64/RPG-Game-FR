/************************************************************
* fichier : fonctions.cpp
* Rôle : Contenir les fonctions qui ne peuvent pas être associé
*		 à une classe
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/


#include <iostream>
#include "Personnage.h"
#include "Pretre.h"
#include "Druide.h"
#include "Guerrier.h"
#include <vector>

using namespace std;

/*************************************************************
*Entrée: Aucune
*Sortie: Aucune
*Rôle: Afficher le message d'introduction et les instructions
**************************************************************/
void affichageIntro() {
	cout << R"(
				  __  __ _____ _     _____ _____    ___        
				 |  \/  | ____| |   | ____| ____|  ( _ )       
				 | |\/| |  _| | |   |  _| |  _|    / _ \/\     
				 | |  | | |___| |___| |___| |___  | (_>  <     
				 |_|  |_|_____|_____|_____|_____|__\___/\/   __
					 / ___| / _ \|  _ \ / ___| ____|  _ \ \ / /
					 \___ \| | | | |_) | |   |  _| | |_) \ V / 
					  ___) | |_| |  _ <| |___| |___|  _ < | |  
					 |____/ \___/|_| \_\\____|_____|_| \_\|_|  
                                               
                                               )"
		<< "\n";
	system("PAUSE");
	system("cls");
	cout << R"( 
*******************************************************************************************************
* Bienvenue dans mon jeu de combat en mode console !                                                  *
*                                                                                                     *
* Vous pouvez choisir d'incarner 3 rôles :                                                            *
* 1 - Un guerrier qui possède beaucoup d'endurance et de puissantes attaques physiques.               *
* 2 - Un prêtre qui possède des pouvoirs de guérison, une bonne arme et une bonne endurance.          *
* 3 - Un druide moins endurant qui peut également se guérir et possède une puissante attaque magique. *
*                                                                                                     *
* A vous de choisir votre combattant...                                                               *
*******************************************************************************************************)" << "\n";
	system("PAUSE");
	system("cls");
}

/**********************************************************************
*Entrée: Aucune
*Sortie: L'entrée saisie par l'utilisateur
*Rôle: Obtenir la saisie du joueur ainsi que vérifier l'entrée
***********************************************************************/
int saisieI(int nbInputs) {
	int saisie(0);
	bool valide(false);

	while (!valide) { // Vérifie si l'entrée est valide
		cin >> saisie;
		if (cin.fail()) { // Affiche une erreur si l'utilisateur n'entre pas un nombre
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Erreur! Veuillez entrer un nombre valide!" << endl;
			valide = false;
		}
		else if (saisie <= nbInputs && saisie > 0) {
			valide = true;
		}

		else {
			valide = false;
			cout << "Erreur! Veuillez entrer une option valide!" << endl;
			cout << "Resaisissez votre choix: ";
		}

	}

	return saisie;
}

Personnage* creePersonnage(int i) {
	Personnage* joueur(0);
	string choix;
	string nom;
	bool estValide(false);

	cout << "Joueur " << (i+1) << endl;
	cout << "Choisissez votre nom:";
	cin >> nom;
	
	do{
		cout << "Choix de votre classe:" << endl;
		cout << "	1. Guerrier" << endl;
		cout << "	2. Prêtre" << endl;
		cout << "	3. Druide" << endl;
		cout << "Choisissez votre classe:";
		cin >> choix;
		if (choix == "1") {
			joueur = new Guerrier(nom);
			estValide = true;
		}

		else if (choix == "2") {
			joueur = new Pretre(nom);
			estValide = true;
		}

		else if (choix == "3") {
			joueur = new Druide(nom);
			estValide = true;
		}

		else {
			cout << "Erreur! " << choix << " n'est pas un choix valide!" << endl;
			estValide = false;
		}
	} while (!estValide);

	return joueur;
}

void tourJoueur(vector<Personnage*>& listeJoueurs, int tourJoueur) {
	int ennemi(0);

	if (tourJoueur == 1) {
		ennemi = 0;
	}
	else
	{
		ennemi = 1;
	}

	listeJoueurs[tourJoueur]->choixAttaque(listeJoueurs[ennemi]);

	system("PAUSE");
	system("cls");
	listeJoueurs[0]->affichageFormatee();
	listeJoueurs[1]->affichageFormatee();
	system("PAUSE");
}

int determinerGagnant(std::vector<Personnage*>& listeJoueurs) {
	for (int i = 0; i < listeJoueurs.size(); i++)
	{
		if (listeJoueurs[i]->estVivant()) {
			return i;
		}
	}
}
