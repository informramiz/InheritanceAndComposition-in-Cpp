#ifndef COOKIE_H
#define COOKIE_H

#include "DessertItem.h"

class Cookie : public DessertItem
{
	private:

		int number;
		double price;

	public:

		Cookie ( const CString & , int n , double p );

		virtual int getCost ( ) const;

		void setNumber( int );
		int getNumber ( ) const;

		void setPrice ( double );
		double getPrice ( ) const;
};

#endif