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


	//-------------------------------------- Constructeurs - Destructeur --
	Date ( char lHeure = 0, char lesMinutes = 0 );
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
	char heure;		//Heure de la date
	char minutes;	//Minutes de la date

};

//-------------------------- Autres definitions dependantes de Date --------

#endif // ifndef DATE_H
