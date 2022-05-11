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
#include "Personnage.h"

#pragma once
class Guerrier : public Personnage {
public:
	Guerrier(std::string nom);
	~Guerrier();

	virtual void choixAttaque(Personnage*& p_cible);
	void chargePercutante(Personnage*& p_cible);
	virtual void affichageFormatee() const;
};