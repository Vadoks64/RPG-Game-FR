/************************************************************
* fichier : fonctions.h
* R�le : Header de fonctions.cpp
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/
#include <vector>

#pragma once

void affichageIntro();
int saisieI(int nbInputs);
Personnage* creePersonnage(int i);
void tourJoueur(std::vector<Personnage*>& listeJoueurs, int tourJoueur);
int determinerGagnant(std::vector<Personnage*>& listeJoueurs);