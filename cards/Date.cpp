#include "Date.h"

const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date( int m , int d , int y )
{
	setDate( m , d , y );
}

void Date::setDate( int m , int d , int y )
{
	setMonth( m );
	setYear( y );
	setDay( d );
}

void Date::setMonth( int m )
{
	month = ((m > 0 && m <= 12 ) ? m : 1 );
}

void Date::setYear ( int y )
{
	year = ( y >= 1900 && y < 2050 ) ? y : 1900;
}

void Date::setDay( int d )
{	
	if( month == 2 && isLeapYear( year ) )
		day = ( d > 0 && d <= 29 ) ? d:1;
	else
		day = ( d > 0 && d <= days[month] ) ? d : 1;
}

int Date::getDay ( ) const
{
	return day;
}

int Date::getMonth ( ) const
{
	return month;
}

int Date::getYear ( ) const 
{
	return year;
}
 
bool Date::isLeapYear( int testYear )const
{
	if( testYear % 400 == 0 || ( testYear % 4 == 0 && testYear%100 != 0 ) )
		return true;
	return false;
}

void Date::incrementDay ( int inc )
{
	
	day += inc;

	if( day > days[month] )
	{
		incrementMonth ( day / days[month] );
		day %= days[month];
	}
}

void Date::incrementMonth ( int inc )
{
	month +=inc;

	if( month > 12 )
	{
		incrementYear( month / 12 );
		month %= 12;
	}
}

void Date::incrementYear ( int inc )
{
	year += inc;
}

void Date::print ( ) const
{
	//char *monthName[] = {"","January", "February", "March", "April", "May", "June", "July", "August"
		//, "September" , "October" , "Novemebeer" , "December"};

	cout<< getMonth ( ) <<' '<<getDay() <<","<< getYear() <<endl;
	//cout<< monthName[ getMonth ( ) ] <<" "<< getDay ( ) <<","<< getYear ( ) <<endl;
}

Date &  Date::operator ++ ( )
{
	incrementDay ( );
	return * this;
}

Date Date::operator ++ ( int )
{
	Date temp = * this;
	incrementDay ( );
	return temp;
}

bool Date::operator == ( const Date & right ) const
{
	return ( right.getDay ( ) == getDay ( ) && right.getMonth ( ) == getMonth ( ) && 
		right.getYear ( ) == getYear ( ) );
}

bool Date::operator < ( const Date & right ) const
{
	if ( getDay ( ) < right.getDay ( ) && getMonth ( ) < right.getMonth ( )
		&& getYear ( ) < right.getYear ( ) )
		return true;

	return false;
}






