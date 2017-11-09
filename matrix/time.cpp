#include <iostream.h>
#include <iomanip.h>
//using namespace std;

#include "time.h"

Time::Time( int h , int m , int s )
{
	setTime ( h , m , s);
}

void Time::setTime( int h , int m , int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour( int h )
{
	hour = ( h >= 0 && h < 24 )? h : 0 ;
}

void Time::setMinute( int m )
{
	minute = ( m >= 0 && m < 60 ) ? m : 0 ;
}

void Time::setSecond( int s )
{
	second = ( s >= 0 && s < 60 ) ? s : 0 ;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond () const
{
	return second;
}

void Time::incHour( int inc )
{
	hour += inc;

	if( hour > 23 )
	{
		hour %= 24 ;
	}
}

void Time::incMinute( int inc )
{
	minute += inc;

	if( minute > 59 )
	{
		incHour( (minute / 60 ) );
		minute %= 60;
	}
}

void Time::incSecond( int inc )
{
	second += inc ;

   if( second > 59 )
   {
   	incMinute( (second / 60 ) );
      second %= 60 ;
   }
}

void Time::printUniversalTime() const
{
	cout << setfill('0') << setw ( 2 ) << getHour ( ) << ":" << setw ( 2 ) << getMinute ( ) <<":"
   	<< setw( 2 ) << getSecond ( ) << endl;
}

void Time::printStandardTime() const
{
	cout << ( ( getHour() == 0 || getHour ( ) == 12 ) ? 12 : getHour() % 12 )
   	<< ":" << setfill ( '0' ) << setw ( 2 ) << getMinute ( ) << ":" << setw ( 2 ) << getSecond ( )
      << ( ( getHour ( ) > 12 ) ? " PM" : " AM" );
}

bool Time::operator == ( const Time & value ) const
{
	return ( hour == value.hour && minute == value.minute && second == value.second );
}

ostream & operator << ( ostream & output , const Time & value )
{
	value.printStandardTime ( );
	return output;
}

istream & operator >> ( istream & input , Time & value )
{
	cin >> value.hour >> value.minute >> value.second ;
	return input;
}

Time Time::operator * ( const Time & value ) const
{
	return Time ( hour * value.hour , minute * value.minute , second * value.second );
}

Time Time::operator - ( const Time & value ) const
{
	return Time ( hour - value.hour , minute - value.minute , second - value.second );
}

Time Time::operator + ( const Time & value ) const
{
	return Time ( hour + value.hour , minute + value.minute , second + value.second );
}

