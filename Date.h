/******************************************************************************
		Date -

	debut		: 2019-01-16
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Interface de la classe <Date> ----------
#ifndef DATE_H
#define DATE_H

////////////////////////////////////////////////////////// Interfaces utilisees
#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types


//-----------------------------------------------------------------------------
//	Role de la classe <Date>
//		Permet de stocker une date sous la forme d'une heure et de minutes.
//		Permet de comparer des dates entres elles.
//-----------------------------------------------------------------------------
struct Date
{

//////////////////////////////////////////////////////////////////////// PUBLIC
public :
	//----------------------------------------------- Methodes publiques --
	//------------------------------------------- Surcharge d'operateurs --
	Date & operator = (const Date & date );
	// Mode d'emploi :
	//	Operateur d'affectation de la classe
	//	date : la date a copier
	//	retour : reference sur la date qui a ete affectee.
	// Contrat :
	//	Aucun contrat.


	bool operator < ( const Date & date ) const;
	// Mode d'emploi :
	//	Permet de comparer la date entre deux dates. Compare heure et minutes.
	//	date : la date a comparer
	//	retour : suivant le resultat de la comparaison
	// Contrat :
	//	Aucun contrat.


	bool operator >= ( const Date & date ) const;
	// Mode d'emploi :
	//	Permet de comparer la date entre deux dates. Compare heure et minutes.
	//	date : la date a comparer
	//	retour : suivant le resultat de la comparaison
	// Contrat :
	//	Aucun contrat.


	Date & operator += ( const Date & date );
	// Mode d'emploi :
	//	Permet d'ajouter une date a la date courante.
	//	Sert aussi a ajouter des heures (en utilisant le constructeur).
	//	date : la date a ajouter.
	//	retour : reference sur la date qui a ete modifiee.
	// Contrat :
	//	Aucun contrat.

	operator string () const;
	// Mode d'emploi
	//	Permet de transformer la date en string pour l'affichage.
	//	retour : la date en format string
	// Contrat :
	//	Aucun contrat.

	friend Date operator + ( const Date & date1, const Date & date2 );
	// Mode d'emploi :
	//	Permet d'effectuer l'addition entre 2 dates (heures et minutes)
	//	Sert aussi a ajouter un date et des heures
	//	date1 : la premiere date.
	//	date2 : la deuxieme date.
	//	retour : une nouvelle date qui est la somme des deux precedentes.
	// Contrat :
	//	Aucun contrat.


	friend ostream & operator << ( ostream & out, const Date & date );
	// Mode d'emploi :
	//	Permet d'afficher une date a l'ecran (ou dans un fichier)
	//	out : le flux de sortie sur lequel on affiche la date
	//	date : la date a afficher
	//	retour : le flux de sortie (out)
	// Contrat :
	//	Aucun contrat.


	//-------------------------------------- Constructeurs - Destructeur --
	Date ( int lHeure = 0, int lesMinutes = 0 );
	// Mode d'emploi :
	//	Permet de creer une date
	//	lHeure : l'heure de la date.
	//	lesMinutes : les minutes de la date.
	// Contrat:
	//	Aucun contrat.


	Date ( const Date & date );
	// Mode d'emploi :
	//	Constructeur de copie de la classe Date.
	//	date : la date a copier.
	// Contrat :
	//	Aucun contrat.


	virtual ~Date();
	// Mode d'emploi :
	//	Destructeur de la classe Date.
	// Contrat :
	//	Aucun contrat.

	//----------------------------------------------- Attributs publics --
	int heure;		//Heure de la date
	int minutes;	//Minutes de la date

};

//-------------------------- Autres definitions dependantes de Date --------

#endif // ifndef DATE_H
