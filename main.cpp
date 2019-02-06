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
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "main.h"
#include "Log.h"
#include "Lecture.h"
#include "KeyLog.h"
#include "GestionLog.h"

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
static bool heureValide = false;

static bool optionGarderIndispensable; //Si il faut garder que les contenus
					// indispensables (hors image, css, javascript...)


//------------------------------------------------------ Fonctions privées
static void erreurOption ()
// Mode d'emploi :
//	Genere un message d'erreur indiquant que les parametres d'entree n'ont pas
//		le bon format.
//	Ferme le programme.
// Contrat :
//	Aucun contrat.
{
	cerr << "Mauvais format des parametres en entree !" << endl;
	exit(-1);
}


static void analyseArguments ( int argc, char * argv [])
// Mode d'emploi :
//	Permet d'analyser les arguments fournis lors de l'appel de l'executable,
//		et d'en deduire les options et le lancement du programme.
//	argc : le nombre de parametres
//	argv : tableau qui contient les parametres
{
	enum Option { RIEN, G, E, T };	//Pour savoir quelle option est en cours de traitement.
	Option optionEnCours = RIEN;

	if( argc == 1 )
	{
		cerr << "Format d'entree incorrect" << endl;
		cerr << "Pour obtenir de l'aide, utilisez la commande man ./analog_man"
			<< endl;
		exit(-1);
	}

	for (int i = 1; i < argc - 1; i++ )
	{
		if( *argv[i] == '-' && strlen(argv[i]) == 2)
		// Debut d'une option
		{
			switch(*(argv[i] + 1))
			{
				case 'g':
					if(optionCreationGraphe == true)	//Option deja rentree
					{
						erreurOption();
					}
					optionEnCours = G;
					optionCreationGraphe = true;
					break;
				case 'e':
					if(optionGarderIndispensable == true)
						//Option deja rentree
					{
						erreurOption();
					}
					optionEnCours = RIEN;
					optionGarderIndispensable = true;
					break;
				case 't':
					if(optionHeure == true)
						//Option deja rentree
					{
						erreurOption();
					}
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
				case G:
					if(! nomFichierGraphe.empty())	//Deja un nom de fichier
					{
						erreurOption();
					}

					nomFichierGraphe = argv[i];
					optionEnCours = RIEN;
					break;
				case RIEN:
					erreurOption();
					break;
				case T:
					// Decoupage de l'heure
					string stringHeure ( argv[i] );
					string::iterator separateur = find(stringHeure.begin(), stringHeure.end(), ':');

					if(separateur >= stringHeure.end())
					{
						cerr << "Mauvais format d'heure : HH:MM" << endl;
						exit(-1);
					}
					else
					{
						int h = Log::Strtoui(string(stringHeure.begin(), separateur));
						int m = Log::Strtoui(string(++separateur, stringHeure.end()));
						// On verifie que stoi ai bien donne les bonnes valeurs
						if( heure.heure == h || heure.minutes == m)
						{
							cerr << "Heure incorrecte !" << endl;
							exit(-1);
						}

						heure = Date(h, m);
						cout << heure << endl;
						heureValide = true;
					}

					optionEnCours = RIEN;
					break;

			}
		}
	}
	nomFichierLog = argv[argc - 1];

#ifdef MAP
	cout << "Description des entrees du main" << endl;
	cout << nomFichierLog << endl;
	cout << optionCreationGraphe << " : " << nomFichierGraphe << endl;
	cout << optionGarderIndispensable << endl;
	cout << optionHeure << " : " << heure << endl;
#endif

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
	else if (optionHeure && !heureValide)
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

	//Vecteur pour les options de gestion des logs
	int vecteurOption = optionCreationGraphe << 2 |
			optionGarderIndispensable << 1 |
			optionHeure;

	// Gestion du fichier de log
	ifstream in;
	in.open(nomFichierLog);
	if ( ! in )
	{
		cerr << "Impossible d'acceder au fichier de Log !" << endl;
		exit(-1);
	}
	else if (in.eof())
	{
		cerr << "Fichier de Logs vide !" << endl;
		exit(-1);
	}

	// Gestion du fichier pour le graphe
	//		Si l'option n'est pas demande, le fichier ne s'ouvre pas,
	//		car il y a erreur
	ofstream out;
	out.open(nomFichierGraphe, ios_base::trunc);

	if ( optionCreationGraphe )
	{
		if ( ! out )
		{
			cerr << "Impossible d'acceder au fichier pour ecrire le graphe !"
				<< endl;
			exit(-1);
		}
	}
	GestionLog g(&in,&out,vecteurOption, heure, nomFichierGraphe);
	}//--- Fin de main
