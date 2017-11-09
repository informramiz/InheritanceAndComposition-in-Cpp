#include "SalesAgent.h"

SalesAgent::SalesAgent ( )
{
	lastCommissionAmount = 0 ;			
}

SalesAgent::SalesAgent ( const CString & nm , const CString & ad , const CString & ph , int cm  )
	:address ( nm , ad , ph )
{
	lastCommissionAmount = ( cm >= 0 ) ? cm : 0 ;
}

void SalesAgent::setLastCommissionAmount ( int value )
{
	if ( value >= 0 )
		lastCommissionAmount = value;
}

int SalesAgent::getLastCommissionAmount ( ) const
{
	return lastCommissionAmount;
}

