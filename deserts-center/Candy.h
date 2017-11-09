#ifndef CANDY_H
#define CANDY_H

#include "DessertItem.h"

class Candy : public DessertItem
{
	private:

		double weight;
		double price;

	public:

		Candy ( const CString & , double w , double p );

		virtual int getCost ( ) const;

		void setWeight ( double );
		void setPrice ( double );

		double getWeight ( ) const;
		double getPrice ( ) const;
};

#endif