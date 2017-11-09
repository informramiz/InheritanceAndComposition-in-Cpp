#include "person.h"

Person::Person ( const CString & n , const CString & ad , const CString & c , const CString & s , int z )
{
	name = n;
	address = ad;
	city = c;
	state = s;
	zipCode = ( z >= 0 ) ? z : 0 ;
}

void Person::setName ( const CString & n )
{
	name = n;
}

CString Person::getName ( ) const
{
	return name;
}

void Person::setCity ( const CString & c )
{
	city = c;
}

CString Person::getCity ( ) const
{
	return city;
}

void Person::setAddress ( const CString & ad )
{
	address = ad;
}

CString Person::getAddress ( ) const
{
	return address;
}

void Person::setState ( const CString & s )
{
	state = s;
}

CString Person::getState ( ) const
{
	return state;
}

void Person::setZipCode ( int z )
{
	if ( z >= 0 )
		zipCode = z;
}

int Person::getZipCode ( ) const
{
	return zipCode;
}

void Person::print ( ) const
{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	cout << "City : " << city << endl;
	cout << "State : " << state << endl;
	cout << "Zip code : " << zipCode << endl;
}