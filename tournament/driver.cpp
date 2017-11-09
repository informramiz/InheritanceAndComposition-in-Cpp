#include "Batsman.h"
#include "Bowler.h"
#include "Team.h"
#include "Tournament.h"

void main ( )
{
	Batsman b ( "Ramiz Raja" , 2 , 32 );
	Bowler b1 ( "Farooq" , 4 , 45 );
	Batsman bs ( "Asim" , 2 , 44 );
	Bowler  bo ( "Shahzad" , 5 , 56 );
	
	Player * p[4] = { &b , &b1 , &bs , &bo };
	
	Team t1;
	t1.insertPlayer ( p[0] );
	
	Team t2;
	t2.insertPlayer ( p[1] );
	t2.insertPlayer ( p[2] );

	Tournament to ;
	to.insertTeam ( t1 );
	to.insertTeam ( t2 );

	to.printAllTeams ( );
}
