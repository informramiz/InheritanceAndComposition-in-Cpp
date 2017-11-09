#include "package.h"

Package::Package ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , 
			const CString & sState , const CString & rstate , int sZip , int rZip , float cst , float w )
			:sender ( sName , sAd , scity , sState , sZip ) 
			, receiver ( rName , rAd , rcity , rstate , rZip )
{
	cost = ( cst >= 0.0 ) ? cst : 0.0 ;
	weight = ( w >= 0.0 ) ? w : 0.0 ;
}

Package::Package ( const Person & s , const Person & r , float c , float w )
	:sender ( s ) , receiver ( r )
{
	cost = c;
	weight = w;
}

void Package::setWeight ( float value )
{
	if ( value >= 0.0 )
		weight = value;
}

float Package::getWeight ( ) const
{
	return weight;
}

void Package::setCost ( float value ) 
{
	if ( value >= 0.0 )
		cost = value;
}

float Package::getCost ( ) const
{
	return cost;
}

//float Package::calculateCost ( ) const
//{
	//return getCost ( ) * getWeight ( );
//}

void Package::setSenderAddress ( const CString & str )
{
	sender.setAddress ( str );
}

CString Package::getSenderAddresss ( ) const
{
	return sender.getAddress ( );
}

void Package::setReceiverAddress ( const CString & str )
{
	receiver.setAddress ( str );
}

CString Package::getReceiverAddress ( ) const
{
	return receiver.getAddress ( );
}

void Package::setSenderName ( const CString & str )
{
	sender.setName ( str );
}

CString Package::getSenderName ( ) const
{
	return sender.getName ( );
}

void Package::setReceiverName ( const CString & str )
{
	receiver.setName ( str );
}

CString Package::getReceiverName ( ) const
{
	return receiver.getName ( );
}

void Package::setSenderCity ( const CString & str )
{
	sender.setCity ( str );
}

CString Package::getSenderCity ( ) const
{
	return sender.getCity ( );
}

void Package::setReceiverCity ( const CString & str )
{
	receiver.setCity ( str );
}

CString Package::getReceiverCity ( ) const
{
	return receiver.getCity ( );
}

void Package::print ( ) const
{
	cout << "Sender : ";
	sender.print ( );

	cout << "\nReceiver : ";
	receiver.print ( );
	
	cout << endl;
}
