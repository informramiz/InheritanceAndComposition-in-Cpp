#include "bowler.h"

Bowler::Bowler ( const string & n , int i , int w )
	:Player ( n , i )
{
	wickets = ( w >= 0 ) ? w : 0 ;	
}

Bowler::Bowler ( )
{
	wickets = 0;	
}

Player * Bowler::clone ( ) const
{
	return new Bowler ( *this );
}

void Bowler::setWickets ( int w ) 
{
	if ( w >= 0 )
		wickets = wickets + w;
}

int Bowler::getStatus ( ) const
{
	return wickets;
}

void Bowler::increase ( int value )
{
	if ( value >= 0 )
		wickets = wickets + value;
}

void Bowler::print ( ) const
{
	cout << "Bowler : ";
	Player::print ( );
	cout << "Wickets : " << getStatus ( ) << endl;
}