#include "CallingCard.h"

CallingCard::CallingCard ( )
{
	pin = 0;
}

CallingCard::CallingCard ( const CString & name , int num , int p ):Card ( name , num )
{
	pin = p >= 0 ? p : 0 ;
}

void CallingCard::setPin ( int value )
{
	pin = value >= 0 ? value : 0;
}

int CallingCard::getPin ( ) const
{
	return pin;
}

void CallingCard::print ( ) const
{
	cout << "Calling card : \n";
	cout << "Name : " << getName ( );
	cout << "\nId number : " << getNumber ( );
	cout << "\nPin : " << pin << endl;
}