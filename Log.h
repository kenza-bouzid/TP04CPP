/******************************************************************************
		Log -  

	debut		: 2019-01-16
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Interface de la classe <Log> ----------
#ifndef LOG_H
#define LOG_H

////////////////////////////////////////////////////////// Interfaces utilisees
#include "Date.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types
//-----------------------------------------------------------------------------
//	Role de la classe <Log>
//		Permet de lire et de stocker les informations sinteressantes du Log 
//			(pour le TP)
//-----------------------------------------------------------------------------
class Log
{

//////////////////////////////////////////////////////////////////////// PUBLIC
public :
	//----------------------------------------------- Methodes publiques --
	//------------------------------------------- Surcharge d'operateurs --
	Log & operator = ( const Log & log );
	// Mode d'emploi :
	//	Operateur d'affectation de la classe Log.
	//	log : le Log a copier
	//	retour : le log affecte (*this)
	// Contrat :
	//	Aucun contrat.


	Log & operator = ( const vector<string> & informations );
	// Mode d'emploi :
	//	Affecte les valeurs des variables d'instances en fonction des 
	//		informations.
	//	informations : contient toutes les informations du Log (voir partie 2)
	//	retour : le Log affecte.
	// Contrat :
	//	informations doit contenir toutes les informations d'un Log,
	//		dans le bon ordre.


	friend ostream & operator << (ostream & out, const Log & log );
	// Mode d'emploi :
	//	Permet d'afficher le Log (sur une ligne), suivant le flux de sortie
	//		specifie.
	//	out : le flux de sortie sur lequel ecrire.
	//	log : le log a afficher
	//	retour : le flux de sortie apres ecriture.
	// Contrat :
	//	Aucun contrat.


	//-------------------------------------- Constructeurs - Destructeur --
	Log ( Date laDate = Date(), string laCible = "", string leReferer = "",
		string leBaseReferer = "", bool leContenuIndispensable = false);
	// Mode d'emploi :
	//	Constructeur de la classe Log
	//	laDate : la date du Log
	//	laCible : la cible du Log
	//	leReferer : le referer du Log
	//	leBaseReferer : la base du referer du Log
	//	leConteneuIndispensable : si le contenu est Image, JS, CSS -> false
	// Contrat :
	//	Aucun contrat.


	Log ( const Log & log );
	// Mode d'emploi :
	//	Constructeur de copie de la classe Log.
	//	log : le log a copier
	// Contrat : 
	//	Aucun contrat.


	Log ( const vector<string> & informations );
	// Mode d'emploi :
	//	Constructeur de la classe Log a partir d'informations.
	//	informations : liste de toutes les informations du Log (voir partie 2
	//		du TP)
	// Contrat :
	//	informations doit contenir toutes les caracteristiques du Log, dans le
	//		bon format.


	virtual ~Log ();
	// Mode d'emploi :
	//	Destructeur de la classe Log
	// Contrat :
	//	Aucun contrat.


///////////////////////////////////////////////////////////////////////// PRIVE
protected :
	//----------------------------------------------- Methodes protegees --
	static bool estContenuIndispensable ( string & extension );
	// Mode d'emploi :
	//	Determine si l'extension est reliee a des contenus CSS, Image, JS...
	//	type1 : l'extension de fichier
	//	retour : false si le string correspond a des extensions de type
	//		Image, CSS, JS...
	// Contrat :
	//	Aucun contrat.


	//----------------------------------------------- Attributs proteges --
	Date date;					// Horaire du Log

	string cible;				// Cible de la requete du Log

	string referer;				// referer (source) du Log (sans nom de
								// 	domaine)
	string baseReferer;			// le nom de domaine du referer

	bool contenuIndispensable;
		// false : CSS, Image, JS
		// true sinon

};

//-------------------------- Autres definitions dependantes de Log --------

#endif // ifndef LOG_H