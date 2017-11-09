#ifndef DESSERTITEM_H
#define DESSERTITEM_H

#include "String.h"

class DessertItem
{
	private:

		CString name;

	public:

		DessertItem ( );
		DessertItem ( const CString & );

		CString getName ( ) const;

		virtual int getCost ( ) const = 0;
};

#endif