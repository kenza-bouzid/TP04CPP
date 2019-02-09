/******************************************************************************
		Date - Conteneur pour une date (ici HH:MM)

	debut		: 2019-01-16
	copyright	: (C) 2018 par K. BOUZID et P-Y. GENEST
	e-mail		: kenza.bouzid@insa-lyon.fr
			  pierre-yves.genest@insa-lyon.fr
******************************************************************************/
//---------- Realisation de la classe <Date> ----------

////////////////////////////////////////////////////////////////////// INCLUDES
//--------------------------------------------------------- Includes systeme --
#include <iostream>

using namespace std;

//------------------------------------------------------ Includes personnels --
#include "Date.h"

//------------------------------------------------------------------ CONSTANTES


//////////////////////////////////////////////////////////////////////// PUBLIC
//------------------------------------------------------- Methodes publiques --
//-------------------------------------------------- Surcharge d'operateurs --
Date & Date::operator = ( const Date & date )
{
	heure = date.heure;
	minutes = date.minutes;

	return *this;
}//--- FIn de operator =


bool Date::operator < ( const Date & date ) const
{
	if ( heure < date.heure )
	{
		return true;
	}
	else if ( heure == date.heure )
	{
		return minutes < date.minutes;
	}
	else
	{
		return false;
	}
}//--- Fin de operator <


bool Date::operator >= ( const Date & date ) const
{
	return ! ( *this < date );
}//--- Fin de operator >=


Date & Date::operator += ( const Date & date )
{
	int retenue = (minutes + date.minutes) / 60;
	minutes = ( minutes + date.minutes ) % 60;
	heure  = ( heure + date.heure + retenue ) % 24;

	return *this;
}//--- Fin de operator +=


Date::operator string() const
{
	string dateString = to_string(heure) + "h";
	if(minutes != 0)
	{
		 dateString += to_string(minutes);
	}

	return dateString;
}//--- Fin de operator string


Date operator + ( const Date & date1, const Date & date2 )
{
	Date date ( date1 );
	date += date2;
	return date;
}//--- Fin de operator +


ostream & operator << ( ostream & out, const Date & date )
{
	out << date.heure << ":" << date.minutes << endl;
	return out;
}//--- Fin de operator <<


//---------------------------------------------- Constructeurs - Destructeur --
Date::Date ( int lHeure, int lesMinutes ) : heure(lHeure),
	minutes(lesMinutes)
{
#ifdef MAP
	cout << "Construction Date : heure=" << heure << " minutes="
		<< minutes << endl;
#endif
	// Gestion des heures et minutes negatives
	int retenue = minutes / 60;
	minutes = minutes % 60;

	if(minutes < 0)
	{
		minutes = 60 + minutes;
		retenue--;
	}

	heure = ( heure + retenue ) % 24;
	if ( heure < 0 )
	{
		heure = 24 + heure;
	}
}//--- Fin de Date


Date::Date ( const Date & date ) : heure(date.heure), minutes(date.minutes)
{
#ifdef MAP
	cout << "Construction Date par copie" << endl;
#endif
}//--- Fin de Date


Date::~Date ()
{
#ifdef MAP
	cout << "Destruction Date par copie" << endl;
#endif
}//--- Fin de ~Date
///////////////////////////////////////////////////////////////////////// PRIVE
//------------------------------------------------------- Methodes protegees --
