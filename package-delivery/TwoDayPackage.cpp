#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , const CString & sState
			, const CString & rstate , int sZip , int rZip , float cst , float w , float f )
			:Package ( sName , rName , sAd , rAd , scity , rcity , sState , rstate , sZip ,
			rZip , cst , w )
{
	flatFee = ( f >= 0.0 ) ? f : 0.0;	
}

TwoDayPackage::TwoDayPackage ( const Person & s , const Person & r , float c , float w ,
							  float fee ):Package ( s , r , c , w )
{
	flatFee = ( fee >= 0.0 ) ? fee : 0.0 ;
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
	return flatFee + getCost ( ) * getWeight ( );
}

void TwoDayPackage::print ( ) const
{
	cout << "Two day package\n";
	Package::print ( );
	cout << "Shipping cost: " << calculateCost ( ) << endl;
}

