/******************************************************************************
		Lecture - Lecture d'un fichier de Log

	debut		: 2019-01-17
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Interface de la classe <Lecture> ----------
#ifndef LECTURE_H
#define LECTURE_H

////////////////////////////////////////////////////////// Interfaces utilisees
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "KeyLog.h"

using namespace std;
//------------------------------------------------------------------ Constantes
//----------------------------------------------------------------------- Types


//-----------------------------------------------------------------------------
//	Role de la classe <Lecture>
//	Permet de lire un fichier de Log et de creer une serie d'objet relies
//		aux logs (objets de type T)
//	T doit avoir un constructeur prenant en parametre un
//		vector<string>, qui contient toutes les informations du Log.
//	La gestion du flux d'entree (ouverture, fermeture) est a la gestion de
//		l'appelant !!
//-----------------------------------------------------------------------------
template < typename T >
class Lecture
{

//////////////////////////////////////////////////////////////////////// PUBLIC
public :
	//----------------------------------------------- Methodes publiques --
	vector < T > LectureLog ();
	// Mode d'emploi :
	//	Lit tous les Logs contenus dans le flux d'entree. Si une erreur est
	//		rencontree, annule toute la lecture et renvoie un vector vide.
	//	retour : le vector contenant tous les Log, au format specifie par
	//		l'utilisateur.
	// Contrat :
	//	Aucun contrat.


	//------------------------------------------- Surcharge d'operateurs --
	Lecture & operator = ( const Lecture & lecture );
	// Mode d'emploi :
	//	Operateur d'affectation de la classe Lecture.
	//	lecture : l'objet a copier.
	//	retour : reference sur l'objet courant, qui a ete affecte.
	// Contrat :
	//	Aucun contrat.


	//-------------------------------------- Constructeurs - Destructeur --
	Lecture ( istream * lEntree );
	// Mode d'emploi :
	//	Constructeur de la classe Lecture.
	//	lEntree : pointeur vers le flux utilise pour la lecture des Logs. Les
	//		verifications d'ouverture doivent avoir ete effectuees.
	//	La destruction du flux d'entree est a la charge de l'appelant !!!
	// Contrat :
	//	Aucun contrat.


	Lecture ( const Lecture & lecture );
	// Mode d'emploi :
	//	Constructeur de copie de la classe Lecture;
	// Contrat :
	//	Aucun contrat.


	virtual ~Lecture ();
	// Mode d'emploi :
	//	Destructeur de la classe Lecture.
	// Contrat :
	//	Aucun contrat.


///////////////////////////////////////////////////////////////////////// PRIVE
protected :
	//----------------------------------------------- Methodes protegees --
	vector < string > decoupageInformationsLog ();
	// Mode d'emploi :
	//	Lit une ligne du flux d'entree, et decoupe les informations importantes
	//		dans un vector.
	//	retour : le tableau qui contient le dcoupage.
	// Contrat :
	//	Aucun contrat.


	//----------------------------------------------- Attributs proteges --
	istream * entree;	// Flux d'entree qui contient tous les Logs a lire.


};

//-------------------------- Autres definitions dependantes de Lecture --------

//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
template < typename T >
vector < T > Lecture<T>::LectureLog ()
{
	vector < T > listeLogs;
	vector < string > informationsLog;

	if ( entree == nullptr )
		// Cas ou l'entree n'a pas ete renseignee comme il faut.
	{
		return listeLogs;
	}

	while ( entree -> good() )
	{
		informationsLog = decoupageInformationsLog ();
		if ( informationsLog.size() == 9 )
		{
			listeLogs.emplace_back ( informationsLog );
		}
		else	// Mauvaise lecture, donc on annule tout
		{
			cerr << "Le fichier de logs n'a pas le bon format ! Operaton annulee" << endl;
			return vector<T>();
		}
	}

	return listeLogs;
}//--- Fin de LectureLog


//--------------------------------------------------- Surcharge d'operateurs --
//---------------------------------------------- Constructeurs - Destructeur --
template < typename T >
Lecture<T>::Lecture ( istream * lEntree ) : entree ( lEntree )
{
#ifdef MAP
	cout << "Construction Lecture" << endl;
#endif
}//--- Fin de Lecture


template < typename T >
Lecture<T>::Lecture ( const Lecture & lecture ) : entree ( lecture.entree )
{
#ifdef MAP
	cout << "Construction Lecture par copie" << endl;
#endif
}//--- Fin de Lecture


template < typename T >
Lecture<T>::~Lecture ()
{
#ifdef MAP
	cout << "Destruction Lecture" << endl;
#endif
}//-- Fin de ~Lecture


///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --
template < typename T >
vector<string> Lecture<T>::decoupageInformationsLog ()
{
	string informations;
	getline(*entree, informations, '\n');
	vector<string> decoupage;

	// Adresse IP
	string::iterator deb = informations.begin();
	string::iterator fin = find(deb, informations.end(), ' ');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// user logname
	deb = ++fin;
	fin = find(deb, informations.end(), ' ');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// authenticated user
	deb = ++fin;
	fin = find(deb, informations.end(), ' ');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// date
	deb = ++find(fin, informations.end(), '[');	//pour sauter ' ['
	if(deb >= informations.end()) return decoupage;
	fin = find(deb, informations.end(), ']');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// cible
	deb = ++find(fin, informations.end(), '"');	//pour sauter '] "'
	if(deb >= informations.end()) return decoupage;
	fin = find(deb, informations.end(), '"');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// status
	deb = fin + 2;	//pour sauter '" '
	fin = find(deb, informations.end(), ' ');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// quantite de donnees
	deb = ++fin;
	fin = find(deb, informations.end(), ' ');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// referer
	deb = ++find(fin, informations.end(), '"');	//pour sauter ' "'
	if(deb >= informations.end()) return decoupage;
	fin = find(deb, informations.end(), '"');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// client navigateur
	deb = ++find(fin, informations.end(), '"');	//pour sauter '" "'
	if(deb >= informations.end()) return decoupage;
	fin = find(deb, informations.end(), '"');
	if(fin >= informations.end()) return decoupage;
	decoupage.emplace_back(deb, fin);

	// Autres informations
	deb = ++fin;
	if(deb >= informations.end()-1) return decoupage;		// Bonne situation
	return decoupage;
}//--- Fin de decoupageInformationLog



#endif // ifndef LECTURE_H
