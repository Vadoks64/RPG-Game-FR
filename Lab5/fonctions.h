/************************************************************
* fichier : fonctions.h
* Rôle : Header de fonctions.cpp
* Auteur : Élie Charles Désaulniers
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