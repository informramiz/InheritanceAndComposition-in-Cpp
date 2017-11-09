#include "player.h"

Player::Player ( const string & n , int i )
{
	name = n;
	id = ( i >= 0 ) ? i : 0 ;
}

Player::Player ( )
{
	name[0] = '\0';
	id = 0 ;
}

void Player::setName ( const string & n ) 
{
	name = n;
}

string Player::getName ( ) const
{
	return name;
}

void Player::setId ( int i ) 
{
	id = i;
}

int Player::getId ( ) const
{
	return id;
}

bool Player::isSameId ( int i ) const
{
	return ( getId ( ) == i );
}

void Player::print ( ) const
{
	cout << getName ( ) << endl;
	cout << "Id : " << getId ( ) << endl;

}