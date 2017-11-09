#ifndef TEAM_H
#define TEAM_H

#include "player.h"
#include "Batsman.h"
#include "Bowler.h"

class Team
{
	private:

		enum { SIZE = 11 };

		Player * players[11];
		int noOfPlayers;

		void shiftPlayersLeft ( int i ) ;
		int isAlreadyInserted ( int ) const;
		int id;

	public:

		Team ( );
		Team ( const Team & );
		~Team ( ) ;

		Team & operator = ( const Team & );

		int insertPlayer ( Player * );
		
		void setId ( int ) ;
		int getId ( ) const;

		int removePlayer ( int id );	
		int isSpace ( ) const;

		int getNoOfPlayers ( ) const;
		void printTeam ( ) const;

		int getSize ( ) const;

		void printPlayer ( int ) const;
		Player  getBestBatsman ( ) const;

		Player  getBestBowler ( ) const;
		int isSameId ( int ) const;
};

#endif