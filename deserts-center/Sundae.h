#ifndef SUNDAE_H
#define SUNDAE_H

#include "IceCream.h"

class Sundae : public IceCream
{
	private:

		double toppingCost;
		CString name;

	public:

		Sundae ( const CString & , double , const CString &  , double );
		
		void setToppingCost ( double );
		double getToppingCost ( ) const;

		virtual int getCost ( ) const;
};

#endif