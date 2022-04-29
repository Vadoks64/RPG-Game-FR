/************************************************************
* fichier : Arme.h
* Rôle : Header de la classe Arme
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Arme
* Rôle : La classe Armermet d'implanter le concept d'armes pour le joueur
* Attributs :
*	int m_degatMin; Dégâts minimum de l'arme
*	int m_degatMax; Dégât maximum de l'arme
*	std::string m_nomArme; Nom de l'arme définie
*
* Note : L'arme est initialisé par défaut avec un bâton
*
****************************************************************************/


#pragma once
#include <iostream>
#include <string>

class Arme {
	public:
		Arme();
		Arme(std::string nom, int min, int max);
		~Arme();

		int getDegatMin() const;
		int getDegatMax() const;
		std::string getNom() const;

		int degatAttaque() const;
		void changerArme(std::string nomArme, int min, int max);

	private:
		int m_degatMin;
		int m_degatMax;
		std::string m_nomArme;
};
