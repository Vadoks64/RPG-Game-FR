/************************************************************
* fichier : Personnage.cpp
* R�le : D�finition de la classe personnage
* Auteur : �lie Charles D�saulniers
* Version : 1.2
* Date : 27/04/2022
*************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <string>
#include <ctime>
#include "Arme.h"
#include "Personnage.h"
#include <cstdlib>
#include <Windows.h>

using namespace std;

Personnage::Personnage() : m_vie(40), m_classe("Personnage"), m_nom("Tony"), m_arme(0){ // Constructeur par d�fauts
	m_arme = new Arme();
}

Personnage::Personnage(string nom) : m_nom(nom), m_vie(40), m_classe("Personnage"), m_arme(0){ //Constructeur Surcharg�
	m_arme = new Arme();
}

Personnage::~Personnage() { // Destructeur
	delete m_arme;
}

/*
Entr�e: Aucune
Sortie: Aucune
R�le: V�rifier si le personnage est vivant
*/
bool Personnage::estVivant() {
	if (m_vie <= 0) {
		m_vie = 0;
		return false;
	}

	else {
		return true;
	}
}

/*
Entr�e: Aucune
Sortie: Vie restante du personnage
R�le: Acc�s � la vie du personnage
*/
int Personnage::getVie() const{
	return m_vie;
}

string Personnage::getNom() const {
	return m_nom;
}


/*
Entr�e: Aucune
Sortie: Aucune
R�le: V�rifier si le personnage est vivant
*/
void Personnage::recevoirDegats(int degats) {
	m_vie -= degats;
}


/*
Entr�e: Une cible
Sortie: Aucune
R�le: Infliger du d�g�t � l'adversaire
*/
void Personnage::attaqueArme(Personnage*& p_cible) {
	int degats = m_arme->degatAttaque();
	p_cible->recevoirDegats(degats);
	cout << "Vous avez fait " << degats << " points de d�gats � votre adversaire" << endl;
}




