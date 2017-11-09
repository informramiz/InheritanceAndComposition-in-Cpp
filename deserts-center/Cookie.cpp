#include "Cookie.h"

Cookie::Cookie ( const CString & name , int n , double p ) : DessertItem ( name )
{
	number = n >= 0 ? n : 0;
	price = p >= 0.0 ? p : 0.0; 
}

void Cookie::setPrice ( double value )
{
	if ( value >= 0.0 )
		price = value;
}

double Cookie::getPrice ( ) const
{
	return price;
}

void Cookie::setNumber ( int value )
{
	if ( value >= 0 )
		number = value;
}

int Cookie::getNumber ( ) const
{
	return number;
}

int Cookie::getCost ( ) const
{
	return number * price;
}

