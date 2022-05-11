/************************************************************
* fichier : Personnage.h
* Rôle : Header de la classe Personnage
* Auteur : Élie Charles Désaulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/

/**************************************************************************
* classe : Personnage
* Rôle : La classe Personnage permet d'implanter le concept de personnage
* Attributs :
* 	int m_vie; Vie du personnage
	std::string m_nom; Nom du personnage
	std::string m_classe; Nom de la classe du personnage
	Arme *m_arme; Arme que le personnage possèdera
*
* Note : Cette classe servira de classe mère pour le jeu
*
****************************************************************************/

#pragma once
#include <iostream>
#include "Arme.h"

class Personnage{
public:
	Personnage();
	Personnage(std::string nom);
	virtual ~Personnage();


	virtual void recevoirDegats(int degats);
	virtual bool estVivant();
	virtual void attaqueArme(Personnage*& p_cible);
	virtual void affichageFormatee() const = 0; 
	virtual void choixAttaque(Personnage*& p_cible) = 0;
	virtual int getVie() const;
	virtual std::string getNom() const;

protected:
	int m_vie;
	std::string m_nom;
	std::string m_classe;
	Arme *m_arme;
};