#include "Item.h"

class CD : public Item
{
	private:

		CString publisher;

	public:

		CD ( const CString & n , const CString & d , int p 
			, const CString & publish );

		CD ( );

		void setPublisher ( const CString & ) ;
		CString getPublisher ( ) const;
};