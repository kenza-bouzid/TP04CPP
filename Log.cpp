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
	baseReferer = log.baseReferer;
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
	fin = find ( leReferer.begin(), leReferer.end(), ':') + 3;	// On saute ://
	if ( fin >= leReferer.end() ) return *this;
	fin = find ( fin, leReferer.end(), '/');	// On va a la fin de la base
												// 	de l'url
	deb = leReferer.begin();
	baseReferer = string ( deb, fin );

	// referer sans nom de domaine
	if( fin < leReferer.end() )
	{
		referer = string ( fin, leReferer.end() );
	}
	else
		// Cas : https://google.com
	{
		referer = "/";
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

/* istream & operator >> ( istream & in, Log & log )
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

	//--- Recuperation du referer
	deb = ++find(fin, ligne.end(), '"');
	deb = ++find(deb, ligne.end(), '"');
	fin = find(deb, ligne.end(), '"');
	if(fin >= ligne.end()) return in;
	log.referer = string(deb, fin);

	//--- Recuperation du type
	string::reverse_iterator rdeb = log.cible.rbegin();
	string::reverse_iterator rfin = find(rdeb, log.cible.rend(), '.');
	string type1(rdeb, rfin);
	cout << type1 << endl;

	rdeb = log.referer.rbegin();
	rfin = find(rdeb, log.referer.rend(), '.');
	string type2(rdeb, rfin);
	cout << type2 << endl;

	log.contenuIndispensable = Log::estContenuIndispensable(type1) ||
		Log::estContenuIndispensable(type2);

	return in;
}//--- Fin de operator >>*/


ostream & operator << ( ostream & out, const Log & log )
{
	out << "cible : " << log.cible << endl;
	out << "referer : " << log.baseReferer << " - " << log.referer << endl;
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
Log::Log ( Date laDate, string laCible, string leReferer, string leBaseReferer,
	bool leContenuIndispensable ) : date(laDate), cible(laCible),
	referer(leReferer), baseReferer(leBaseReferer),
	contenuIndispensable(leContenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log" << endl;
#endif
}//--- Fin de Log


Log::Log ( const Log & log ) : date(log.date), cible(log.cible),
	referer(log.referer), baseReferer ( log.baseReferer),
	contenuIndispensable(log.contenuIndispensable)
{
#ifdef MAP
	cout << "Construction Log par copie" << endl;
#endif
}//--- Fin de Log


Log::Log ( const vector<string> & informations ) : date(), cible(""),
	referer(""), baseReferer(""), contenuIndispensable(false)
{
#ifdef MAP
	cout << "Construction Log a partir liste informations" << endl;
#endif

	*this = informations;
}

Log::Log (string laCible ) : date () , cible (laCible) , referer (""),
	 baseReferer(""), contenuIndispensable(false)
{
	#ifdef MAP
		cout << "Construction Log fictif à partir d'une cible uniquement" << endl;
	#endif
}

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
