#include <stdlib.h>
#include <string.h>
//using namespace std;

#include "String.h"

CString::CString ( const char * s )
{
	length = ( s != 0 ? strlen ( s ) : 0 );

	setString ( s );
}

CString::CString ( const CString & copy )
{
	length = copy.length ;

	setString ( copy.sPtr );
}

CString::CString ( char c )
{
	length = 1;
	setString ( &c );
}

CString::CString ( )
{
	length = 0;
	setString ( "" );
}

CString::~CString ( )
{
	if ( sPtr )
	{
		delete [] sPtr;
		sPtr = '\0';
	}
}

const CString & CString::operator = ( const CString & s )
{
	if ( !sPtr || !s.sPtr )
		exit ( 1 );

	if ( this == & s )
		return *this;

	delete [] sPtr;
	length = s.length ;

	setString ( s.sPtr );

	return *this;
}

void CString::operator += ( const CString & s )
{
	if ( !sPtr || !s.sPtr )
		exit ( 1 );

	int newLength = length + s.length ;
	char * temp = new char [newLength + 1];

	copyString ( temp , sPtr , length );
	copyString ( temp + length , s.sPtr );

	delete [] sPtr ;
	sPtr = temp;
	length = newLength;
}

void CString::operator += ( const char * s )
{
	if ( !sPtr )
		exit ( 1 );

	int newLength = length + strlen ( s );
	char * temp = new char [ newLength + 1];

	copyString ( temp , sPtr , length );
	copyString ( temp + length , s );
	
	delete [] sPtr ;
	sPtr = temp;
	length = newLength;
}

CString CString::operator + ( const CString & s ) const
{
	if ( !sPtr || !s.sPtr )
		exit ( 1 );

	CString temp ( sPtr );
	temp += s;

	return temp;
}

int CString::operator == ( const CString & s ) const
{
	if ( !sPtr || !s.sPtr )
		exit ( 1 );

	return compare ( sPtr , s.sPtr ) == 0;
}

int CString::operator == ( const char * s ) const
{
	if ( !sPtr )
		exit ( 1 );

	return compare ( sPtr , s ) == 0 ;
} 

int CString::operator ! ( ) const
{
	return length == 0;
}

char & CString::operator [] ( int index )
{
	if ( !sPtr )
		exit ( 1 );

	if ( !isValidIndex ( index ) )
	{
		cout << "\nError: subscrip " << index << " out of range \n";
		exit ( 1 );
	}

	return sPtr[ index ];
}

CString CString::operator () ( int start , int end ) const
{
	if ( !isValidIndex ( start ) || !isValidIndex ( end ) )
	{
		cout << "starting or ending index is out of range\n";
		return "";
	}

	int len = end - start + 1;
	char * temp = new char [ len + 1 ];
	
	copyString ( temp , &sPtr[ start ] , len );
	temp [ len ] = '\0';
	
	CString tempString ( temp );
	delete [] temp;

	return tempString;
}

int CString::Find ( const char * a , int start  ) const
{
	if (!sPtr || !a || start < 0 || start >= length )
		return -1;

	for ( int i = start ; i < length ; i ++ )
	{
		if ( sPtr[ i ] == a[ 0 ] )
		{
			if ( isMatchingString ( a , i ) )
				return i;
		}
	}

	return -1;
} 

int CString::isMatchingString ( const char * a , int start ) const
{
	if ( !sPtr )
		exit ( 1 );

	int len = strLen ( a );

	for ( int i = start ; ( i - start ) < len && i < length ; i++ )
	{
		if ( sPtr[ i ] != a[i - start] )
			return 0;
	}

	return 1;
}

int CString::Find ( char c , int start ) const
{
	if ( !sPtr || start < 0 || start >= length )
		return -1;

	for ( int i = 0 ; i < length ; i ++ )
		if ( c == sPtr[i] )
			return i;

	return -1;
}

