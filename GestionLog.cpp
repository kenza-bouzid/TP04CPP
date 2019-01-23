
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

#include <algorithm>    // std::for_each

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
/*GestionLog & GestionLog::operator = ( const GestionLog & unGestionLog )
// Algorithme :
//
{
    if (this != &unGestionLog)
    {
       mapLog = unGestionLog.mapLog ;
    }
    return *this ;
} //----- Fin de operator =*/


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


GestionLog::GestionLog (istream * fichierLog , OptionGestionLog OptionLog , Date d)
// Algorithme :
//
{
  Lecture <KeyLog , Log> lectureLog (fichierLog);
  unordered_multimap <KeyLog,Log> tableLogs =  lectureLog.LectureLog();

  switch (OptionLog)
  {
    case RIEN:
      genereMap (tableLogs);
      break;
    case E :
      selectionParExtension (tableLogs) ;
      genereMap (tableLogs);
      break;
    case T :
      selectionParHeure (tableLogs,d) ;
      genereMap (tableLogs);
      break;
    case G :
      break;
    case ET:
      selectionParHeure (tableLogs,d);
      selectionParExtension (tableLogs);
      genereMap (tableLogs);
      break;
    case EG:
      selectionParExtension (tableLogs);
      genereMap (tableLogs);
      break;
    case ETG:
      selectionParExtension (tableLogs);
      selectionParHeure (tableLogs,d);
      genereMap (tableLogs);
      break;
    default:
      break;
  }
#ifdef MAP
    cout << "Appel au constructeur de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog*/


GestionLog::~GestionLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionLog>" << endl;
#endif
} //----- Fin de ~GestionLog*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


void GestionLog::genereMap (const unordered_multimap <KeyLog,Log> & tableLogs)
{
    unordered_map <KeyLog,unsigned int> mapTemp;
    for (auto it = tableLogs.begin(); it != tableLogs.end(); ++it)
    {
      mapTemp[it->first]++;
    }
    for (auto it = mapTemp.begin(); it != mapTemp.end(); ++it )
    {
      Arc arc (it->first.referer,it->second) ;
      mapLog.emplace (make_pair(it->first.cible,arc));
    }
}

void GestionLog::selectionParHeure ( unordered_multimap <KeyLog,Log> & tableLogs , Date date)
{
  unordered_multimap <KeyLog,Log>::iterator it ;
  for (it = tableLogs.begin(); it != tableLogs.end(); it++)
  {
    if (it->second.date< date || it->second.date>= (date + 1))
    {
      tableLogs.erase(it);
    }
  }
}

void GestionLog::selectionParExtension (unordered_multimap <KeyLog,Log> & tableLogs)
{
  unordered_multimap <KeyLog,Log>::iterator it ;
  for (it = tableLogs.begin(); it != tableLogs.end(); it++)
  {
    if (it->second.contenuIndispensable)
      {
        tableLogs.erase(it);
      }
  }
}

size_t GestionLog::calculPopularite (string cible)
{
  auto range = mapLog.equal_range(cible);
  size_t count = 0 ;
  for (auto it = range.first; it != range.second ; ++it )
  {
    count+=it->second.cardinalite;
  }
  return count;
}
