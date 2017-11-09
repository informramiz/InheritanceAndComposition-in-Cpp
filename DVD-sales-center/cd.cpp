#include "CD.h"

CD::CD ( )
{
	publisher[0] = '\0';	
}

CD::CD ( const CString & n , const CString & d  , int p , 
		const CString & pub ) : Item ( n , d , p )
{
	publisher = pub;
}

void CD::setPublisher ( const CString &  p )
{
	publisher = p;
}

CString CD::getPublisher ( ) const
{
	return publisher;
}