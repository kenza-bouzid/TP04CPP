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
const int tailleBaseUrl = baseUrl.size();
// URL de base a retirer au besoin.

//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
KeyLog Log::GetKey ( ) const
{
	return KeyLog ( cible, referer );
}//--- Fin de GetKey


bool Log::Strtoi ( const string & chaine, int * res )
{
	*res = 0;
	bool estNeg = false;	// Si le nombre est negatif

	if( chaine.size() == 0 )
	{
		return false;
	}

	string::const_iterator deb = chaine.cbegin();
	string::const_iterator fin = chaine.cend();

	if( *deb == '\0' )
	// Chaine vide
	{
		return false;
	}

	//Signe en debut de chaine
	if( *deb == '+' )
	{
		++deb;
	}
	else if ( *deb == '-' )
	{
		estNeg = true;
		++deb;
	}

	// Lecture du nombre
	while ( deb != fin && *deb != '\0' )
	{
		if ( *deb >= 48 && *deb <= 57)
		{
			*res = (*res) * 10 + (*deb - 48);
		}
		else
		{
			return false;
		}

		++deb;
	}

	if(estNeg)
	{
		*res = - *res;
	}
	return true;
}//--- Fin de Strtoi


int Log::Strtoui ( const string & chaine )
{
	int res = 0;
	string::const_iterator deb = chaine.cbegin();
	string::const_iterator fin = chaine.cend();

	if( *deb == '\0' )
	// Chaine vide
	{
		return -1;
	}

	while ( deb != fin && *deb != '\0' )
	{
		if ( *deb >= 48 && *deb <= 57)
		{
			res = res * 10 + (*deb - 48);
		}
		else
		{
			return -1;
		}

		++deb;
	}

	return res;
}//--- Fin de Strtoui


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
	if ( deb >= fin ) Lecture<Log, KeyLog>::ErreurLecture();
	date.heure = Strtoui ( string(deb, fin) );

	// minutes
	deb = ++fin;
	fin = find ( deb, laDate.end(), ':' );
	if ( deb >= fin ) Lecture<Log, KeyLog>::ErreurLecture();
	date.minutes = Strtoui ( string ( deb, fin ) );

	// Decalage horaire
	deb = ++find(fin, laDate.end(), ' ');
	if ( deb >= laDate.end() ) Lecture<Log, KeyLog>::ErreurLecture();
	int valDecalage;
	if ( ! Strtoi ( string ( deb, laDate.end() ), &valDecalage ) )
		Lecture<Log, KeyLog>::ErreurLecture();
	valDecalage = - valDecalage;
	Date decalage( valDecalage / 100, valDecalage % 100 );
	date += decalage;


	//--- Recuperation de la cible
	deb = ++find ( laCible.begin(), laCible.end(), ' ' );
	fin = find ( deb, laCible.end(), ' ' );
	if ( deb >= fin || fin >= laCible.end()) Lecture<Log, KeyLog>::ErreurLecture();
	cible = string ( deb, fin );


	//--- Recuperation du referer
	// Base de l'url
	unsigned int posBaseURL = leReferer.find ( baseUrl );
	// On essaie de trouver "intranet-if..." dans la string

	if( posBaseURL < leReferer.size() )
	{
		// On racourcit la string
		referer = string ( leReferer.begin() + tailleBaseUrl, leReferer.end() );
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
}//--- Fin de operator =


ostream & operator << ( ostream & out, const Log & log )
{
	out << "cible : " << log.cible << endl;
	out << "referer : " << log.referer << endl;
	out << "heure : " << log.date.heure << ":" << log.date.minutes << endl;
	out << "contenu : " << log.contenuIndispensable << endl;

	return out;
}//--- Fin de operator <<


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
}//--- Fin de Log


Log::~Log()
{
#ifdef MAP
	cout << "Destruction Log" << endl;
#endif
}//--- Fin de ~Log


///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --
static string extensions[] = { "js", "css", "jpg", "jpeg", "png", "ico", "bmp",
				"svg", "gif", "ics"};
const int TAILLE_EXTENSIONS = 10;

bool Log::estContenuIndispensable ( string & extension )
{
	for ( int i = 0; i < TAILLE_EXTENSIONS; i++ )
	{
		if ( extension.compare ( extensions[i] ) == 0 )
		{
			return false;
		}
	}

	return true;
}//--- Fin de estContenuIndispensable
