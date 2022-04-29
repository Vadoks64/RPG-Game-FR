/************************************************************
* fichier : fonctions.cpp
* R�le : Contenir les fonctions qui ne peuvent pas �tre associ�
*		 � une classe
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/


#include <iostream>

using namespace std;

/*
*Entr�e: Aucune
*Sortie: Aucune
*R�le: Afficher le message d'introduction et les instructions
*/
void affichageIntro() {
	cout << "Bienvenue dans le programme de combats en mode console !" <<"\n"<< endl;
	cout << "Ce jeu se joue � 2 joueurs 1 contre l'autre." << endl;
	cout << "Un des joueurs utilisera le pr�tre et l'autre le druide." << "\n" << endl;
	cout << "Apr�s avoir entr� le nom de chacun des personnages, vous allez d�marrer la partie." << "\n" << endl;
	cout << "Vous allez devoir combattre jusqu'� ce que le joueur ennemi n'ait plus de point de vie." << endl;
	cout << "Attention, jouez avec strat�gie avec la magie, car vous avez du mana, il est rapidement �puisable." << "\n" << endl;
	cout << "Bon, assez parl�. Place au combat!" << endl;
	system("PAUSE");
	system("cls");
}

/*
*Entr�e: Aucune
*Sortie: L'entr�e saisie par l'utilisateur
*R�le: Obtenir la saisie du joueur ainsi que v�rifier l'entr�e
*/
int saisieI() {
	int saisie(0);
	bool valide(false);

	while (!valide) { // V�rifie si l'entr�e est valide
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