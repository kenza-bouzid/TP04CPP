
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GestionLog> (fichier GestionLog.h) ----------------
#if ! defined ( GESTIONLOG_H )
#define GESTIONLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionLog>
//
//
//------------------------------------------------------------------------

class GestionLog : public Ancetre
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

    calculNbOcc (map<string,int>);
    // Mode d'emploi :
    //
    // Contrat :
    //


    lectureLog ( ifstream & fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //


    sauvFichier(ofstream & fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //


//----------------------------------------------------- Attributs protégés
    map < string , map<string, int>> mapLog;
    struct date  {
      int heure;
      int time ;
    };
    bool optionE ;

};
//-------------------------------- Autres définitions dépendantes de <GestionLog>

#endif // GestionLog_H
