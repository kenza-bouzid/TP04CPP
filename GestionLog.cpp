
/*************************************************************************
                           GestionLog  -  Gestion generale des Logs
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
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GestionLog::GenererGraphe ( ostream * out ) const
{
  string ecriture = "";

  // Sauvegarde des sommets
  unordered_map <string, int> sommets;
  int numeroSommet = 0;

  int sommetA, sommetB;

  // --- Ecriture de tous les arcs
  auto end = mapLog.cend();
  for ( auto i = mapLog.cbegin(); i != end; ++i)
  {
    if( sommets.find(i->first) == sommets.end() )
      //Insertion nouveau sommet
    {
      sommets.insert(make_pair(i->first, numeroSommet));
      sommetA = numeroSommet++;
    }
    else
    {
      sommetA = sommets[i->first];
    }

    if( sommets.find(i->second.referer) == sommets.end())
      //Insertion nouveau sommet
    {
      sommets.insert(make_pair(i->second.referer, numeroSommet));
      sommetB = numeroSommet++;
    }
    else
    {
      sommetB = sommets[i->second.referer];
    }

    // Ecriture
    ecriture = ecriture + "node" + to_string(sommetB) + " -> node" +
    to_string(sommetA) + " [label=\"" + to_string(i->second.cardinalite) + "\"];\n";
  }

  // --- Ecriture de tous les sommets
  for ( auto i = sommets.begin(); i != sommets.end(); ++i )
  {
    ecriture = "node" + to_string(i->second) + " [label=\"" + i->first
     + "\"];\n" + ecriture;
  }

  // --- Ecriture finale
  if ( out->good() )
  {
    *out << "digraph {\n" << ecriture << "}";
  }
} //----- Fin de GenererGraphe


void GestionLog::GenererMap (const unordered_map <KeyLog , unsigned int> & tableLogs)
{
    for (auto it = tableLogs.begin(); it != tableLogs.end(); ++it )
    {
      mapLog.emplace (make_pair(it->first.cible,Arc(it->first.referer,it->second)));
    }
} //----- Fin de GenererMap


void GestionLog::AfficherDixPopulaire()
{
  vector<Arc> listeArc = dixPopulaire();
  for (auto it = listeArc.begin(); it != (listeArc.begin()+10) && it != listeArc.end(); ++it)
  {
    it->Afficher();
  }
} //----- Fin de AfficherDixPopulaire


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
GestionLog::GestionLog ( const GestionLog & unGestionLog ) :
  mapLog (unGestionLog.mapLog)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog (constructeur de copie)


GestionLog::GestionLog (istream * fichierLog , ostream * out , int option ,
  Date heure , string fichierGraphe)
{

  Lecture <KeyLog,Log> lectureLog (fichierLog);
  unordered_map <KeyLog,unsigned int> tableLogs = lectureLog.LectureLog(option , heure);
  bool bitG = (option>>2) & 1 ;
  bool bitE = (option>>1) & 1 ;
  bool bitT = option & 1 ;

  GenererMap(tableLogs);

  if (bitE)
  {
      cout << "Suppression of files of type image, javascript, css" << endl;
  }

  if (bitT)
  {
      cout << "Warning : only hits between " << (string)heure<<" and " ;
      cout << (string)(heure+1) << " have been taken  into account" << endl;
  }

  if (bitG)
  {
      cout << "Dot-file " << fichierGraphe << " generated" << endl;
      GenererGraphe(out);
  }

  AfficherDixPopulaire();

#ifdef MAP
  cout << "Appel au constructeur de <GestionLog>" << endl;
#endif
} //----- Fin de GestionLog


GestionLog::~GestionLog ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionLog>" << endl;
#endif
} //----- Fin de ~GestionLog


//----------------------------------------------------- Méthodes protégées
size_t GestionLog::calculPopularite (string cible)
{
  auto range = mapLog.equal_range(cible);
  size_t count = 0 ;
  for (auto it = range.first; it != range.second ; ++it )
  {
    count+=it->second.cardinalite;
  }
  return count;
}//--- Fin de calculPopularite


vector<Arc> GestionLog::dixPopulaire ()
{
  unordered_map <string,unsigned int> mapTemp;
  for (auto it = mapLog.begin(); it != mapLog.end(); ++it)
  {
    if (mapTemp.find(it->first)==mapTemp.end())
    {
      mapTemp[it->first]=calculPopularite(it->first);
    }
  }

  vector <Arc> listeArc;
  for (auto it = mapTemp.begin(); it != mapTemp.end(); ++it)
  {
    listeArc.emplace_back(Arc(it->first, it->second));
  }
  sort(listeArc.begin() , listeArc.end()) ;
  return listeArc ;
}//--- Fin de dixPopulaire
