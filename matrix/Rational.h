#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream.h>

class Rational
{
	friend ostream & operator << ( ostream & , const Rational & );
	friend istream & operator >> ( istream & , Rational & );

	private:
		
		int numerator;
		int denominator;
		void reduceRational();
	
	public:

		Rational ( int = 0 , int = 1 );
		void setNumerator ( int  );
		int getNumerator ( ) const;

		void setDenominator ( int );
		int getDenominator () const;

		Rational addRational ( const Rational & ) const;
		Rational subtractRational ( const Rational & ) const;

		Rational multiplyRational ( const Rational & ) const;
		Rational divideRational ( const Rational & ) const;

		void printRational ( ) const;

		bool operator == ( const Rational & ) const;
		
		bool operator != ( const Rational & value ) const
		{
			return !( *this == value );
		}

		Rational operator * ( const Rational & ) const;
		Rational operator + ( const Rational & ) const;
		
		Rational operator - ( const Rational & ) const;
};

#endif