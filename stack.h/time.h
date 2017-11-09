
class Time
{
	friend ostream & operator << ( ostream & , const Time & );
	friend istream & operator >> ( istream & , Time & );

	private:

		int hour;
		int minute;
		int second;

	public:

		Time( int = 0 , int  = 0 , int = 0 );
		void setTime ( int , int , int );
		void setHour ( int );
		void setMinute ( int );

		void setSecond ( int );
		int getHour ( ) const ;
		int getMinute ( ) const ;
		int getSecond ( ) const;

		void incSecond ( int = 1 );
		void incMinute ( int = 1 );
		void incHour( int = 1 );

		void printUniversalTime ( ) const;
		void printStandardTime ( ) const;

		bool operator == ( const Time & ) const;
		
		bool operator != ( const Time & value ) const
		{
			return ! ( *this == value );
		}

		Time operator * ( const Time & ) const;
};
