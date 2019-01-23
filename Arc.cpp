
/*************************************************************************
                           Arc  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Arc> (fichier Arc.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Arc.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Arc::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Arc & Arc::operator = ( const Arc & unArc )
// Algorithme :
//
{
  if (this != &unArc)
  {
      referer = unArc.referer;
      cardinalite= unArc.cardinalite;
  }
  return *this ;
} //----- Fin de operator =

bool Arc::operator < ( const Arc & unArc )
{
  return cardinalite > unArc.cardinalite ;
}//----- Fin de operator <

void Arc::Afficher (const string s ) const
{
  if (s != "")
  {
    cout << s << endl ;
  }
  cout << referer << " (" << cardinalite << " hits)" << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Arc::Arc ( const Arc & unArc )
// Algorithme :
//
{
  referer = unArc.referer;
  cardinalite = unArc.cardinalite;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Arc>" << endl;
#endif
} //----- Fin de Arc (constructeur de copie)


Arc::Arc ( string unReferer  , unsigned int card ): referer(unReferer) ,
cardinalite(card)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Arc>" << endl;
#endif
} //----- Fin de Arc


Arc::~Arc ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Arc>" << endl;
#endif
} //----- Fin de ~Arc


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
