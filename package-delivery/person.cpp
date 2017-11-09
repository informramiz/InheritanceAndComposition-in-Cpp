#include "person.h"

Person::Person ( const string & n , const string & ad , const string & c , const string & s , int z )
{
	name = n;
	address = ad;
	city = c;
	state = s;
	zipCode = ( z >= 0 ) ? z : 0 ;
}

void Person::setName ( const string & n )
{
	name = n;
}

string Person::getName ( ) const
{
	return name;
}

void Person::setCity ( const string & c )
{
	city = c;
}

string Person::getCity ( ) const
{
	return city;
}

void Person::setAddress ( const string & ad )
{
	address = ad;
}

string Person::getAddress ( ) const
{
	return address;
}

void Person::setState ( const string & s )
{
	state = s;
}

string Person::getState ( ) const
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