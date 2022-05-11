/************************************************************
* fichier : Druide.h
* Rôle : Header de la classe Druide
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Prêtre
* Rôle : La classe Druide permet d'implanter le concept de classe secondaire
* Attributs :
* 	Aucun
*
* Note : Cette classe servira de classe fille hérité de Prêtre pour le jeu
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