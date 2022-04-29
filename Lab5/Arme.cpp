/************************************************************
* fichier : Arme.cpp
* R�le : Configuration de la classe Arme
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

#include <iostream>
#include <cstdlib>
#include "Arme.h"
#include <ctime>
#include <string>
using namespace std;

Arme::Arme() : m_nomArme("B�ton"), m_degatMin(1), m_degatMax(5) { // Constructeur par D�faut

}

Arme::Arme(string nom, int min, int max) : m_nomArme(nom), m_degatMin(min), m_degatMax(max) { // Constructeur Surcharg�

}

Arme::~Arme() {

}

/*
Entr�e: Aucune
Sortie: Le d�gat minimal de l'arme
R�le: Retourner la valeur du minimum que l'arme peut faire
*/
int Arme::getDegatMin() const {
	return m_degatMin;
}

/*
Entr�e: Aucune
Sortie: Le d�gat maximal de l'arme
R�le: Retourner la valeur du maximal que l'arme peut faire
*/
int Arme::getDegatMax() const {
	return m_degatMax;
}

/*
Entr�e: Aucune
Sortie: Le d�gat minimal de l'arme
R�le: Retourner la valeur du minimum que l'arme peut faire
*/
string Arme::getNom() const {
	return m_nomArme;
}

/*
Entr�e: Aucune
Sortie: Le d�g�t que l'arme va infliger
R�le: D�finir al�atoirement le d�g�t de l'arme lors d'une attaque
*/
int Arme::degatAttaque() const{
	srand(time(NULL));
	int degat(0);
	degat = ((rand() % m_degatMax) + m_degatMin);
	return degat;
}

/*
Entr�e: Aucunes
Sortie: Aucune
R�le: Permet le changement d'arme d'une classe � l'autre
*/
void Arme::changerArme(string nomArme, int min, int max) {
	m_degatMin = min;
	m_degatMax = max;
	m_nomArme = nomArme;
}