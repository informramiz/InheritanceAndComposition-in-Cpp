#include "String.h"

class Item
{
	private:

		int price;
		CString name;
		CString description;

	public:

		Item ( );
		Item ( const CString & nm , const CString & descript , int );

		void setName ( const CString & );
		CString getName ( ) const;

		void setDescription ( const CString & );
		CString getDescription ( ) const;

		void setPrice ( int ) ;
		int getPrice ( ) const;
};