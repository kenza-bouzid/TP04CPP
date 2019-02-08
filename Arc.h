
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
//------------------------------------------------------------------------
// Rôle de la classe <Arc>
// Implémente le bout de l'arc refer et cardinalité
// Cette classe peut être utilisée pour représenter un bout d'arc (referer-card)
// ainsi qu'un bout (cible-referer)
//------------------------------------------------------------------------
class Arc
{
//----------------------------------------------------------------- PUBLIC
public:
  	friend class GestionLog;
    // la Classe GestionLog pourra accéder aux attributs de la classe courante
//------------------------------------------------- Surcharge d'opérateurs
    Arc & operator = ( const Arc & unArc );
    // Mode d'emploi : Surcharge de l'opérateur = de la classe Arc
    // Contrat : Aucun contrat
    //

    bool operator < ( const Arc & unArc );
    // Mode d'emploi : Surcharge de l'opérateur < de la classe Arc
    // Contrat : Aucun contrat
    //

    void Afficher(const string s = "")const;
    // Mode d'emploi : permet d'afficher un bout d'arc.
    // Dans ce contexte, l'affichage est personnalisé pour un type d'arc
    // (cible-card)
    // s : chaine de caract permettant d'ajuter une spécification d'affichage
    // si besoin. Elle est égale à la chaine vide par défaut
    // Contrat : Aucun contrat
    //

//-------------------------------------------- Constructeurs - destructeur
    Arc ( const Arc & unArc );
    // Mode d'emploi (constructeur de copie) : permet la création d'une instance
    // d'arc par copie. On aurait pu s'en passer car contexte statique,
    // le compilateur peut fournir le bon constructeur de copie à notre place.
    // Pour des raisons de respect de forme canonique d'une classe
    // nous l'implémentons quand même.
    // unArc: objet à partr du quel nous créons une nouvelle instance de Arc
    // par copie.
    // Contrat : Aucun constrat
    //

    Arc ( string unRefere = "" , unsigned int card = 0 );
    // Mode d'emploi : Coonstructeur de la classe Arc
    // unReferer: le referer et éventuellement une cible
    // card : la cardinalité associé à l'arc
    // Contrat : Aucun constrat
    //

    ~Arc ( );
    // Mode d'emploi : Destructeur de Arc, aucune spécification car contexte
    // statique
    // Contrat : Aucun constrat
    //

//------------------------------------------------------------------ PRIVE
protected:

//----------------------------------------------------- Méthodes protégées
    bool compare_nocase (string first, string second);
    //Mode d'emploi: permet de trier les arcs par ordre alphabétique de Referer
    // dans le cas d'égalité des cardinalités
    // first: le premier referer à comparer
    // second : le deuxième
    // retourne un booléen indiquant si first > second
    // Contrat: Aucun Contrat
    //

//----------------------------------------------------- Attributs protégés
  string referer;
  unsigned int cardinalite;
};

#endif // Arc_H
