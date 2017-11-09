#include "DVD.h"

DVD::DVD ( )
{
	publisher[0] = '\0';	
}

DVD::DVD ( const CString & n , const CString & d  , int p , 
		const CString & pub ) : Item ( n , d , p )
{
	publisher = pub;
}

void DVD::setPublisher ( const CString &  p )
{
	publisher = p;
}

CString DVD::getPublisher ( ) const
{
	return publisher;
}