#include "TwoDayPackage.h"
#include "OverNightPackage.h"

void main ( )
{
	Person p1 ( "Ramiz" , "Anar kali" , "lhr" , "Pakistan" , 2343 );
	Person p2 ( "Ahmad" , "Jamun Abad" , "lhr" , "Pakistan" , 2435 );
	
	Person p3 ( "Fahad" , "Anar kali" , "lrh" , "Pakistan" , 4546 );
	Person p4 ( "Asim" , "Anar kali" , "lhr" , "Pakistan" , 3535 );

	TwoDayPackage tDay ( p1 , p2 , 30 , 40 , 50 );
	OverNightPackage oNight ( p3 , p4 , 30 , 40 , 12 );

	Package * packages [ 2 ] = { &tDay , &oNight };

	float shipCost = 0;

	for ( int i = 0 ; i < 2 ; i++ )
	{
		packages[i]->print ( );
		shipCost = shipCost + packages[i]->calculateCost ( );
		cout << endl << endl;
	}

	cout << "\nTotal shipping cost : " << shipCost << endl;
}