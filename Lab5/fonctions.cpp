/************************************************************
* fichier : fonctions.cpp
* R�le : Contenir les fonctions qui ne peuvent pas �tre associ�
*		 � une classe
* Auteur : �lie Charles D�saulniers
* Version : 1.0
* Date : 27/04/2022
*************************************************************/


#include <iostream>

using namespace std;

/*************************************************************
*Entr�e: Aucune
*Sortie: Aucune
*R�le: Afficher le message d'introduction et les instructions
**************************************************************/
void affichageIntro() {
	cout << R"(
	  __  __ _____ _     _____ _____    ___        
	 |  \/  | ____| |   | ____| ____|  ( _ )       
	 | |\/| |  _| | |   |  _| |  _|    / _ \/\     
	 | |  | | |___| |___| |___| |___  | (_>  <     
	 |_|  |_|_____|_____|_____|_____|__\___/\/   __
		 / ___| / _ \|  _ \ / ___| ____|  _ \ \ / /
		 \___ \| | | | |_) | |   |  _| | |_) \ V / 
		  ___) | |_| |  _ <| |___| |___|  _ < | |  
		 |____/ \___/|_| \_\\____|_____|_| \_\|_|  
                                               
                                               )"
		<< "\n";
	system("PAUSE");
	system("cls");
	cout << R"( 
*******************************************************************************************************
* Bienvenue dans mon jeu de combat en mode console !                                                  *
*                                                                                                     *
* Vous pouvez choisir d'incarner 3 r�les :                                                            *
* 1 - Un guerrier qui poss�de beaucoup d'endurance et de puissantes attaques physiques.               *
* 2 - Un pr�tre qui poss�de des pouvoirs de gu�rison, une bonne arme et une bonne endurance.          *
* 3 - Un druide moins endurant qui peut �galement se gu�rir et poss�de une puissante attaque magique. *
*                                                                                                     *
* A vous de choisir votre combattant...                                                               *
*******************************************************************************************************)" << "\n";
	system("PAUSE");
	system("cls");
}

/**********************************************************************
*Entr�e: Aucune
*Sortie: L'entr�e saisie par l'utilisateur
*R�le: Obtenir la saisie du joueur ainsi que v�rifier l'entr�e
***********************************************************************/
int saisieI(int nbInputs) {
	int saisie(0);
	bool valide(false);

	while (!valide) { // V�rifie si l'entr�e est valide
		cin >> saisie;
		if (cin.fail()) { // Affiche une erreur si l'utilisateur n'entre pas un nombre
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Erreur! Veuillez entrer un nombre valide!" << endl;
			valide = false;
		}
		else if (saisie <= nbInputs) {
			valide = true;
		}

		else {
			valide = false;
			cout << "Erreur! Veuillez entrer un nombre valide!" << endl;
		}

	}

	return saisie;
}

void creePersonnage() {

}