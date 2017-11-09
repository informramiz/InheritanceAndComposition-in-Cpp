#ifndef TWODAYPACKAG_H
#define TWODAYPACKAG_H

#include "Package.h"

class TwoDayPackage : public Package
{
	private:

		float flatFee;

	public:
		
			TwoDayPackage ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , const CString & sState
			, const CString & rstate , int sZip , int rZip , float cst , float w , float f );
		

			TwoDayPackage ( const Person & , const Person & , float , float , float );
			void setFee ( float );
			float getFee ( ) const;

			virtual float calculateCost ( ) const;
			virtual void print ( ) const;

};

#endif