/* int main()
{
	ifstream f("anonyme.log");
	Lecture<Log> l(&f);
	vector<Log> v = l.LectureLog();
}*/
/*************************************************************************
                           main  -  lancement du programme

	debut		: 2019-01-17
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Réalisation du module <main> (fichier main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "main.h"
#include "Log.h"
#include "Lecture.h"

using namespace std;

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static string nomFichierLog;	// Nom de fichier qui contient les logs

static string nomFichierGraphe;	// Nom de fichier dans lequel ecrire le graphe
static bool optionCreationGraphe;	// Si l'option graphe est activee

static Date heure(-1, -1);	// Heure pour le creneau horaire specifie
static bool optionHeure;	// Si l'option de creneau horaire est activee

static bool optionGarderIndispensable;	//Si il faut garder que les contenus indispensables (hors image, css, javascript...)


//------------------------------------------------------ Fonctions privées
static void analyseArguments ( int argc, char * argv [])
// Mode d'emploi :
//	Permet d'analyser les arguments fournis lors de l'appel de l'executable,
//		et d'en deduire les options et le lancement du programme.
//	argc : le nombre de parametres
//	argv : tableau qui contient les parametres
{
	enum Option { RIEN, G, E, T };	//Pour savoir quelle option est en cours de traitement.
	Option optionEnCours = RIEN;
	nomFichierLog = "";
	nomFichierGraphe = "";


	for (int i = 1; i < argc; i++ )
	{
		if( *argv[i] == '-' && strlen(argv[i]) == 2)
		// Debut d'une option
		{
			switch(*(argv[i] + 1))
			{
				case 'g':
					optionEnCours = G;
					optionCreationGraphe = true;
					break;
				case 'e':
					optionEnCours = E;
					optionGarderIndispensable = true;
					break;
				case 't':
					optionEnCours = T;
					optionHeure = true;
					break;
				default:
					cerr << "Option inconnue -" << *(argv[i] + 1) << endl;
					exit(-1);
					break;
			}
		}
		else
		// Texte a recuperer
		{
			string graphe;
			switch ( optionEnCours )
			{
				case RIEN:
					nomFichierLog = nomFichierLog + " " + argv[i];
					break;
				case G:
					nomFichierGraphe = nomFichierGraphe + " " + argv[i];

					break;
				case E:
					nomFichierLog = nomFichierLog + " " + argv[i];
					graphe = argv[i];
					if(find(graphe.begin(), graphe.end(), '.') < graphe.end())
					{
						optionEnCours = RIEN;
					}
					optionEnCours = RIEN;
					break;
				case T:
					// Decoupage de l'heure
					string stringHeure ( argv[i] );
					string::iterator separateur =
						find(stringHeure.begin(), stringHeure.end(), ':');

					if(separateur >= stringHeure.end())
					{
						cerr << "Mauvais format d'heure : HH:MM" << endl;
						exit(-1);
					}
					else
					{
						heure = Date(
							stoi(string(stringHeure.begin(), separateur)),
							stoi(string(++separateur, stringHeure.end()))
							);

						// On verifie que stoi ai bien donne les bonnes valeurs
						if( (heure.heure == 0 || heure.heure == 0) && 
							find(stringHeure.begin(), stringHeure.end(), '0') <
								stringHeure.end() )
						{
							cerr << "Heure incorrecte !" << endl;
							exit(-1);
						}
					}

					optionEnCours = RIEN;
			}
		}
	}

	cout << nomFichierLog << endl;
	cout << optionCreationGraphe << " : " << nomFichierGraphe << endl;
	cout << optionGarderIndispensable << endl;
	cout << optionHeure << " : " << heure << endl;

	if ( nomFichierLog == "" )
	{
		cerr << "Pas de fichier de Log !" << endl;
		exit(-1);
	}
	else if (optionCreationGraphe && nomFichierGraphe == "")
	{
		cerr << "Pas de fichier ou creer le graphe !" << endl;
		exit(-1);
	}
	else if (optionHeure && heure.heure == -1)
	{
		cerr << "Pas de creneau horaire renseigne !" << endl;
		exit(-1);
	}

}//--- Fin de analyseArguments

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char * argv [] )
{

	analyseArguments ( argc, argv );
}//--- Fin de main

