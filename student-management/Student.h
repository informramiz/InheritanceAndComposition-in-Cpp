#include <iostream.h>
#include <fstream.h>
#include "String.h"

class Student
{
	friend fstream & operator<< ( fstream & , const Student & );
	friend fstream & operator>> ( fstream & , Student & );

	private:

		CString name;
		int rollNumber;

	public:

		Student ( );
		Student ( const CString & , int );

		void  setName ( const CString & );
		CString getName ( ) const;

		void setRollNumber ( int );
		int getRollNumber ( ) const;

		bool operator == ( const Student &  ) const;
		bool operator != ( const Student & ref ) const
		{
			return ! ( *this == ref );
		}
};
