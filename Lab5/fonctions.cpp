/************************************************************
* fichier : fonctions.cpp
* Rôle : Contenir les fonctions qui ne peuvent pas être associé
*		 à une classe
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/


#include <iostream>

using namespace std;

/*
*Entrée: Aucune
*Sortie: Aucune
*Rôle: Afficher le message d'introduction et les instructions
*/
void affichageIntro() {
	cout << "Bienvenue dans le programme de combats en mode console !" <<"\n"<< endl;
	cout << "Ce jeu se joue à 2 joueurs 1 contre l'autre." << endl;
	cout << "Un des joueurs utilisera le prêtre et l'autre le druide." << "\n" << endl;
	cout << "Après avoir entré le nom de chacun des personnages, vous allez démarrer la partie." << "\n" << endl;
	cout << "Vous allez devoir combattre jusqu'à ce que le joueur ennemi n'ait plus de point de vie." << endl;
	cout << "Attention, jouez avec stratégie avec la magie, car vous avez du mana, il est rapidement épuisable." << "\n" << endl;
	cout << "Bon, assez parlé. Place au combat!" << endl;
	system("PAUSE");
	system("cls");
}

/*
*Entrée: Aucune
*Sortie: L'entrée saisie par l'utilisateur
*Rôle: Obtenir la saisie du joueur ainsi que vérifier l'entrée
*/
int saisieI() {
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
		else if (saisie == 1 || saisie == 2 || saisie == 3) {
			valide = true;
		}

		else {
			valide = false;
		}

	}

	return saisie;
}