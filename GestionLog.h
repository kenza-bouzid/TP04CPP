
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : 2019-01-16
    copyright            : (C) 2018 par K. BOUZID et P-Y. GENEST
    e-mail               : kenza.bouzid@insa-lyon.fr
  			  pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionLog> (fichier GestionLog.h) ----------------
#if ! defined ( GESTIONLOG_H )
#define GESTIONLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionLog>
//
//
//------------------------------------------------------------------------

class GestionLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    GestionLog & operator = ( const GestionLog & unGestionLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GestionLog ( const GestionLog & unGestionLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionLog (int argc, char*argv []);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void calculNbOcc (map<string,int>);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void lectureLog ( ifstream & fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void sauvFichier(ofstream & fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //


//----------------------------------------------------- Attributs protégés
    map < string , map<string, int>> mapLog;
    Date date ;
    bool optionE ;

};
//-------------------------------- Autres définitions dépendantes de <GestionLog>

#endif // GestionLog_H
