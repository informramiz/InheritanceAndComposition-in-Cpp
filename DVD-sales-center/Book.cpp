#include "Book.h"

Book::Book ( const CString & n , const CString & d , int p ,
			const CString & authr ) : Item ( n , d , p )
{
	author = authr;
}

Book::Book ( )
{
	author[0] = '\0';
}

void Book::setAuthor ( const CString & s )
{
	author = s;
}

CString Book::getAuthor ( ) const
{
	return author;
}