#include "contact.h"

class SalesAgent
{
	private:

		Contact address;
		int lastCommissionAmount;

	public:

		SalesAgent ( const CString & nm , const CString & ad , const CString & ph , int cm );
		SalesAgent ( );

		void setLastCommissionAmount ( int );
		int getLastCommissionAmount ( ) const;
};