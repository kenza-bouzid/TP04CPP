
/*************************************************************************
                           KeyLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <KeyLog> (fichier KeyLog.h) ----------------
#if ! defined ( KEYLOG_H )
#define KEYLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

using namespace std ;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <KeyLog>
// Cette classe a deux rôles :
// 1- Elle implémente la clé de la table de hachage utilisée pour stocker les logs.
//  Chaque clé sera composée d'une cible et d'un referer.
//  Toutes les fonctions de la classe seront définies en inline afin d'éviter
//  les surcoûts liés aux appel de fonctions.
// 2- Elle implémente la structure de hachage utilisée
//
//------------------------------------------------------------------------

class KeyLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator == ( const KeyLog & unKeyLog1 , const KeyLog & unKeyLog2 );
    // Méthode inline : définition de la méthode dans l'interface à la fin de
    // de la définition de la classe
    // Mode d'emploi :
    //  Surcharge de l'opérateur ==
    // Contrat :
    // Aucun contrat


//-------------------------------------------- Constructeurs - destructeur

    KeyLog ( string uneCible, string unReferer);
    // Constructeur inline : définition du constructeur dans l'interface à la fin
    // de la définition de la classe KeyLog
    // Mode d'emploi : Constructeur de la classe Key
    //  uneCible : la cible de la clé
    // unReferer : le referer de la clé
    // Contrat :
    //  Aucun contrat

    KeyLog ( const KeyLog & unKeyLog );
    // Constructeur  par copie inline : définition du constructeur dans
    // l'interface à la fin de la définition de la classe KeyLog
    // Mode d'emploi : Constructeur de coie la classe Key
    //  unKeyLog : le keyLog à copier
    // Contrat :
    //  Aucun contrat

    virtual ~KeyLog ( );
    // Constructeur inline : définition du destructeur dans l'interface à la fin
    // de la définition de la classe
    // Mode d'emploi :
    //  destructeur de la classe KeyLog
    // Contrat :
    //  Aucun contrat

    friend struct hash<KeyLog> ;


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  string cible;
  string referer;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <KeyLog>

#endif // KEYLOG_H

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

//---------- Définition de la fonction de hashage ---------
// source : stackOverflow forum
namespace std
{
  template <>
  struct hash<KeyLog>
  {
    size_t operator()(const KeyLog& k) const
    {
      // Compute individual hash values for first, second and third
              // http://stackoverflow.com/a/1646913/126995
        size_t res = 17;
        res = res * 31 + hash<string>()( k.cible );
        res = res * 31 + hash<string>()( k.referer );
        return res;
    }
  };
}
