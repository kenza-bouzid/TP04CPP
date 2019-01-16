
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    if (this != & unGestionLog)
    {
      delete 
    }
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


GestionLog::GestionLog ( )
// Algorithme :
//
{
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
