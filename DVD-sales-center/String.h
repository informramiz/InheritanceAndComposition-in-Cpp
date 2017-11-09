#ifndef STRING_H
#define	STRING_H

#include <iostream.h>

class CString
{
	friend ostream & operator << ( ostream & , const CString & );
	friend istream & operator >> ( istream & , CString & );

	friend int operator == ( const char * const , const CString & ) ;
	friend CString operator + ( const CString & , const char * const ) ;
	friend CString operator + ( const char * const , const CString & ) ;

	private:

		char * sPtr;
		int length;

		void setString ( const char * );
		int isValidIndex ( int ) const;

		int compare ( const char * , const char * ) const;
		void copyString ( char * , const char * ) const;

		int strLen ( const char * ) const ;
		void copyString ( char * , const char * , int ) const;
		
		int isMatchingString ( const char * , int ) const;
		int numberOfMatches ( char ) const;

		int numberOfLeadingSpaces ( ) const;
		int numberOfTrailingSpaces ( ) const;

		int isUpper ( char ) const;
		int isLower ( char ) const;

	public:

		CString ( const char * );
		CString ( const CString & );

		CString ( );
		CString ( char );
		~CString ( );

		const CString & operator = ( const CString & );
		void operator += ( const CString & );

		void operator += ( const char * const );
		CString operator + ( const CString & ) const;

		int operator == ( const CString & ) const;
		int operator == ( const char * const ) const;

		int operator ! ( ) const;
		char & operator [] ( int ) ;

		CString operator ( ) ( int , int ) const;
		int Find ( const char * , int start = 0 ) const;

		int Find ( char c , int start = 0 ) const;
		int Insert ( int , char * ) ;

		int Insert ( int , char c );
		CString Right ( int ) const;

		CString Left ( int ) const;
		int Delete ( int , int = 1 );

		int Remove ( char );
		CString Trim ( );

		CString MakeUpper ( );
		CString MakeLower ( );

		CString Reverse ( );
		void Resize ( int );

		int getLength ( ) const;
		CString Replace ( char * , char * );
};

#endif