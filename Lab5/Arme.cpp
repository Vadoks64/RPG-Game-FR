/************************************************************
* fichier : Arme.cpp
* Rôle : Configuration de la classe Arme
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

#include <iostream>
#include <cstdlib>
#include "Arme.h"
#include <ctime>
#include <string>
using namespace std;

Arme::Arme() : m_nomArme("Bâton"), m_degatMin(1), m_degatMax(5) { // Constructeur par Défaut

}

Arme::Arme(string nom, int min, int max) : m_nomArme(nom), m_degatMin(min), m_degatMax(max) { // Constructeur Surchargé

}

Arme::~Arme() {

}

/*
Entrée: Aucune
Sortie: Le dégat minimal de l'arme
Rôle: Retourner la valeur du minimum que l'arme peut faire
*/
int Arme::getDegatMin() const {
	return m_degatMin;
}

/*
Entrée: Aucune
Sortie: Le dégat maximal de l'arme
Rôle: Retourner la valeur du maximal que l'arme peut faire
*/
int Arme::getDegatMax() const {
	return m_degatMax;
}

/*
Entrée: Aucune
Sortie: Le dégat minimal de l'arme
Rôle: Retourner la valeur du minimum que l'arme peut faire
*/
string Arme::getNom() const {
	return m_nomArme;
}

/*
Entrée: Aucune
Sortie: Le dégât que l'arme va infliger
Rôle: Définir aléatoirement le dégât de l'arme lors d'une attaque
*/
int Arme::degatAttaque() const{
	srand(time(NULL));
	int degat(0);
	degat = ((rand() % m_degatMax) + m_degatMin);
	return degat;
}

/*
Entrée: Aucunes
Sortie: Aucune
Rôle: Permet le changement d'arme d'une classe à l'autre
*/
void Arme::changerArme(string nomArme, int min, int max) {
	m_degatMin = min;
	m_degatMax = max;
	m_nomArme = nomArme;
}