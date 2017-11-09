#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
	private:

		string name;
		int noOfMatches;
		int id;

	public:

		Player ( const string & n , int i );
		Player ( );

		void setName ( const string & );
		string getName ( ) const;

		void setId ( int ) ;
		int getId ( ) const;

		bool isSameId ( int ) const;
		virtual void print ( ) const;

		virtual int getStatus ( ) const 
		{
			return 0;
		}

		virtual void increase ( int ) 
		{
		
		}

		virtual Player * clone ( ) const  
		{
			return new Player ( *this );
		}
};

#endif