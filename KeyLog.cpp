
/*************************************************************************
                           KeyLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <KeyLog> (fichier KeyLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "KeyLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
inline bool operator == (const KeyLog & unKeyLog1 , const KeyLog & unKeyLog2 )
  // surcharge de l'opérateur ==
{
  return (   (unKeyLog1.cible == unKeyLog2.cible)
            && (unKeyLog1.referer == unKeyLog2.referer)) ;
}

inline KeyLog::KeyLog ( const KeyLog & unKeyLog ) : cible (unKeyLog.cible) ,
    referer(unKeyLog.referer)
{
  #ifdef MAP
      cout << "Appel au constructeur de copie de <KeyLog>" << endl;
  #endif
} //----- Fin de KeyLog (constructeur de copie)

inline KeyLog::KeyLog ( string uneCible, string unReferer) : cible (uneCible) ,
    referer (unReferer)
{
  #ifdef MAP
      cout << "Appel au constructeur de <KeyLog>" << endl;
  #endif
} //----- Fin de KeyLog

inline KeyLog::~KeyLog ( )
{
  #ifdef MAP
      cout << "Appel au destructeur de <KeyLog>" << endl;
  #endif
} //----- Fin de ~KeyLog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
