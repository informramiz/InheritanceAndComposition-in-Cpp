#include "contact.h"

Contact::Contact ( const CString & nm , const CString & ad , const CString & ph )
{
	name = nm;
	address = ad;
	phoneNumber = ph;
}

Contact::Contact ( )
{
	name[0] = '\0';
	address[0] = '\0';
	phoneNumber[0] = '\0';
}

void Contact::setAddress ( const CString & ad )
{
	address = ad ;
}

CString Contact::getAddress ( ) const
{
	return address;
}

void Contact::setName ( const CString & n )
{
	name = n;
}

CString Contact::getName ( ) const
{
	return name;
}

void Contact::setPhoneNumber ( const CString & ph )
{
	phoneNumber = ph;
}

CString Contact::getPhoneNumber ( ) const
{
	return phoneNumber;
}