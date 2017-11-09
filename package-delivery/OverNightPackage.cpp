#include "OverNightPackage.h"

OverNightPackage::OverNightPackage ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , const CString & sState
			, const CString & rstate , int sZip , int rZip , float cst , float w , float f )
			:Package ( sName , rName , sAd , rAd , scity , rcity , sState , rstate , sZip ,
			rZip , cst , w )
{
	additionalFee = ( f >= 0.0 ) ? f : 0.0 ;
}

OverNightPackage::OverNightPackage ( const Person & s , const Person & r , float c , float w ,
									float fee ):Package ( s , r , c , w )
{
	additionalFee = fee >= 0.0 ? fee : 0.0 ;
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
	return ( getAdditionalFee ( ) + getCost ( ) ) * getWeight ( );
}

void OverNightPackage::print ( ) const
{
	cout << "Over night package\n" ;
	Package::print ( );
	cout << "Shipping Cost : " << calculateCost ( ) << endl;
}