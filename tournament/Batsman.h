#ifndef	BATSMAN_H
#define BATSMAN_H

#include "player.h"

class Batsman : public Player
{
	private:

		int scores;

	public:

		Batsman ( const string & n , int i , int score );
		Batsman ( );

		void setScores ( int );
		virtual void increase ( int ) ;

		virtual int getStatus ( ) const;
		virtual void print ( ) const;

		virtual Player * clone ( ) const;
};

#endif