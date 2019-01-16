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
	//	retour : le log copie (*this)
	// Contrat :
	//	Aucun contrat.


	friend istream & operator >> ( istream & in, Log & log );
	// Mode d'emploi :
	//	Permet d'affecter les parametres de l'instance Log en lisant un Log
	//		Apache.
	//	in : le flux d'entree.
	//	log : le log a modifier
	//	retour : le flux d'entree.
	// Contrat :
	//	Aucun contrat.

	friend ostream & operator << (ostream & out, const Log & log );


	//-------------------------------------- Constructeurs - Destructeur --
	Log ( Date laDate = Date(), string laCible = "", string leRefer = "",
		bool leContenuIndispensable = false);
	// Mode d'emploi :
	//	Constructeur de la classe Log
	//	laDate : la date du Log
	//	laCible : la cible du Log
	//	leRefer : le refer du Log
	//	leConteneuIndispensable : si le contenu est Image, JS, CSS -> false
	// Contrat :
	//	Aucun contrat.


	Log ( const Log & log );
	// Mode d'emploi :
	//	Constructeur de copie de la classe Log.
	//	log : le log a copier
	// Contrat : 
	//	Aucun contrat.


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
	//	type1 : l'extension de fichier (en ordre inverse !)
	//	retour : false si le string correspond a des extensions de type
	//		Image, CSS, JS...
	// Contrat :
	//	Aucun contrat.


	//----------------------------------------------- Attributs proteges --
	Date date;					// Horaire du Log
	string cible;				// Cible de la requete du Log
	string refer;				// Refer (source) du Log
	bool contenuIndispensable;
		// false : CSS, Image, JS
		// true sinon

};

//-------------------------- Autres definitions dependantes de Log --------

#endif // ifndef LOG_H