/************************************************************
* fichier : Personnage.cpp
* Rôle : Définition de la classe personnage
* Auteur : Élie Charles Désaulniers
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

Personnage::Personnage() : m_vie(40), m_classe("Personnage"), m_nom("Tony"), m_arme(0){ // Constructeur par défauts
	m_arme = new Arme();
}

Personnage::Personnage(string nom) : m_nom(nom), m_vie(40), m_classe("Personnage"), m_arme(0){ //Constructeur Surchargé
	m_arme = new Arme();
}

Personnage::~Personnage() { // Destructeur
	delete m_arme;
}

/*
Entrée: Aucune
Sortie: Aucune
Rôle: Vérifier si le personnage est vivant
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
Entrée: Aucune
Sortie: Vie restante du personnage
Rôle: Accès à la vie du personnage
*/
int Personnage::getVie() const{
	return m_vie;
}

string Personnage::getNom() const {
	return m_nom;
}


/*
Entrée: Aucune
Sortie: Aucune
Rôle: Vérifier si le personnage est vivant
*/
void Personnage::recevoirDegats(int degats) {
	m_vie -= degats;
}


/*
Entrée: Une cible
Sortie: Aucune
Rôle: Infliger du dégât à l'adversaire
*/
void Personnage::attaqueArme(Personnage*& p_cible) {
	int degats = m_arme->degatAttaque();
	p_cible->recevoirDegats(degats);
	cout << "Vous avez fait " << degats << " points de dégats à votre adversaire" << endl;
}




