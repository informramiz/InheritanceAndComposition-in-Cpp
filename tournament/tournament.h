#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Team.h"

class Tournament
{
	private:

		Team * teams;
		int totalTeams;
		int noOfTeams;

		void shiftTeamsLeft ( int );
		int isAlreadyInserted ( int ) const;

		int isSpace ( ) const;

	public:

		Tournament ( int = 5 );
		Tournament ( const Tournament & );
		~Tournament ( );

		Tournament & operator = ( const Tournament & );

		void insertTeam ( const Team &  );
		void removeTeam ( int id );

		void printTeam ( int ) const;

		void printAllTeams ( ) const;
		int getNumberOfTeams ( ) const;

		int getTotalTeams ( ) const;

		Player getBestBatsman ( ) const;
		Player getBestBowler ( ) const;
};

#endif