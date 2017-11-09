#ifndef ICECREAM_H
#define ICECREAM_H

#include "DessertItem.h"

class IceCream : public DessertItem
{
	private:

		double cost;

	public:

		IceCream ( const CString & ,  double );

		virtual int getCost ( ) const;

		void setCost ( double ) ;
};

#endif