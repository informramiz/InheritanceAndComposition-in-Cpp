#include "Item.h"

class Book : public Item
{
	private:

		CString author;

	public:

		Book ( const CString & n , const CString & d , int p 
			, const CString & a );
		Book ( );

		void setAuthor ( const CString & );
		CString getAuthor ( ) const;
};