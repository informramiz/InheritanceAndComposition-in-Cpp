#include "IceCream.h"

IceCream::IceCream ( const CString & name ,  double value ):DessertItem ( name )
{
	cost = value >= 0.0 ? value : 0.0;
}

void IceCream::setCost ( double value )
{
	cost = value >= 0.0 ? value : 0.0;	
}

int IceCream::getCost ( ) const
{
	return cost;
} 

