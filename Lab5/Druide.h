/************************************************************
* fichier : Druide.h
* R�le : Header de la classe Druide
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Pr�tre
* R�le : La classe Druide permet d'implanter le concept de classe secondaire
* Attributs :
* 	Aucun
*
* Note : Cette classe servira de classe fille h�rit� de Pr�tre pour le jeu
*
****************************************************************************/

#include "Pretre.h"
#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include <string>
#pragma once
class Druide : public Pretre{
	public:
		Druide();
		Druide(std::string nom);
		~Druide();

		void choixAttaque(Personnage& p_cible);
		void attaqueCeleste(Personnage& p_cible);
};


