#include "batsman.h"

Batsman::Batsman ( const string & n , int i , int score )
	:Player ( n , i )
{
	scores = ( score >= 0 ) ? score : 0;
}

Batsman::Batsman ( )
{
	scores = 0;
}

Player * Batsman::clone ( ) const
{
	return new Batsman ( *this );
}

void Batsman::setScores ( int value )
{
	if ( value >= 0 )
		scores = scores + value;
}

int Batsman::getStatus ( ) const
{
	return scores;
}

void Batsman::increase ( int value ) 
{
	if ( value >= 0 )
		scores = scores + value;
}

void Batsman::print ( ) const
{
	cout << "Batsman : ";
	Player::print ( );
	cout << "Scores : " << scores << endl ;
}

