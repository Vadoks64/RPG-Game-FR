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
#include "Guerrier.h"
#include <Windows.h>


// Definition des couleurs de texte
const int BLANC = 15;
const int BLEU = 9;
const int MAUVE = 13;
const int BLEU_P = 11;
const int VERT = 10;
const int JAUNE = 14;

using namespace std;
const int vieMax(80);
bool utiliserCharge(false);

Guerrier::Guerrier(string nom) : Personnage(nom) { // Constructeur surchargé
	m_vie = 60;
	m_classe = "Guerrier";
	m_arme->changerArme("Épée Double", 5, 20);
}

Guerrier::~Guerrier() { // Destructeur

}

/**************************************************************************
* Rôle : Attaquer l'Adversaire avec une attaque spéciale
* Entrée 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Guerrier::chargePercutante(Personnage*& p_cible) {
	int degatsMax = 30;
	int degatsMin = 10;
	if (!utiliserCharge) {
		int degats = (rand() % ((degatsMax - degatsMin) + 1) + degatsMin);
		p_cible->recevoirDegats(degats);
		cout << "Vous avez fait " << degats << " points de dégâts" << endl;
		utiliserCharge = true;
	}
}

/**************************************************************************
* Rôle : Sélection de l'attaque que le joueur peut faire
* Entrée 1 : Cible du joueur
* Sortie : Aucune
***************************************************************************/
void Guerrier::choixAttaque(Personnage*& p_cible) {
	cout << "*************************************************************************" << endl;
	cout << "Tour de: " << Personnage::m_nom << "\n" << endl;
	cout << "Choississez votre attaque :" << endl;
	cout << "1. Attaquer avec votre épée double(5 - 20 de dégats)" << endl;

	if (!utiliserCharge) {
		cout << "2. Utiliser la Charge Percutante (10-30 dégâts)" << endl;
	}

	cout << "Faite votre choix: ";

	int saisie = saisieI(3);

	switch (saisie)
	{
	case 1:
		attaqueArme(p_cible);
		break;
	case 2:
		chargePercutante(p_cible);
		break;
	default:
		break;
	}
}

/**************************************************************************
* Rôle : Afficher les stats du joueur
* Entrée 1 : Aucune
* Sortie : Aucune
***************************************************************************/
void Guerrier::affichageFormatee() const {
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
}