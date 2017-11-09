#include "Tournament.h"

Tournament::Tournament ( int s )
{
	totalTeams = ( s >= 0 ) ? s : 0 ;
	teams = new Team[totalTeams];

	noOfTeams = 0;
}

Tournament::Tournament ( const Tournament & t )
{
	for ( int i = 0 ; i < t.getNumberOfTeams ( ) ; i++ )
		insertTeam ( t.teams [i] );
}

Tournament::~Tournament ( )
{
	if ( teams )
	{
		delete [] teams;
		teams = 0;
	}
}

Tournament & Tournament::operator = ( const Tournament & t )
{
	if ( this == &t )
		return *this;

	delete [] teams;
	
	totalTeams = t.getTotalTeams ( );

	for ( int i = 0 ; i < totalTeams ; i++ )
		insertTeam ( t.teams [i] );

	return *this;
}

Player Tournament::getBestBatsman ( ) const
{
	int team = 0;

	for ( int i = 1 ; i < getNumberOfTeams ( ) ; i++ )
		if ( teams[ team ].getBestBatsman ( ).getStatus ( ) 
			< teams[i].getBestBatsman ( ).getStatus ( ) )
			team = i;
		
		return teams[ team].getBestBatsman ( );
}

Player Tournament::getBestBowler ( ) const
{
	int team = 0;

	for ( int i = 1 ; i < getNumberOfTeams ( ) ; i++ )
		if ( teams[ team ].getBestBowler ( ).getStatus ( ) 
			< teams[i].getBestBowler ( ).getStatus ( ) )
			team = i;
		
		return teams[ team ].getBestBowler ( );
}

int Tournament::isAlreadyInserted ( int id ) const
{
	for ( int i = 0 ; i < getNumberOfTeams ( ) ; i++ )
		if ( teams[i].isSameId ( id ) )
			return 1;

		return 0;
}

int Tournament::isSpace ( ) const
{
	return noOfTeams < totalTeams;
}

void Tournament::insertTeam ( const Team & t ) 
{
	if ( !isSpace ( ) )
		cout << "No space for new teams" << endl;
	else
	{
		teams[ noOfTeams ] = t;
		noOfTeams ++;
	}
}

void Tournament::removeTeam ( int id ) 
{
	int i = 0 ; 
	
	while ( i < getNumberOfTeams ( ) && !teams[i].isSameId ( id ) )
		i ++ ;

	if ( teams[i].isSameId ( id ) == 0 )
		cout << "Unknown id" << endl;
	else
		shiftTeamsLeft ( i );
}

void Tournament::printAllTeams ( ) const
{
	for ( int i = 0 ; i < getNumberOfTeams ( ) ; i++ )
	{
		teams[i].printTeam ( ) ;
		cout << endl;
		cout << "teams : " << noOfTeams << endl;
	}
}

void Tournament::printTeam ( int id ) const
{
	int i = 0;

	while ( i < getNumberOfTeams ( ) && teams[i].isSameId ( id ) == 0 )
		i++;

	if ( teams[i].isSameId ( id ) )
		teams[i].printTeam ( );
	else
		cout << "Unknown id" << endl;
}

void Tournament::shiftTeamsLeft ( int start ) 
{
	for ( int i = start ; i < getNumberOfTeams ( ) - 1 ; i++ )
		teams[i] = teams[ i + 1 ];
}

int Tournament::getNumberOfTeams ( ) const
{
	return noOfTeams;
}

int Tournament::getTotalTeams ( ) const
{
	return totalTeams;
}





