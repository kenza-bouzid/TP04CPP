
/******************************************************************************
		Lecture - Lecture d'un fichier de Log

	debut		: 2019-01-17
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/

//---------- Interface de la classe <KeyLog> (fichier KeyLog.h) ----------------
#if ! defined ( KEYLOG_H )
#define KEYLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <functional>
#include <string>


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

struct KeyLog
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator == ( const KeyLog & unKeyLog1 , const KeyLog & unKeyLog2 );
    // Méthode inline : définition de la méthode dans l'interface à la fin de
    // de la définition de la classe
    // Mode d'emploi :
    //  Surcharge de l'opérateur ==
    // Contrat :
    // Aucun contrat


//-------------------------------------------- Constructeurs - destructeur

    KeyLog ( const string & uneCible, const string & unReferer);
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

    //----------------------------------------------------- Attributs publiques
      string cible;
      string referer;

};

//-------------------------------- Autres définitions dépendantes de <KeyLog>
namespace std {
template<>
class hash<KeyLog> {
public:
    size_t operator()(const KeyLog &k) const
    {
        size_t h1 = std::hash<std::string>()(k.cible);
        size_t h2 = std::hash<std::string>()(k.referer);
        return h1 ^ ( h2 << 1 );
    }
};
}
#endif // KEYLOG_H
