
/*************************************************************************
                           Arc  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Arc> (fichier Arc.h) ----------------
#if ! defined ( Arc_H )
#define Arc_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Arc>
// Implémente le bout de l'arc refer et cardinalité
//
//------------------------------------------------------------------------

class Arc
{
//----------------------------------------------------------------- PUBLIC

public:
  	friend class GestionLog ;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Arc & operator = ( const Arc & unArc );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool operator < ( const Arc & unArc );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher(const string s = "")const;

//-------------------------------------------- Constructeurs - destructeur
    Arc ( const Arc & unArc );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Arc ( string unArc = "" , unsigned int card = 0 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Arc ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string referer;
  unsigned int cardinalite;
};

//-------------------------------- Autres définitions dépendantes de <Arc>

#endif // Arc_H
