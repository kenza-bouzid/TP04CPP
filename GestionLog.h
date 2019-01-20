
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
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include "Date.h"
#include "Log.h"
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef enum {
   RIEN ,   // option par défaut : aficher sur la console sous forme textuelle
    // la liste des 10 documets les plus consultés par ordre décroissant de popularité
   E ,     // option d'exclusion des ficj=hiers de type image , css ou js
   T ,    // option permettant de ne prendre en compte que les hits qui sont dans
   // le crénau horaire correspondant à l'intervalle [heure, heure+1[
   ET , //  combinaison des deux options E et T
 } OptionGestionLog;
//------------------------------------------------------------------------

// Rôle de la classe <GestionLog>
//  Implémente les différentes options que proposent l'outil d'analyse des
//  fichiers de log Apache en utilisant une structure de données la plus
//  optimale possible.
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
  	//	Operateur d'affectation de la classe GestionLog .
  	//	unGestionLog : le gestionnairelog a copier
  	//	retour : le gestionnaire log affecte (*this)
  	// Contrat :
  	//	Aucun contrat.


//-------------------------------------------- Constructeurs - destructeur
    GestionLog ( const GestionLog & unGestionLog );
    // Mode d'emploi :
  	//	Constructeur de copie de la classe GestionLog.
  	//	unGestionLog : le gestionnaire log a copier
  	// Contrat :
  	//	Aucun contrat.


    GestionLog (istream * fichierLog , string OptionLog);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionLog ();
    // Mode d'emploi :
    //  Destructeur de la classe GestionLog
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    int calculNbOcc (const vector <Log> listeLogs, string cible );
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void genereMapParDefaut (const vector <Log> listeLogs ) ;
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void genereMapHeure (const vector <Log> listeLogs) ;
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void genereMapExclusion (const vector <Log> listeLogs) ;
    // Mode d'emploi :
    // permet de calculer
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
    map<string, int> mapLog;
    // structure de données utilisée pour stocker les différentes informations
    // relatives aux logs et qui nous sont utiles pour les options -e -t et
    // par défaut
    // la clé de la map est de type string correspondant aux cibles
    // la valeur est de type int correspondant au nombre de consultation de
    // chaque cible

};
//-------------------------------- Autres définitions dépendantes de <GestionLog>

#endif // GestionLog_H
