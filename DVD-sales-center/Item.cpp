#include "Item.h"

Item::Item ( )
{
	description[0] = '\0';
	name[0] = '\0';
	price = 0;
}

Item::Item ( const CString & nm , const CString & descript , int p )
{
	name = nm;
	description = descript;
	price = p;
}

void Item::setName ( const CString & nm )
{
	name = nm;
}

CString Item::getName ( ) const
{
	return name;
}

void Item::setDescription ( const CString & d )
{
	description = d;
}

CString Item::getDescription ( ) const
{
	return description;
}

void Item::setPrice ( int p )
{
	price = p;
}

int Item::getPrice ( ) const
{
	return price;
}


