#ifndef CALLINGCARD_H
#define CALLINGCARD_H

#include "Card.h"

class CallingCard : public Card
{
	private:

		int pin;

	public:

		CallingCard ( const CString & , int , int );
		CallingCard ( );

		void setPin ( int );
		int getPin ( ) const;

		virtual void print ( ) const;
};

#endif