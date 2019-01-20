
/*************************************************************************
                           GestionLog  -  description
                             -------------------
    début                : 2019-01-16
    copyright            : (C) 2018 par K. BOUZID et P-Y. GENEST
    e-mail               : kenza.bouzid@insa-lyon.fr
  			  pierre-yves.genest@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionLog> (fichier GestionLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GestionLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
GestionLog & GestionLog::operator = ( const GestionLog & unGestionLog )
// Algorithme :
//
{
    if (this != &unGestionLog)
    {
       mapLog = unGestionLog.mapLog ;
    }
    return *this ;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*GestionLog::GestionLog ( const GestionLog & unGestionLog )
  mapLog (unGestionLog.mapLog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog (constructeur de copie)*/


GestionLog::GestionLog (istream * fichierLog , OptionGestionLog OptionLog)
// Algorithme :
//
{
  Lecture <Log> lectureLog (fichierLog);
  vector <Log> listeLogs =  lectureLog.LectureLog();
  sort (listeLogs.begin(), listeLogs.end());
  switch (OptionLog)
  {
    case RIEN:
      break;
    case E :
      break;
    case T :
      break;
    case G :
      break;
    case ET:
      break;
    case EG:
      break;
    case ETG:
      break;
    default:
      break;
  }
#ifdef MAP
    cout << "Appel au constructeur de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog


GestionLog::~GestionLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionLog>" << endl;
#endif
} //----- Fin de ~GestionLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

// c'etait juste un essai je crois pas qu eje garderai tout ca mnt qu'on change d'optique
/*int GestionLog::calculNbOcc (const vector <Log> listeLogs, string cible)
{
  Log logFictif (cible);
  int nbOcc = 1;
  vector<Log>::iterator it ;

  if (it ==  listeLogs.end ())
  {
    return nbOcc;
  }

  for ( it=find (listeLogs.begin(), listeLogs.end (), logFictif) ;it !=listeLogs.end (); ++it)
  {
    if (!strcmp(it->cible.c_str() , cible.c_str()))
    {
      nbOcc ++ ;
    }
    else
    {
      return nbOcc;
    }
  }
  return nbOcc;
}

void GestionLog::genereMapParDefaut (const vector <Log> listeLogs ) ;
{

}
void GestionLog::genereMapExclusion (const vector <Log> listeLogs)
{

}

void GestionLog::genereMapHeure (const vector <Log> listeLogs) ;
{

}*/
