/************************************************************
* fichier : Druide.cpp
* R�le : D�finition de la classe Druide
* Auteur : �lie Charles D�saulniers
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


Druide::Druide() : Pretre() { // Constructeur par D�faut
	m_vie = 60;
	m_vieMax = 60;
	m_classe = "Druide";
	m_mana = 30;
	m_arme->changerArme("B�ton", 1, 10);
}

Druide::Druide(string nom) : Pretre(nom) { // Constructeur surcharg�
	m_vie = 60;
	m_vieMax = 60;
	m_classe = "Druide";
	m_mana = 30;
	m_arme->changerArme("B�ton", 1, 10);
}

Druide::~Druide() { // Destructeur

}

/**************************************************************************
* R�le : Attaquer l'Adversaire avec une attaque sp�ciale
* Entr�e 1 : Cible du joueur 
* Sortie : Aucune
***************************************************************************/
void Druide::attaqueCeleste(Personnage*& p_cible) { 
	if (m_mana >= 10) {
		int degats = ((rand() % 20) + 6);
		p_cible->recevoirDegats(degats);
		cout << "Vous avez fait " << degats << " points de d�g�ts" << endl;
		m_mana -= 10;
	}

	else
	{
		cout << "Vous n'avez pas assez de mana, vous perdez votre tour!" << endl;
	}
	
}

/**************************************************************************
* R�le : S�lection de l'attaque que le joueur peut faire
* Entr�e 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Druide::choixAttaque(Personnage*& p_cible) {
	cout << "*************************************************************************" << endl;
	cout << "Tour de: " << Personnage::m_nom << "\n" << endl;
	cout << "Choississez votre attaque :" << endl;
	cout << "1. Attaquer avec votre B�ton(1 - 10 de d�gats)" << endl;
	cout << "2. Sort de gu�risson(co�t : 5 mana)(5 - 10 de soins)." << endl;
	cout << "3. Utiliser l'attaque C�l�ste (co�t: 10)(5-25 d�g�ts)" << endl;
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