int CString::Insert ( int index , char * str )
{
	if ( !isValidIndex ( index - 1 ) || !sPtr || !str )
	{
		cerr << "invalid index\n" << endl;
		exit ( 1 );
	}

	int length1= strLen ( str );
	int len = length1 + length ;

	char * temp = new char [ len + 1 ];

	CString s ( str );
	s += &sPtr[ index ];
	
	copyString ( temp , sPtr , index );
	copyString ( temp + index , s.sPtr );
	
	delete [] sPtr;
	sPtr = temp;
	length = len;
	
	return length;
}

int CString::Insert ( int index , char ch )
{
	Insert ( index , &ch );

	return length;
}

CString CString::Left ( int count ) const
{
	if ( !sPtr || count < 0 || count > length )
	{
		cout << "characters count out of range\n";
		exit ( 1 );
	}

	char * temp =new char[ count + 1 ];

	copyString ( temp , sPtr , count );
	temp [ count ] = '\0';
	
	CString tempString ( temp );
	delete [] temp;

	return tempString;
}

CString CString::Right ( int count ) const
{
	if ( !sPtr || count < 0 || count > length )
	{
		cerr << "character count out of range" << endl;
		exit ( 1 );
	}

	char * temp = new char[ count + 1 ];

	copyString ( temp , sPtr + ( length - count ) , count );
	temp [ count ] = '\0';

	CString tempString ( temp );
	delete [] temp;

	return tempString ;
}

int CString::Delete ( int index , int count ) 
{
	if ( !sPtr || !isValidIndex ( index ) || count <= 0 || ( count + index ) > length )
	{
		cerr << "index or count out of range\n" << endl;
		exit ( 1 );
	}

	int len = length - count;
	char * temp = new char [ len + 1 ];

	if ( index != 0 )
		copyString ( temp , sPtr , index );

	CString tempString ( sPtr + index + count  );
	copyString ( temp + index , tempString.sPtr );

	delete [] sPtr;
	sPtr = temp;

	length = len;
	return length;
}

int CString::Remove ( char ch ) 
{
	if ( !sPtr )
		exit (1);

	int count = numberOfMatches ( ch );	
	
	int len = length - count;
	char * temp = new char [ len + 1];


	for ( int i = 0 , j = 0 ; i < length ; i++ )
	{
		if ( ch != sPtr[i] )
		{
			temp [j] = sPtr [i];
			j++;
		}
	}
	
	temp[ len ] = '\0';

	delete [] sPtr;
	sPtr = temp;
	length = len;

	return count;
}

CString CString::Trim ( )
{
	if ( !sPtr )
		exit ( 1 );

	int leadingSpaces = numberOfLeadingSpaces ( );
	int trailingSpaces = numberOfTrailingSpaces ( );

	int len = length - leadingSpaces - trailingSpaces ;
	char * temp = new char[ len + 1];

	copyString ( temp , sPtr + leadingSpaces , len );
	temp [ len ] = '\0';
	
	delete [] sPtr;
	sPtr = temp;
	length = len;

	return CString( temp );
}

CString CString::MakeLower ( )
{
	if ( !sPtr )
		exit ( 1 );

	char * temp = new char [ length + 1];
	
	for ( int i = 0 ; i < length ; i++ )
		if ( isUpper ( sPtr[i] ) )
			temp [i] =  sPtr[i] + 32;
		else
			temp [i] = sPtr[i] ;

	temp [ length ] = '\0';
	
	delete [] sPtr;
	sPtr = temp;
	
	return CString ( sPtr );
}

CString CString::MakeUpper ( )
{
	if ( !sPtr )
		exit ( 1 );

	char * temp = new char [ length + 1];
	
	for ( int i = 0 ; i < length ; i++ )
	{
		if ( isLower ( sPtr[i] ) )
			temp [i] = sPtr[i]  - 32 ;
		else
			temp [i] = sPtr [i]  ;
	}
	
	temp [ length ] = '\0';
	delete [] sPtr;
	sPtr = temp;
	
	return CString ( sPtr );
}

CString CString::Reverse ( )
{
	if ( !sPtr )
		exit ( 1 );

	char * temp = new char [ length + 1];

	for ( int i = length - 1 , j = 0 ; i >= 0 ; i-- , j++ )
	{
		temp [j] = sPtr [i];
	}
	
	temp [ length ] = '\0';
	delete [] sPtr;
	sPtr = temp;

	return CString ( temp );
}

