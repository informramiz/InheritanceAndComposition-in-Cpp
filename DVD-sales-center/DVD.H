#include "Item.h"

class DVD : public Item
{
	private:

		CString publisher;

	public:

		DVD ( const CString & n , const CString & d , int p 
			, const CString & publish );

		DVD ( );

		void setPublisher ( const CString & ) ;
		CString getPublisher ( ) const;
};