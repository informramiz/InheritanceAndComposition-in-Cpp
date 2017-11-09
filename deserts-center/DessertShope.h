#include "String.h"

class DessertShope
{
	private:

		static const double taxRate;
		static const CString storeName;

		static const int maxItemNameSize;
		static const int costWidth;

	public:

		static CString cents2dollarsAndCents ( int cents );
		static int getMaxItemNameSize ( ) ;

		static double getTaxRate ( ) ;
		static CString getStoreName ( );

		static int getCostWidth ( );
};