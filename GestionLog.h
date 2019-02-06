
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : 2019-01-16
    copyright            : (C) 2018 par K. BOUZID et P-Y. GENEST
    e-mail               : kenza.bouzid@insa-lyon.fr
  			  pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionLog> (fichier GestionLog.h) --------
#if ! defined ( GESTIONLOG_H )
#define GESTIONLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "Date.h"
#include "Log.h"
#include "Lecture.h"
#include "KeyLog.h"
#include "Arc.h"

//------------------------------------------------------------------------

// Rôle de la classe <GestionLog>
//  Implémente un gestionnaire de log exploitant les données extraites d'un
//  fichier de log à travers l'outil d'analyse des fichiers de log Apache
//   en utilisant une structure de données la plus optimale possible.
//
//------------------------------------------------------------------------

class GestionLog
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    void GenererGraphe ( ostream * out ) const ;
    // Mode d'emploi : permet de générer un graphe à partir de la table
    // de hashage de l'objet courant conformément aux conventions de GraphViz
    // out: le fichier de sortie du graphe
    // Contrat :Aucun contrat
    //
    void GenererMap(const unordered_map <KeyLog , unsigned int> & tableLogs);
    // Mode d'emploi : permet de générer la map qui représente notre structure
    // de données
    // tableLogs: une unordered_map contenant tous les KeyLog contenus dans
    // un fichier avec leur cardinalité 
    // log Apache , peut contenir des doublons ce qui nou spermettra de calcule
    // la cardinalité de chaque arc
    // Contrat : Aucun contrat
    //
    void AfficherDixPopulaire() ;
    // Mode d'emploi :
    // permet d'afficher les 10 plus populaires cible d'un fichier log Apache
    // affiche tous les logs si le fichier contient moins de 10 cibles
    // s'arrête au dixième si ex aequo
    // Contrat : Aucun contrat
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
    GestionLog (const GestionLog & unGestionLog );
    // Mode d'emploi :
  	//	Constructeur de copie de la classe GestionLog.
  	//	unGestionLog : le gestionnaire log a copier
  	// Contrat :
  	//	Aucun contrat.

    GestionLog (istream * fichierLog, ostream * out ,int option,
       Date heure, string fichierGraphe);
    // Mode d'emploi : Constructeur de la classe GestionLog
    // fichierlog: le fichier de lecture comprtant les logs
    // out : fichier de sortie d'écriture du graphe Viz
    // option : spécifie les options sélectionnées par l'utilisateur
    // nous gérons cela à l'aide du bitMasking . Les options étant -g, -e et -t.
    // option est interprétée en binaire : 3bits relatifs à chacune des options
    // sous forme de GET , le bit 0 étant l'option t...
    // heure: l'heure de sélection définie par l'utilisateur sur la console
    // fichierGraphe : le nom du fihcier du graphe
    // Contrat : Aucun contrat
    //

    ~GestionLog ();
    // Mode d'emploi :
    //  Destructeur de la classe GestionLog
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    size_t calculPopularite (string cible);
    // Mode d'emploi :
    // permet de calculer la popularité d'une cible donnée en faisant la somme
    // des cardinalites des différents arcs dans lesquels intervient la cible
    // cible: la cible en question
    // Contrat : Aucun contrat
    //
    vector<Arc> dixPopulaire ();
    // Mode d'emploi :
    // permet de classer des bouts d'arcs selon leur popularité, ici il s'agit
    // d'arc de type (cible-popularité)
    // vector<Arc> : un vector stockant les différentes cibles avec leur popularité
    // classées par ordre de popularité
    // Contrat :Aucun Contrat
    //


//----------------------------------------------------- Attributs protégés
    unordered_multimap<string,Arc> mapLog;
    // structure de données utilisée pour stocker les différentes informations
    // relatives aux logs et qui nous sont utiles pour les options -g -e -t et
    // par défaut
    // On utilise une unordered_map afin d'optimiser les algos de recherche
    // la clé de la map est de type string correspondant aux cibles
    // la valeur est de type Arc
};
//-------------------------------- Autres définitions dépendantes de <GestionLog>

#endif // GestionLog_H
