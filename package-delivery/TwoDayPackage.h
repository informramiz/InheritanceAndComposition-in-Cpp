#include "Package.h"

class TwoDayPackage : public Package
{
	private:

		float flatFee;

	public:
		
			TwoDayPackage ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , const string & sState
			, const string & rstate , int sZip , int rZip , float cst , float w , float f );
		

			void setFee ( float );
			float getFee ( ) const;

			float calculateCost ( ) const;

};