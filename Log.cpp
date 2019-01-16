/******************************************************************************
		Log -  

	debut		: 2019-01-16
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Realisation de la classe <Log> ----------

////////////////////////////////////////////////////////////////////// INCLUDES
//--------------------------------------------------------- Includes systeme --
#include <iostream>

using namespace std;

//------------------------------------------------------- Includes personnels -
#include "Log.h"
//------------------------------------------------------------------ CONSTANTES


//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
//-------------------------------------------------- Surcharge d'operateurs --
Log & Log::operator = ( const Log & log )
{
	date = log.date;
	cible = log.cible;
	refer = log.refer;
	contenuIndispensable = log.contenuIndispensable;
}//-- Fin de operator =


//---------------------------------------------- Constructeurs - Destructeur --
Log::Log ( Date laDate, string laCible, string leRefer, bool leContenuIndispensable ) : date(laDate), cible(laCible), refer(leRefer),
	contenuIndispensable(leContenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log" << endl;
#endif
}//--- Fin de Log




///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --


