#ifndef BOWLER_H
#define BOWLER_H

#include "player.h"

class Bowler : public Player
{
	private:

		int wickets;

	public:

		Bowler ( const string & n , int i , int w );
		Bowler ( );

		void setWickets ( int ) ;
		virtual int getStatus ( ) const;

		virtual void increase ( int );
		virtual void print ( ) const;

		virtual Player * clone ( ) const;
};

#endif