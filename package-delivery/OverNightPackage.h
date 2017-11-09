#include "Package.h"

class OverNightPackage : public Package 
{
	private:

		float additionalFee;

	public:

		OverNightPackage ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , const string & sState
			, const string & rstate , int sZip , int rZip , float cst , float w , float f );

		void setAdditionalFee ( float );
		float getAdditionalFee ( ) const;

		float calculateCost ( ) const;	
};