#include "package.h"

Package::Package ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , 
			const string & sState , const string & rstate , int sZip , int rZip , float cst , float w )
			:sender ( sName , sAd , scity , sState , sZip ) 
			, receiver ( rName , rAd , rcity , rstate , rZip )
{
	cost = ( cst >= 0.0 ) ? cst : 0.0 ;
	weight = ( w >= 0.0 ) ? w : 0.0 ;
}

void Package::setWeight ( int value )
{
	if ( value >= 0.0 )
		weight = value;
}

double Package::getWeight ( ) const
{
	return weight;
}

void Package::setCost ( int value ) 
{
	if ( value >= 0.0 )
		cost = value;
}

double Package::getCost ( ) const
{
	return cost;
}

double Package::calculateCost ( ) const
{
	return getCost ( ) * getWeight ( );
}
