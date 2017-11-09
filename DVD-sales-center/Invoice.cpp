#include "Invoice.h"

Invoice::Invoice ( const Customer & c , const SalesAgent & sa , const Date & d , int count )
	:client ( c ) , sA ( sa ) , orderDate ( d )
{
	size = ( count > 0 ) ? count : 1 ;
	shoppingCart = new Item[size];

	quantity = new int[size];
	numberOfItems = 0;
}

Invoice::Invoice ( )
{
	size = 5;
	numberOfItems = 0;
	
	shoppingCart = new Item [ size ];
	quantity = new int[ size ];
}

Invoice::Invoice ( const Invoice & i ):client ( i.client ) , sA ( i.sA )
	,orderDate ( i.orderDate )
{
	numberOfItems = i.numberOfItems ;
	size = i.size ;
	
	shoppingCart = new Item [ size ];
	quantity = new int[size];

	for ( int j = 0 ; j < size ; j++ )
	{
		shoppingCart[j] = i.shoppingCart[j];
		quantity[j] = i.quantity [j];
	}
}

Invoice & Invoice::operator = ( const Invoice & i )
{
	client = i.client ;
	sA = i.sA ;
	orderDate = i.orderDate ;
	
	numberOfItems = i.numberOfItems ;
	size = i.size ;
	
	shoppingCart = new Item [ size ];
	quantity = new int[size];

	for ( int j = 0 ; j < size ; j++ )
	{
		shoppingCart[j] = i.shoppingCart[j];
		quantity[j] = i.quantity [j];
	}

	return *this;
}

void Invoice::insertItem ( const Item & i , int q )
{
	if ( getNumberOfItems ( ) < getSize ( ) )
	{
		shoppingCart[ numberOfItems ] = i ; 
		quantity[ numberOfItems ] = ( q >= 0 ) ? q : 1 ;
		
		numberOfItems ++ ;
	}
}

int Invoice::calculateBill ( ) const
{
	int bill = 0;

	for ( int i = 0 ; i < getNumberOfItems ( ) ; i++ )
		bill = bill + shoppingCart[i].getPrice ( ) * quantity[i];

	return bill;
}

int Invoice::getNumberOfItems ( ) const
{
	return numberOfItems;
}

int Invoice::getSize ( ) const
{
	return size;
}

void Invoice::pay ( ) 
{
	isPayed = 1 ;
}

void Invoice::received ( ) 
{
	isReceived = 1;
}

void Invoice::ship ( )
{
	isShipped = 1;
}

