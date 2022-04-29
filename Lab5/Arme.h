/************************************************************
* fichier : Arme.h
* R�le : Header de la classe Arme
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Arme
* R�le : La classe Armermet d'implanter le concept d'armes pour le joueur
* Attributs :
*	int m_degatMin; D�g�ts minimum de l'arme
*	int m_degatMax; D�g�t maximum de l'arme
*	std::string m_nomArme; Nom de l'arme d�finie
*
* Note : L'arme est initialis� par d�faut avec un b�ton
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
