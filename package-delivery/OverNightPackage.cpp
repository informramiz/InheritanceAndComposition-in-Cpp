#include "OverNightPackage.h"

OverNightPackage::OverNightPackage ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , const string & sState
			, const string & rstate , int sZip , int rZip , float cst , float w , float f )
			:Package ( sName , rName , sAd , rAd , scity , rcity , sState , rstate , sZip ,
			rZip , cst , w )
{
	additionalFee = ( f >= 0.0 ) ? f : 0.0 ;
}

void OverNightPackage::setAdditionalFee ( float value )
{
	if ( value >= 0.0 )
		additionalFee = value;
}

float OverNightPackage::getAdditionalFee ( ) const
{
	return additionalFee;
}

float OverNightPackage::calculateCost ( ) const
{
	return ( additionalFee + getCost ( ) ) * getWeight ( );
}