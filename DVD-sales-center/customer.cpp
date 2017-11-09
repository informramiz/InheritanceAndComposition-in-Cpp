#include "Customer.h"

Customer::Customer ( )
{
	shippingAddress[0] = '\0';
	cardNumber[0] = '\0';
}

Customer::Customer ( const CString & nm , const CString & ad , const CString & ph 
					, const CString & ship , const CString & card ):address ( nm , ad , ph ) 

{
		shippingAddress = ship;
		cardNumber = card;
}

void Customer::setCardNumber ( const CString & card )
{
	cardNumber = card;
}

CString Customer::getCardNumber ( ) const
{
	return cardNumber;
}

void Customer::setShippingAddress ( const CString & s )
{
	shippingAddress = s;
}

CString Customer::getShippingAddress ( ) const
{
	return shippingAddress;
}



