/************************************************************
* fichier : Personnage.h
* R�le : Header de la classe Personnage
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Personnage
* R�le : La classe Personnage permet d'implanter le concept de personnage
* Attributs :
* 	int m_vie; Vie du personnage
	std::string m_nom; Nom du personnage
	std::string m_classe; Nom de la classe du personnage
	Arme *m_arme; Arme que le personnage poss�dera
*
* Note : Cette classe servira de classe m�re pour le jeu
*
****************************************************************************/

#pragma once
#include <iostream>
#include "Arme.h"

class Personnage{
public:
	Personnage();
	Personnage(std::string nom);
	~Personnage();


	void recevoirDegats(int degats);
	bool estVivant();
	void attaqueArme(Personnage& p_cible);
	std::string affichageFormatee() const;
	int getVie();

protected:
	int m_vie;
	std::string m_nom;
	std::string m_classe;
	Arme *m_arme;
};