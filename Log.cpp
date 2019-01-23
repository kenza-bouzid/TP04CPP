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
const string baseUrl = "http://intranet-if.insa-lyon.fr";
// URL de base a retirer au besoin.

//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
KeyLog Log::GetKey ( ) const
{
	return KeyLog ( cible, referer );
}//--- Fin de GetKey

//-------------------------------------------------- Surcharge d'operateurs --
Log & Log::operator = ( const Log & log )
{
	date = log.date;
	cible = log.cible;
	referer = log.referer;
	contenuIndispensable = log.contenuIndispensable;

	return *this;
}//-- Fin de operator =


Log & Log::operator = ( const vector<string> & informations )
{
	string laDate ( informations[3] );
	// Au format DD/MM/YYYY :HH:MM:SS DECALAGE

	string laCible ( informations[4] );
	// Au format OPERATION cible PROTOCOLE

	string leReferer ( informations[7] );
	// Au format NOM_DOMAINE/REFERER

	// --- Recuperation de la date
	// heure
	string::iterator deb = ++find ( laDate.begin(), laDate.end(), ':' );
	string::iterator fin = find ( deb, laDate.end(), ':' );
	if ( deb >= fin ) return *this;
	date.heure = stoi(string(deb, fin));

	// minutes
	deb = ++fin;
	fin = find ( deb, laDate.end(), ':' );
	if ( deb >= fin ) return *this;
	date.minutes = stoi ( string ( deb, fin ) );


	//--- Recuperation de la cible
	deb = ++find ( laCible.begin(), laCible.end(), ' ' );
	fin = find ( deb, laCible.end(), ' ' );
	if ( deb >= fin ) return *this;
	cible = string ( deb, fin );


	//--- Recuperation du referer
	// Base de l'url
	unsigned int posBaseURL = leReferer.find ( baseUrl );
	// On essaie de trouver la base dans la string

	// referer sans nom de domaine
	if( posBaseURL < leReferer.size() )
	{
		referer = string ( leReferer.begin() + posBaseURL, leReferer.end() );
	}
	else
	{
		referer = leReferer;
	}


	//--- Calcul pour savoir si le contenu est indispensable ou non
	deb = ++find ( referer.begin(), referer.end(), '.');
	string extension1 ("");	// Pour gerer le cas pas d'extension de fichier
	if ( deb < referer.end() )

	{
		extension1 = string ( deb, referer.end() );
	}

	deb = ++find ( cible.begin(), cible.end(), '.');
	string extension2 ("");	// Pour gerer le cas pas d'extension de fichier
	if ( deb < cible.end() )
	{
		extension2 = string ( deb, cible.end() );
	}

	contenuIndispensable = estContenuIndispensable ( extension1 ) &&
			estContenuIndispensable ( extension2 );

	return *this;
}


ostream & operator << ( ostream & out, const Log & log )
{
	out << "cible : " << log.cible << endl;
	out << "referer : " << log.referer << endl;
	out << "heure : " << log.date.heure << ":" << log.date.minutes << endl;
	out << "contenu : " << log.contenuIndispensable << endl;

	return out;
}

bool Log::operator < (const Log& log ) const
{
		return cible < log.cible ;
}//--- Fin de operator <

bool operator == (const Log& log1 , const Log& log2 )
{
	return !strcmp(log1.cible.c_str(),log2.cible.c_str()) ;
}// --- Fin de operator ==

//---------------------------------------------- Constructeurs - Destructeur --
Log::Log ( Date laDate, string laCible, string leReferer,
	bool leContenuIndispensable ) : date(laDate), cible(laCible),
	referer(leReferer), contenuIndispensable(leContenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log" << endl;
#endif
}//--- Fin de Log


Log::Log ( const Log & log ) : date(log.date), cible(log.cible),
	referer(log.referer), contenuIndispensable(log.contenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log par copie" << endl;
#endif
}//--- Fin de Log


Log::Log ( const vector<string> & informations ) : date(), cible(""),
	referer(""), contenuIndispensable(false)
{
#ifdef MAP
	cout << "Construction Log a partir liste informations" << endl;
#endif

	*this = informations;
}

/*Log::Log (string laCible ) : date () , cible (laCible) , referer (""),
	 baseReferer(""), contenuIndispensable(false)
{
	#ifdef MAP
		cout << "Construction Log fictif à partir d'une cible uniquement" << endl;
	#endif
}*/

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
	if( extension.compare("js") == 0 )
	{
		return false;
	}
	else if( extension.compare("css") == 0 )
	{
		return false;
	}
	else if( extension.compare("jpg") == 0 )
	{
		return false;
	}
	else if( extension.compare("jpeg") == 0 )
	{
		return false;
	}
	else if( extension.compare("png") == 0 )
	{
		return false;
	}

	return true;
}
