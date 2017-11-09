#include "contact.h"

class Customer
{
	private:

		Contact address;
		CString shippingAddress;
		CString cardNumber;

	public:

		Customer ( const CString & nm , const CString & ad , const CString & ph , 
			const CString & ship , const CString & card );
		Customer ( );

		void setShippingAddress ( const CString & );
		CString getShippingAddress ( ) const;

		void setCardNumber ( const CString & );
		CString getCardNumber ( ) const;
};