
/*************************************************************************
                           KeyLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <KeyLog> (fichier KeyLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "KeyLog.h"
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
bool operator == (const KeyLog & unKeyLog1 , const KeyLog & unKeyLog2 )
  // surcharge de l'opérateur ==
{
  return ( (unKeyLog1.cible == unKeyLog2.cible)
            && (unKeyLog1.referer == unKeyLog2.referer)) ;
}



KeyLog::KeyLog( const string & uneCible, const string & unReferer) : 
  cible(uneCible) , referer (unReferer)
{
	#ifdef MAP
		cout << "Appel au constructeur de <KeyLog>" << endl;
	#endif

}//----- Fin de KeyLog

KeyLog::KeyLog ( const KeyLog & unKeyLog ) : cible (unKeyLog.cible) ,
    referer(unKeyLog.referer)
{
  #ifdef MAP
      cout << "Appel au constructeur de copie de <KeyLog>" << endl;
  #endif
} //----- Fin de KeyLog (constructeur de copie)


KeyLog::~KeyLog ( )
{
  #ifdef MAP
      cout << "Appel au destructeur de <KeyLog>" << endl;
  #endif
} //----- Fin de ~KeyLog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
