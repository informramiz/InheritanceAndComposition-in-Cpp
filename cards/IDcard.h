#ifndef IDCARD_H
#define IDCARD_H

#include "Card.h"
#include "Date.h"

class IDcard : public Card
{
	private:

		Date birthDate;
		Date expirationDate;
		CString occupation;
		int age;

	public:

		IDcard ( );
		IDcard ( const CString & , int , const Date & , const Date & , const CString & , int );

		void setExpirationDate ( const Date & );
		Date getExpirationDate ( ) const;

		void setBirthDate ( const Date & );
		Date getBirthDate ( ) const;

		void setOccupation ( const CString & );
		CString getOccupation ( ) const;

		void setAge ( int );
		int getAge ( ) const;

		virtual void print ( ) const;
};


#endif