#ifndef PACKAGE_H
#define PACKAGE_H

#include "Person.h"

class Package 
{
	private:

		Person sender;
		Person receiver;

		float cost;
		float weight;

	public:

		Package ( const CString & sName , const CString & rName , const CString & sAd , 
			const CString & rAd , const CString & scity , const CString & rcity , 
			const CString & sState , const CString & rstate , int sZip , int rZip , float cst , float w ) ;

		Package ( )
		{
			cost = 0;
			weight = 1;
		}

		Package ( const Person & , const Person & , float , float );

		void setSenderName ( const CString & );
		CString getSenderName ( ) const;

		void setReceiverName ( const CString & );
		CString getReceiverName ( ) const;

		void setSenderAddress ( const CString & );
		CString getSenderAddresss ( ) const;

		void setReceiverAddress ( const CString & );
		CString getReceiverAddress ( ) const;

		void setSenderCity ( const CString & );
		CString getSenderCity ( ) const;

		void setReceiverCity ( const CString & );
		CString getReceiverCity ( ) const;

		void setCost ( float );
		float getCost ( ) const;

		void setWeight ( float );
		float getWeight ( ) const;

		virtual float calculateCost ( ) const = 0;

		virtual void print ( ) const;
};

#endif

