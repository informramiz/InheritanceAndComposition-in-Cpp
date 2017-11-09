#ifndef PERSON_H
#define PERSON_H

#include <iostream.h>
#include "String.h"
//'using namespace std;

class Person
{
	private:

		CString name;
		CString address;
		CString city;
		CString state;
		int zipCode;

	public:

		Person ( const CString & n , const CString & ad , const CString & c , const CString & s , int z );
		Person ( )
		{
			name[0] = '\0';
			address[0] = '\0';
			city[0] = '\0';
			state[0] = '\0';
			zipCode = 0;
		}

		void setName ( const CString & );
		CString getName ( ) const;

		void setAddress ( const CString & );
		CString getAddress ( ) const;

		void setCity ( const CString &  );
		CString getCity ( ) const;

		void setState ( const CString & );
		CString getState ( ) const;

		void setZipCode ( int );
		int getZipCode ( ) const;

		void print ( ) const;
};

#endif