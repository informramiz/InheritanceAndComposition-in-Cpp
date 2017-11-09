#include "String.h"
#include "DessertItem.h"
#include "DessertShope.h"

DessertItem::DessertItem ( )
{
	name = '\0';
}

DessertItem::DessertItem ( const CString & s )
{
	if ( s.getLength ( ) <= DessertShope::getMaxItemNameSize ( ) )
	{
		name = s;
	}
	else
		name = s.Left ( DessertShope::getMaxItemNameSize ( ) );
}

CString DessertItem::getName ( ) const
{
	return name;
}