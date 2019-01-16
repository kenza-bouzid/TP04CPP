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
#include <algorithm>

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

	return *this;
}//-- Fin de operator =

istream & operator >> ( istream & in, Log & log )
{
	// On recupere une ligne pour mieux gerer les erreurs de formats
	string ligne;
	getline(in, ligne, '\n');

	//--- Recuperation de la date
	// heure
	string::iterator deb = ++find(ligne.begin(), ligne.end(), ':');
	string::iterator fin = find(deb, ligne.end(), ':');
	if(fin >= ligne.end()) return in;
	log.date.heure = stoi(string(deb, fin));
	cout << stoi(string(deb, fin)) << endl;
	// minutes
	deb = ++fin;
	fin = find(deb, ligne.end(), ':');
	if(fin >= ligne.end()) return in;
	log.date.minutes = stoi(string(deb, fin));

	//--- Recuperation de la cible
	deb = find(fin, ligne.end(), '/');
	fin = find(deb, ligne.end(), ' ');
	if(fin >= ligne.end()) return in;
	log.cible = string(deb, fin);

	//--- Recuperation du refer
	deb = ++find(fin, ligne.end(), '"');
	deb = ++find(deb, ligne.end(), '"');
	fin = find(deb, ligne.end(), '"');
	if(fin >= ligne.end()) return in;
	log.refer = string(deb, fin);

	//--- Recuperation du type
	string::reverse_iterator rdeb = log.cible.rbegin();
	string::reverse_iterator rfin = find(rdeb, log.cible.rend(), '.');
	string type1(rdeb, rfin);
	cout << type1 << endl;

	rdeb = log.refer.rbegin();
	rfin = find(rdeb, log.refer.rend(), '.');
	string type2(rdeb, rfin);
	cout << type2 << endl;

	log.contenuIndispensable = Log::estContenuIndispensable(type1) ||
		Log::estContenuIndispensable(type2);

	return in;
}//--- Fin de operator >>


ostream & operator << ( ostream & out, const Log & log )
{
	out << log.date.heure << endl;
	out << log.date.minutes << endl;
	out << log.cible << endl;
	out << log.refer << endl;
	out << log.contenuIndispensable << endl;

	return out;
}


//---------------------------------------------- Constructeurs - Destructeur --
Log::Log ( Date laDate, string laCible, string leRefer, bool leContenuIndispensable ) : date(laDate), cible(laCible), refer(leRefer),
	contenuIndispensable(leContenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log" << endl;
#endif
}//--- Fin de Log


Log::Log ( const Log & log ) : date(log.date), cible(log.cible),
	refer(log.refer), contenuIndispensable(log.contenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log par copie" << endl;
#endif
}//--- Fin de Log


Log::~Log()
{
#ifdef MAP
	cout << "Destruction Log" << endl;
#endif
}//--- Fin de ~Log


///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --
bool Log::estContenuIndispensable ( string & extension )
{
	// L'extension est a l'envers a cause de l'utilisation de reverse_iterator
	//	dans operator >> !

	if( extension.compare("sj") == 0 )
	{
		return false;
	}
	else if( extension.compare("ssc") == 0 )
	{
		return false;
	}
	else if( extension.compare("gpj") == 0 )
	{
		return false;
	}
	else if( extension.compare("gepj") == 0 )
	{
		return false;
	}
	else if( extension.compare("gnp") == 0 )
	{
		return false;
	}

	return true;
}


