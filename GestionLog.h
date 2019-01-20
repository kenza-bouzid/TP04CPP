
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
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
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
   G ,  // option graph VIZ
   ET , //  combinaison des deux options E et T
   EG , //  combinaison des deux options E et G
   TG , //  combinaison des deux options G et G
   ETG, //  combinaison de toutes les options
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


    GestionLog (istream * fichierLog , OptionGestionLog OptionLog ,
       Date date = Date ());
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

// --- je mets la toutes les idées de fonctions que j'utiliserai
    int calculNbOcc (string cible);
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void genereMap(const unordered_multimap <KeyLog,Log> & tableLogs);
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void selectionParHeure ( unordered_multimap <KeyLog,Log> & tableLogs , Date heure ) ;
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //

    void selectionParExtension (unordered_multimap <KeyLog,Log> & tableLogs) ;
    // Mode d'emploi :
    // permet de calculer
    // Contrat :
    //


//----------------------------------------------------- Attributs protégés
    unordered_map<KeyLog,int> mapLog;
    // structure de données utilisée pour stocker les différentes informations
    // relatives aux logs et qui nous sont utiles pour les options -g -e -t et
    // par défaut
    // On utilise une ordered_map afin d'optimiser les algos de recherche
    // la fonction de hashage utilisée est spécifiée dans le .h car il s'agit
    // d'une specialisation template de la sctructure de hashage définie
    // la clé de la map est de type string correspondant aux cibles
    // la valeur est à son tour une unordered_map de clé refer
    // et de valeur: la cardinalité de chaque arc


};
//-------------------------------- Autres définitions dépendantes de <GestionLog>

#endif // GestionLog_H

//---------- Définition de la fonction de hashage ---------
/*namespace std
{
  template <>
  struct hash<string>
  {
    // fonction de décalage de bit circulaire
    unsigned int shift_rotate(unsigned int val, unsigned int n)
    {
      n = n%(sizeof(unsigned int)*8);
      return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
    }
    // fonction d'encodage d'une chaîne de caractères
    unsigned int Encode(string key)
    {
       unsigned int i;
       unsigned int val = 0;
       unsigned int power = 0;
       for (i=0;i<strlen(key);i++)
       {
         val += shift_rotate(key[i],power*7);
         power++;
       }
       return val;
    }
    // fonction de hachage simple qui prend le modulo
    unsigned int hash(unsigned int val, unsigned int size)
    {
       return val%size;
    }
    // fonction de hachage complète à utiliser
    unsigned int HashFunction(string key, unsigned int size)
    {
       return hash(Encode(key),size);
    }
    // Surgarche de l'opérateur ()
    size_t operator()(const string& s) const
    {
        return HashFunction(s,strlen(s));
    }
  };
}*/
