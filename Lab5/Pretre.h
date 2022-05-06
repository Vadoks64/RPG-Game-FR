/************************************************************
* fichier : Pr�tre.h
* R�le : Header de la classe Pr�tre
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Pr�tre
* R�le : La classe Druide permet d'implanter le concept de classe secondaire
* Attributs :
* 	int m_mana; Mana du joueur
*	int m_vieMax; Vie maximum du joueur
*	std::string m_nom; Nom du joueur
*
* Note : Cette classe servira de classe fille h�rit� de Personnage pour le jeu
*
****************************************************************************/

#pragma once
#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include <string>

class Pretre : public Personnage {

	public:
		Pretre();
		Pretre(std::string nom);
		~Pretre();

		void guerrison();
		virtual void choixAttaque(Personnage*& p_cible);
		virtual void affichageFormatee() const;
	protected:
		int m_mana;
		int m_vieMax;
		std::string m_nom;
};