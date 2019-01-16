
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : 2019-01-16
    copyright            : (C) 2018 par K. BOUZID et P-Y. GENEST
    e-mail               : kenza.bouzid@insa-lyon.fr
  			  pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionLog> (fichier GestionLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GestionLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
GestionLog & GestionLog::operator = ( const GestionLog & unGestionLog )
// Algorithme :
//
{
    if (this != &unGestionLog)
    {
       date = unGestionLog.date;
       optionE = unGestionLog.optionE ;
       mapLog = unGestionLog.mapLog ;
    }
    return *this ;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GestionLog::GestionLog ( const GestionLog & unGestionLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog (constructeur de copie)


GestionLog::GestionLog (int argc, char*argv [])
// Algorithme :
//
{
    for ( int i = 1 ; i <= argc ; i ++)
    {
      if (strchr (argv [i] , '-'))
      {

      }  
    }
    #ifdef MAP
    cout << "Appel au constructeur de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog


GestionLog::~GestionLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionLog>" << endl;
#endif
} //----- Fin de ~GestionLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
