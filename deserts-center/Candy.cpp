#include "Candy.h"

Candy::Candy ( const CString & name , double w , double p ):DessertItem ( name )
{
	weight = w > 0.0 ? w : 1.0;
	price = p >= 0.0 ? p : 0.0;
}

void Candy::setPrice ( double value )
{
	if ( value >= 0.0 )
		price = value;
}

double Candy::getPrice ( ) const
{
	return price;
}

void Candy::setWeight ( double value )
{
	if ( value >= 1.0 )
		weight = value;
}

double Candy::getWeight ( ) const
{
	return weight;
}

int Candy::getCost ( ) const
{
	return weight * price;
}


