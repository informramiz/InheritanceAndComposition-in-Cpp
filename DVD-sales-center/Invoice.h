#include "SalesAgent.h"
#include "customer.h"
#include "item.h"
#include "Date.cpp"

class Invoice
{
	private:

		Customer client;
		SalesAgent sA;

		Date orderDate;
		bool isShipped;
		bool isPayed;
		bool isReceived;

		Item * shoppingCart;
		int * quantity;
		int numberOfItems;
		int size;

	public:

		Invoice ( const Customer & , const SalesAgent & , const Date &  , int );
		Invoice ( const Invoice & );
		Invoice ( ) ;

		Invoice & operator = ( const Invoice & );
		
		void pay ( );
		void ship ( );
		void received ( );
		int calculateBill ( ) const;

		void insertItem ( const Item & , int );

		int getNumberOfItems ( ) const;
		int getSize ( ) const;

};