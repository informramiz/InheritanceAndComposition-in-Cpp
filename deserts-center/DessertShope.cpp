#include "DessertShope.h"

const double DessertShope::taxRate = 6.5;
const CString DessertShope::storeName = "M & M Dessert shope";
const int DessertShope::maxItemNameSize = 25;
const int DessertShope::costWidth = 6;

CString DessertShope::cents2dollarsAndCents ( int cents )
{
	CString s = "";

	if ( cents < 0 )
	{
		s += "-";
		cents *= -1;
	}

	int dollars = cents / 100 ;
	cents = cents % 100;

	if ( dollars > 0 )
		s += dollars;

	s += ".";

	if ( cents < 10 )
		s += "0";

	s += cents;

	return s;
}

int DessertShope::getMaxItemNameSize ( )
{
	return maxItemNameSize;
}

int DessertShope::getCostWidth ( )
{
	return costWidth;
}

CString DessertShope::getStoreName ( )
{
	return storeName;
}

double DessertShope::getTaxRate ( )
{
	return taxRate;
}
