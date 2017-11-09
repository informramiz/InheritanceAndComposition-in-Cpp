#include "Card.h"

Card::Card ( )
{
	name[0] = '\0';
}

Card::Card ( const CString & n , int num )
{
	name = n;
	number = num >= 0 ? num : 0;
}

void Card::setName ( const CString & n )
{
	name = n;
}

CString Card::getName ( ) const
{
	return name;
}

bool Card::isExpired ( ) const
{
	return false;
}

void Card::setNumber ( int num )
{
	number = num >= 0 ? num : 0;
}

int Card::getNumber ( ) const
{
	return number;
}


