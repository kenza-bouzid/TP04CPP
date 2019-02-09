/*************************************************************************
                           main  -  lancement du programme

	debut		: 2019-01-17
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Interface du module <main> (fichier main.h) -------------------
#if ! defined ( MAIN_H )
#define MAIN_H

//------------------------------------------------------------------------
// Rôle du module <main>
//	Permet de lancer le programme de lecture des Logs. Decortique les
//		parametres avec lesquels est lance le programme.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char * argv [] );
// Mode d'emploi :
//	Fonction qui est la porte d'entree du programme.
//	Il faut fournir des options aux programmes, en utilisant des commandes
//		lors du lancement de l'executable
//	agrc : le nombre de parametres lors du lancement du programme.
//	argv : le tableau qui contient ces parametres.
// Contrat :
//	Aucun contrat.

#endif // MAIN_H
