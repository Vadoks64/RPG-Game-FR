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
string Pretre::affichageFormatee() const{
	ostringstream os;
	os << Personnage::affichageFormatee();
	os << "Mana restante: " << m_mana;
	return os.str();
}

/**************************************************************************
* Rôle : Choix d'attaque du joueur
* Entrée 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Pretre::choixAttaque(Personnage& p_cible) {
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
		int guerison = ((rand() % 10) + 5);
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