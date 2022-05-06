/************************************************************
* fichier : Prêtre.cpp
* Rôle : Définition de la classe Prêtre
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

#include "Pretre.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ostream>
#include "Personnage.h"
#include "fonctions.h"
#include "Pretre.h"
#include "Arme.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

// Definition des couleurs de texte
const int BLANC = 15;
const int BLEU = 9;
const int MAUVE = 13;
const int BLEU_P = 11;
const int VERT = 10;
const int JAUNE = 14;

using namespace std;

Pretre::Pretre() : Personnage(), m_mana(15), m_vieMax(70){ // Constructeur par Défaiut
	m_vie = 70;
	m_classe = "Prêtre";
	m_arme->changerArme("Marteau", 2, 12);
}

Pretre::Pretre(string nom) : Personnage(nom), m_mana(15), m_vieMax(70) { // Constructeur Surchargé
	m_vie = 70;
	m_classe = "Prêtre";
	m_arme->changerArme("Marteau", 2, 12);
}

Pretre::~Pretre() { // Destructeur
	
}

/**************************************************************************
* Rôle : Afficher les stats du joueur
* Entrée 1 : Aucune
* Sortie : Aucune
***************************************************************************/
void Pretre::affichageFormatee() const{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, BLANC);
	cout << "Nom: ";
	SetConsoleTextAttribute(hConsole, MAUVE);
	cout << Personnage::m_nom << endl;
	SetConsoleTextAttribute(hConsole, BLANC);
	cout << "Classe: ";
	SetConsoleTextAttribute(hConsole, JAUNE);
	cout << m_classe << endl;
	SetConsoleTextAttribute(hConsole, BLANC);
	cout << "Points de vie: ";
	SetConsoleTextAttribute(hConsole, VERT);
	cout << m_vie << endl;
	SetConsoleTextAttribute(hConsole, BLANC);
	cout << "Arme: ";
	SetConsoleTextAttribute(hConsole, BLEU_P);
	cout << m_arme->getNom();
	SetConsoleTextAttribute(hConsole, BLANC);
	cout << " (Dégats : " << m_arme->getDegatMin() << "-" << m_arme->getDegatMax() << ")" << endl;
	cout << "Mana restante: ";
	SetConsoleTextAttribute(hConsole, BLEU);
	cout << m_mana << "\n" << endl;
	SetConsoleTextAttribute(hConsole, BLANC);
}

/**************************************************************************
* Rôle : Choix d'attaque du joueur
* Entrée 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Pretre::choixAttaque(Personnage*& p_cible) {
	cout << "*************************************************************************" << endl;
	cout << "Tour de: " << Personnage::m_nom << "\n" << endl;
	cout << "Choississez votre attaque :" << endl;
	cout << "1. Attaquer avec votre Marteau(2 - 12 de dégats)" << endl;
	cout << "2. Sort de guérisson(cout : 5 mana)(5 - 10 de soins)." << endl;
	cout << "Faite votre choix: ";

	int saisie = saisieI(2);

	switch (saisie)
	{
		case 1:
			attaqueArme(p_cible);
			break;
		case 2:
			guerrison();
			break;
		default:
			break;
	}

}

/**************************************************************************
* Rôle : Guérir le joueur s'il est en mesure de prendre une potion
* Entrée 1 : Aucune
* Sortie : Aucune
***************************************************************************/
void Pretre::guerrison() {
	if (m_mana >= 5) {
		m_mana -= 5;
		int guerison = ((rand() % 5) + 6);
		if (m_vie + guerison >= m_vieMax) {
			guerison = (m_vieMax - m_vie);
		}
		m_vie += guerison;

		cout << "\n" << "Vous avez reçu " << guerison << " points de vie." << endl;
	}
	else {
		cout << "Vous n'avez pas assez de mana, vous perdez votre tour!" << endl;
	}
}