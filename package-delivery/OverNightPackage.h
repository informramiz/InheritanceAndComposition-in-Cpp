#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OverNightPackage : public Package 
{
	private:

		float additionalFee;

	public:

		OverNightPackage ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , const CString & sState
			, const CString & rstate , int sZip , int rZip , float cst , float w , float f );

		OverNightPackage ( const Person & , const Person & , float , float , float );
		void setAdditionalFee ( float );
		float getAdditionalFee ( ) const;

		virtual float calculateCost ( ) const;
		virtual void print ( ) const;
};

#endif