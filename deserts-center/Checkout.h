#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "vector.h"
#include "DessertShope.h"
#include "DessertItem.h"
#include "IceCream.h"

class Checkout
{
	private:

		Vector < DessertItem > list;

	public:

		Checkout ( );

		void clear ( );
		void enterItem ( DessertItem * );

		int numberOfItems ( ) const;
		CString toString ( ) const;

		int totalCost ( ) const;
		int totalTax ( ) const;
};

ostream & operator << ( ostream & , const Checkout & );

#endif