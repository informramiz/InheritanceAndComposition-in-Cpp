#include "Checkout.h"


Checkout::Checkout ( )
{
	
}

void Checkout::enterItem ( DessertItem * item )
{
	list.push ( item );
}

void Checkout::clear ( )
{
	list.clear ( );
}

int Checkout::numberOfItems ( ) const
{
	return list.getCapacity ( );
}

CString Checkout::toString ( ) const
{
	if ( list.isEmpty ( ) )
		return "Sorry, No items entered\n" ;

	CString string = DessertShope::getStoreName ( );
	string += "\n--------------------\n\n";

	for ( int i = 0 ; i < numberOfItems ( ) ; i++ )
	{
		string += list[i]->getName ( );
		string += "       ";

		string += DessertShope::cents2dollarsAndCents ( list[i]->getCost ( ) );
		string += "\n";
	}

	string += "Tax: ";
	string += totalTax ( );

	string += "\nTotal cost: ";
	string += totalCost ( );

	string += "\n\n";
	
	return string;
}

int Checkout::totalCost ( ) const
{
	int sum = 0;

	for ( int i = 0 ; i < numberOfItems ( ) ; i++ )
		sum = sum + list[0]->getCost ( );

	return sum;
}

int Checkout::totalTax ( ) const
{
	int sum = 0;

	for ( int i = 0 ; i < numberOfItems ( ) ; i ++ )
		sum = sum + ( int )DessertShope::getTaxRate ( );

	return sum;
}

ostream & operator << ( ostream & output , const Checkout & c )
{
	output << c.toString ( );
	return output;
}