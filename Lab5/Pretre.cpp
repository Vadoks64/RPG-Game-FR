/************************************************************
* fichier : Pr�tre.cpp
* R�le : D�finition de la classe Pr�tre
* Auteur : �lie Charles D�saulniers
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

using namespace std;

Pretre::Pretre() : Personnage(), m_mana(15), m_vieMax(70){ // Constructeur par D�faiut
	m_vie = 70;
	m_classe = "Pr�tre";
	m_arme->changerArme("Marteau", 2, 12);
}

Pretre::Pretre(string nom) : Personnage(nom), m_mana(15), m_vieMax(70) { // Constructeur Surcharg�
	m_vie = 70;
	m_classe = "Pr�tre";
	m_arme->changerArme("Marteau", 2, 12);
}

Pretre::~Pretre() { // Destructeur
	
}

/**************************************************************************
* R�le : Afficher les stats du joueur
* Entr�e 1 : Aucune
* Sortie : Aucune
***************************************************************************/
void Pretre::affichageFormatee() const{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "Nom: ";
	SetConsoleTextAttribute(hConsole, 13);
	cout << Personnage::m_nom << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Classe: ";
	SetConsoleTextAttribute(hConsole, 14);
	cout << m_classe << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Points de vie: ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << m_vie << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Arme: ";
	SetConsoleTextAttribute(hConsole, 11);
	cout << m_arme->getNom();
	SetConsoleTextAttribute(hConsole, 15);
	cout << " (D�gats : " << m_arme->getDegatMin() << "-" << m_arme->getDegatMax() << ")" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Mana restante: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << m_mana << "\n" << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

/**************************************************************************
* R�le : Choix d'attaque du joueur
* Entr�e 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Pretre::choixAttaque(Personnage& p_cible) {
	cout << "*************************************************************************" << endl;
	cout << "Tour de: " << Personnage::m_nom << "\n" << endl;
	cout << "Choississez votre attaque :" << endl;
	cout << "1. Attaquer avec votre Marteau(2 - 12 de d�gats)" << endl;
	cout << "2. Sort de gu�risson(cout : 5 mana)(5 - 10 de soins)." << endl;
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
* R�le : Gu�rir le joueur s'il est en mesure de prendre une potion
* Entr�e 1 : Aucune
* Sortie : Aucune
***************************************************************************/
void Pretre::guerrison() {
	if (m_mana >= 5) {
		m_mana -= 5;
		int guerison = ((rand() % 10) + 5);
		if (m_vie + guerison >= m_vieMax) {
			guerison = (m_vieMax - m_vie);
		}
		m_vie += guerison;

		cout << "\n" << "Vous avez re�u " << guerison << " points de vie." << endl;
	}
	else {
		cout << "Vous n'avez pas assez de mana, vous perdez votre tour!" << endl;
	}
}