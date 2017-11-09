#include "Sundae.h"

Sundae::Sundae ( const CString & Iname , double cost , const CString & n , double tPrice )
 : IceCream ( Iname , cost )
{
	toppingCost = tPrice >= 0.0 ? tPrice : 0.0;
	name = n;
}

void Sundae::setToppingCost ( double value )
{
	if ( value >= 0.0 )
		toppingCost = value;
}

double Sundae::getToppingCost ( ) const
{
	return toppingCost;
}

int Sundae::getCost ( ) const
{
	return ( int )toppingCost + IceCream::getCost ( );
}