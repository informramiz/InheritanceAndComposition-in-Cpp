#include "IDcard.h"
#include "CallingCard.h"
#include "DriverLicense.h"



void main ( )
{
	CallingCard c( "Ramiz" , 2345 , 235 );

	Date date ( 1 , 2 , 1991 );
	DriverLicense d ( "Ahmad" , 3534 , date , 4 );
	
	IDcard id ( "Raja" , 34535 , date , date , "sdf" , 1 );

	Card *p[3] = { &c , &d , &id };

	for ( int i = 0 ; i < 3 ; i++ )
	{
		p[i]->print ( ) ;
		cout << endl << endl;
	}
}