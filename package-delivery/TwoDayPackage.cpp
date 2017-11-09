#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , const string & sState
			, const string & rstate , int sZip , int rZip , float cst , float w , float f )
			:Package ( sName , rName , sAd , rAd , scity , rcity , sState , rstate , sZip ,
			rZip , cst , w )
{
	flatFee = ( f >= 0.0 ) ? f : 0.0;	
}

void TwoDayPackage::setFee ( float f )
{
	if ( f >= 0.0 )
		flatFee = f;
}

float TwoDayPackage::getFee ( ) const
{
	return flatFee;
}

float TwoDayPackage::calculateCost ( ) const
{
	return flatFee + Package::calculateCost ( );
}

