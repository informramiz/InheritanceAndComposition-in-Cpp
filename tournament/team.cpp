#include "team.h"

Team::Team ( )
{
	noOfPlayers = 0 ;
}

Team::~Team ( )
{
	if ( players )
	{
		for ( int i = 0 ; i < getNoOfPlayers ( ) ; i++ )
			delete players[i];
	}

	id = 0;
}

Team::Team ( const Team & t )
{
	id = t.getId ( );
	for ( int i = 0 ; i < t.getNoOfPlayers ( ) ; i++ )
		insertPlayer ( t.players [i]->clone ( ) );
}

Team & Team::operator = ( const Team & t )
{
	if ( this == &t )
		return *this;

	for ( int i = 0 ; i < t.getNoOfPlayers ( ) ; i++ )
		insertPlayer ( t.players [i]->clone ( ) );

	return *this;
}

int Team::insertPlayer ( Player * p )
{
	if ( !isSpace ( ) )
		return 0;
	
	if ( isAlreadyInserted ( p->getId ( ) ) )
		return 0;

	players[ noOfPlayers ++ ] = p->clone ( ) ;
	return 1;
}

int Team::getSize ( ) const
{
	return SIZE;
}

int Team::isAlreadyInserted ( int id ) const
{
	for ( int i = 0 ; i < getNoOfPlayers ( ) ; i++ )
		if ( players[i]->isSameId ( id ) )
			return 1;

		return 0;
}

int Team::isSpace ( ) const
{
	return noOfPlayers < SIZE ;
}

int Team::getNoOfPlayers ( ) const
{
	return noOfPlayers;
}

int Team::removePlayer ( int id ) 
{
	int i = 0 ;

	while ( i < getNoOfPlayers ( ) && !players[i]->isSameId ( id ) )
		i++ ;

	if ( !players[i]->isSameId ( id ) )
		return 0;

	shiftPlayersLeft ( i );
	return 1;
}

void Team::shiftPlayersLeft ( int start ) 
{
	for ( int i = start ; i < getNoOfPlayers ( ) - 1 ; i++ )
		players[i] = players[ i + 1 ];

	noOfPlayers -- ;
}

void Team::printPlayer ( int id ) const
{
	int i = 0 ;

	while ( i < getNoOfPlayers ( ) && !players[i]->isSameId ( id ) )
		i ++ ;

	if ( !players[i]->isSameId ( id ) )
		cout << "Unknown id" << endl;

	players[i]->print ( );
}

void Team::printTeam ( ) const
{
	cout << "Team id: " << getId ( ) << endl;
	for ( int i = 0 ; i < getNoOfPlayers ( ) ; i++ )
	{
		players[i]->print ( );
		cout << endl;
	}
}

Player  Team::getBestBatsman ( ) const
{
	int max = 0 ;
	for ( int i = 0 ; i < getNoOfPlayers ( ) - 1 ; i++ )
	{
		if ( players[i]->getStatus ( ) < players[i + 1 ]->getStatus ( ) )
			max = i + 1;
	}

	return *players[max]; 
}

Player  Team::getBestBowler ( ) const
{
	int max = 0;

	for ( int i = 0 ; i < getNoOfPlayers ( ) - 1 ; i++ )
		if ( players[i]->getStatus ( ) < players[ i + 1]->getStatus ( ) )
			max = i + 1 ;

	return * players[ max ];
}

int Team::isSameId ( int value ) const
{
	return id == value ;
}

void Team::setId ( int value ) 
{
	id = value;
}

int Team::getId ( ) const
{
	return id;
}