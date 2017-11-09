#include "IDcard.h"

IDcard::IDcard ( )
{
	occupation[0] = '\0';
	age = 1 ;
}

IDcard::IDcard ( const CString & name , int num , const Date & db , const Date & de , const CString & o ,
				int ag ):Card ( name , num ) , birthDate ( db ) , expirationDate ( de )
{
	occupation = o;
	age = age >= 1 ? age : 1;
}

void IDcard::setAge ( int value ) 
{
	age = value >= 1 ? value : 1 ;
}

int IDcard::getAge ( ) const
{
	return age;
}

void IDcard::setBirthDate ( const Date & value )
{
	birthDate = value;
}

Date IDcard::getBirthDate ( ) const
{
	return birthDate;
}

void IDcard::setExpirationDate ( const Date & value )
{
	expirationDate = value;
}

Date IDcard::getExpirationDate ( ) const
{
	return expirationDate;
}

void IDcard::setOccupation ( const CString & str )
{
	occupation = str;
}

CString IDcard::getOccupation ( ) const
{
	return occupation;
}

void IDcard::print ( ) const
{
	cout << "Id card\n";

	cout << "Name : " << getName ( ) << endl;
	cout << "ID number : " << getNumber ( ) << endl;
	cout << "Date of birth : " ;
	birthDate.print ( );

	cout << "Expiration date : ";
	expirationDate.print ( );

	cout << "Occupation: " << occupation << endl;
	cout << "Age : " << age << endl;
}


