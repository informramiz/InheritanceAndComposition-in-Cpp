#include "Rational.h"

Rational::Rational ( int n , int d )
{
	setNumerator ( n );
	setDenominator ( d );
	reduceRational ( );
}

void Rational::setNumerator ( int n )
{
	numerator = n;
}

int Rational::getNumerator ( ) const
{
	return numerator;
}

void Rational::setDenominator ( int d )
{
	if ( d == 0 )
	{
		cerr << "Division by zero is not allowed. Denominator set to 1\n" ;
		denominator = 1;
	}
	else if ( d > 0 )
	{
		denominator = d;
	}
	else if ( d < 0 )
	{
		denominator = - d ;
		numerator = - numerator;
	}
}

int Rational::getDenominator ( ) const
{
	return denominator ;	
}

Rational Rational::addRational ( const Rational & r ) const
{
	Rational sum;
	sum.numerator = numerator * r.denominator + denominator * r.numerator ;
	sum.denominator = denominator * r.denominator ;
	
	sum.reduceRational ( );
	return sum;
}

Rational Rational::subtractRational ( const Rational & r ) const
{
	Rational difference;
	difference.numerator = numerator * r.denominator - denominator * r.numerator ;
	difference.denominator = denominator * r.denominator ;
	
	difference.reduceRational ( );
	return difference;
}

Rational Rational::multiplyRational ( const Rational & r ) const
{
	Rational product;
	product.numerator = numerator * r.numerator ;
	product.denominator = denominator * r.denominator ;

	product.reduceRational ();
	return product;
}

Rational Rational::divideRational (  const Rational & r ) const
{
	Rational quotient;
	quotient.numerator = numerator * r.denominator ;

	quotient.denominator = denominator * r.numerator ;
	quotient.reduceRational ( );

	return quotient;
}

void Rational::printRational ( ) const
{
	if( numerator == 0 )
		cout << 0;
	else if ( denominator == 1 )
		cout << numerator ;
	else 
		cout << numerator << '/' << denominator;
}

void Rational::reduceRational ( ) 
{
	for ( int i = 2 ; i <= ( ( numerator >= 0 ) ? numerator : - numerator ) ; )
	{
		if ( numerator % i == 0 && denominator % i == 0 )
		{
			numerator /= i;
			denominator /= i;
		}
		else
			i++;
	}
}

ostream & operator << ( ostream & output , const Rational & value )
{
	value.printRational ( );
	return output;
}

istream & operator >> ( istream & input , Rational & value )
{
	cin >> value.numerator >> value.denominator ;
	return input;
}

bool Rational::operator == ( const Rational & r ) const
{
	return ( r.numerator == numerator && r.denominator == denominator );
}