#include "DriverLicense.h"

DriverLicense::DriverLicense ( )
{
	level = SATISFACTORY ;
}

DriverLicense::DriverLicense (const CString & n , int num , const Date & d 
							  , int value ):Card ( n , num ) , expirationDate ( d )
{
	switch ( value )
	{
		case 1:
			level = SATISFACTORY;
			break;

		case 2:
			level = GOOD;
			break;

		case 3:
			level = BETTER;
			break;

		case 4:
			level = BEST;
			break;

		default:
			level = SATISFACTORY;
			break;
	}
}

void DriverLicense::setExpirationDate ( const Date & value )
{
	expirationDate = value;
}

Date DriverLicense::getExpirationDate ( ) const
{
	return expirationDate;
}

void DriverLicense::print ( ) const
{
	cout << "Driver license : ";
	cout << "\n\nName : " << getName ( ) ;
	cout << "\nID number : " << getNumber ( );

	cout << "\nExpiration Date : ";
	expirationDate.print ( );
	
	cout << "Skill : " ;
	switch ( level )
	{
		case SATISFACTORY:
			cout << "satisfactory" << endl;
			break;

		case GOOD:
			cout << "good" << endl;
			break;

		case BETTER:
			cout << "better" << endl;
			break;

		case BEST:
			cout << "best" << endl;
			break;

		default:
			cout << "Satisfactory" << endl;
			break;
	}
}