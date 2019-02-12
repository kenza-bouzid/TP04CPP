
/*************************************************************************
    KeyLog : cle sous forme de string, string

debut		: 2019-01-17
copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
e-mail		: kenza.bouzid@insa-lyon.fr
      pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <KeyLog> (fichier KeyLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "KeyLog.h"
//------------------------------------------------- Surcharge d'opérateurs
bool operator == (const KeyLog & unKeyLog1 , const KeyLog & unKeyLog2 )
  // surcharge de l'opérateur ==
{
  return ( (unKeyLog1.cible == unKeyLog2.cible)
            && (unKeyLog1.referer == unKeyLog2.referer)) ;
}// Fin de operator ==

 //-------------------------------------------- Constructeurs - destructeur
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
