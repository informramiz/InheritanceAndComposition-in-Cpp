#ifndef CONTACT_H
#define CONTACT_H

#include <iostream.h>
#include "string.h"

class Contact
{
	private:

		CString name;
		CString address;
		CString phoneNumber;

	public:

		Contact ( );
		Contact ( const CString & nm , const CString & ad , const CString & ph );

		void setName ( const CString & n );
		CString getName ( ) const;

		void setAddress ( const CString & ad );
		CString getAddress ( ) const;

		void setPhoneNumber ( const CString & ph ) ;
		CString getPhoneNumber ( ) const;
};

#endif