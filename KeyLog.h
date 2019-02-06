
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
// 1- Elle implémente la clé de la table de hachage temporaire utilisée pour
//  stocker les infos qui sont utiles aux fonctionnalités de notre application.
//  Elle sert également de structure de transport de ces infos à partir de
//  du fichier de lecture.
//  Chaque clé sera composée d'une cible et d'un referer.
// 2- Elle implémente la spécialisation de la classe générique Hash de la stl
//  pour le type KeyLog
//------------------------------------------------------------------------

struct KeyLog
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator == ( const KeyLog & unKeyLog1, const KeyLog & unKeyLog2);
    // Mode d'emploi : Surcharge de l'opérateur ==
    // Cette surcharge est obligatoire car comparaison des clés par la table de
    // hashage
    // Contrat :
    // Aucun contrat

//-------------------------------------------- Constructeurs - destructeur
    KeyLog ( const string & uneCible, const string & unReferer);
    // Mode d'emploi : Constructeur de la classe Key
    //  uneCible : la cible de la clé
    // unReferer : le referer de la clé
    // Contrat :
    //  Aucun contrat

    KeyLog ( const KeyLog & unKeyLog );
    // Mode d'emploi : Constructeur de copie la classe Key
    //  unKeyLog : le keyLog à copier
    // Contrat :
    //  Aucun contrat

    ~KeyLog ( );
    // Mode d'emploi :
    // destructeur de la classe KeyLog
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
// spécialisation de classe Hash pour les types KeyLog 
#endif // KEYLOG_H