void CString::Resize ( int add )
{
	if ( !sPtr || add < 0 )
		exit ( 1 );

	int len = length + add ;
	char * temp = new char [ len + 1 ];

	copyString ( temp , sPtr );
	delete [] sPtr;

	sPtr = temp;
	length = len;
}

int CString::getLength ( ) const
{
	return length;
}

CString CString::Replace ( char * old , char * newStr )
{
	if ( !sPtr )
		exit ( 1 );

	int index = Find ( old );

	if ( index < 0 )
		return CString ( sPtr );

	int length1 = strLen ( old );
	int length2 = strLen ( newStr );

	int len = length - length1 + length2;
	char * temp = new char [ len + 1];

	if ( index !=0 )
		copyString ( temp , sPtr , index );

	copyString ( temp + index , newStr , length2 );

	if ( ( index + length1 ) < length )
		copyString ( temp + index + length2  , sPtr + index + length1 );
	else
		temp[ index + length2 ] = '\0';
	
	delete [] sPtr;
	sPtr = temp;
	length = len;

	return CString ( sPtr );
}

int CString::isLower ( char ch ) const
{
	if ( ch >= 'a' && ch <= 'z' )
		return 1;

	return 0;
}

int CString::isUpper ( char ch ) const
{
	if ( ch >= 'A' && ch <= 'Z' )
		return 1;
	
	return 0;
}

int CString::numberOfLeadingSpaces ( ) const
{
	char space = ' ';
	int i = 0 ;

	while ( sPtr[i] == space  && i < length ) 
		i++;

	return i;
}

int CString::numberOfTrailingSpaces ( ) const
{
	char space = ' ';
	int i = length - 1;

	while ( sPtr[i] == space && i >= 0 )
		i--;

	return length -  (i + 1 ) ;
}

int CString::numberOfMatches ( char ch ) const
{
	int count = 0 ;

	for ( int i = 0 ; i < length ; i++ )
		if ( ch == sPtr [i] )
			count ++ ;

	return count;
}

void CString::setString ( const char * s )
{
	sPtr = new char[ length + 1 ];

	if ( s )
		copyString ( sPtr , s ); 
	else
		sPtr[0] = '\0';
}

int CString::isValidIndex ( int index ) const
{
	if ( index < 0 || index >= length )
		return 0;
	
	return 1;
}

int CString::strLen ( const char * a ) const 
{
	int i = 0;
	
	while ( a[i] != '\0' )
		i++;

	return i;
}

int CString::compare ( const char * a , const char * b ) const 
{
	int length1 = strLen ( a );
	int length2 = strLen ( b );

	for ( int i = 0 ; i < length1 && i < length2 ; i++ )
	{
		if ( a[i] > b[i] )
			return 1;
		else if ( a[i] < b[i] )
			return -1;
	}

	if ( length1 > length2 )
		return 1;
	else if ( length1 < length2 )
		return -1;

	return 0;
}

void CString::copyString ( char * target , const char * src ) const
{
	int length1 = strLen ( src );
	int length2 = strLen ( target );

	for ( int i = 0 ; i < length1 && length2 ; i++ )
	{
		target[ i ] = src[ i ];
	}

	target [ i ] = '\0';
}

void CString::copyString ( char * target , const char * src , int limit ) const
{
	if ( !target || !src )
		exit ( 1 );

	int length = strLen ( src );
	
	for ( int i = 0 ; i < limit && i < length ; i++ )
	{
		target[ i ] = src[ i ];
	}
}

#if 1
ostream & operator << ( ostream & output , const CString & s )
{
	output << s.sPtr ;

	return output;
}

istream & operator >> ( istream & input , CString & s )
{
	char temp [100]; // temporary buffer to store string
	input >> temp;

	s = temp; // conversion constructor makes the object and assing to s
	return input;
}

int operator == ( const char * const str , const CString & s )
{
	return s.compare ( str , s.sPtr ) == 0;
}

CString operator + ( const CString & s , const char * const str )
{
	CString temp ( str );

	return temp + s;
}

CString operator + ( const char * const str , const CString & s )
{
	return s + str;
}
#endif