#ifndef CARD_H
#define CARD_H

#include "String.h"

class Card
{
	private:

		CString name;
		int number;

	public:

		Card ( );
		Card ( const CString & , int  );

		virtual void print ( ) const = 0;
		virtual bool isExpired ( ) const;

		void setNumber ( int );
		int getNumber ( ) const;

		void setName ( const CString & );
		CString  getName( ) const;
};

#endif