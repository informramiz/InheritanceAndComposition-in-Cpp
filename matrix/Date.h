#ifndef DATE_H
#define DATE_H

#include <iostream.h>


class Date
{
	friend ostream & operator << ( ostream & , const Date & );
	friend istream & operator >> ( istream & , Date & );

	private:
		int day;
		int month;
		int year;

		static const int days[];
	public:
		Date(int = 1 , int = 1 , int = 1900 );
		void setDate( int  , int , int  );
		void setDay( int );
		void setMonth( int );

		void setYear( int );

		int getDay ( ) const;
		int getMonth ( ) const;
		int getYear ( ) const;

		void print ( ) const;
		bool isLeapYear( int )const;
		void incrementDay( int = 1 );

		void incrementMonth( int = 1 );
		void incrementYear( int = 1 );

		Date &  operator ++ ( );
		Date operator ++ ( int );

		bool operator == ( const Date & ) const;
		bool operator != ( const Date & value ) const
		{
			return ! ( *this == value );
		}

		Date operator * ( const Date & ) const;
		Date operator + ( const Date & ) const;
		
		Date operator - ( const Date & ) const;
};

#endif