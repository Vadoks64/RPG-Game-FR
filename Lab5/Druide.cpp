/************************************************************
* fichier : Druide.cpp
* Rôle : Définition de la classe Druide
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/



#include "Druide.h"
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


Druide::Druide() : Pretre() { // Constructeur par Défaut
	m_vie = 60;
	m_vieMax = 60;
	m_classe = "Druide";
	m_mana = 30;
	m_arme->changerArme("Bâton", 1, 10);
}

Druide::Druide(string nom) : Pretre(nom) { // Constructeur surchargé
	m_vie = 60;
	m_vieMax = 60;
	m_classe = "Druide";
	m_mana = 30;
	m_arme->changerArme("Bâton", 1, 10);
}

Druide::~Druide() { // Destructeur

}

/**************************************************************************
* Rôle : Attaquer l'Adversaire avec une attaque spéciale
* Entrée 1 : Cible du joueur 
* Sortie : Aucune
***************************************************************************/
void Druide::attaqueCeleste(Personnage*& p_cible) { 
	if (m_mana >= 10) {
		int degats = ((rand() % 20) + 6);
		p_cible->recevoirDegats(degats);
		cout << "Vous avez fait " << degats << " points de dégâts" << endl;
		m_mana -= 10;
	}

	else
	{
		cout << "Vous n'avez pas assez de mana, vous perdez votre tour!" << endl;
	}
	
}

/**************************************************************************
* Rôle : Sélection de l'attaque que le joueur peut faire
* Entrée 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Druide::choixAttaque(Personnage*& p_cible) {
	cout << "*************************************************************************" << endl;
	cout << "Tour de: " << Personnage::m_nom << "\n" << endl;
	cout << "Choississez votre attaque :" << endl;
	cout << "1. Attaquer avec votre Bâton(1 - 10 de dégats)" << endl;
	cout << "2. Sort de guérisson(coût : 5 mana)(5 - 10 de soins)." << endl;
	cout << "3. Utiliser l'attaque Célèste (coût: 10)(5-25 dégâts)" << endl;
	cout << "Faite votre choix: ";

	int saisie = saisieI(3);

	switch (saisie)
	{
	case 1:
		attaqueArme(p_cible);
		break;
	case 2:
		guerrison();
		break;

	case 3:
		attaqueCeleste(p_cible);
		break;
	default:
		break;
	}
}