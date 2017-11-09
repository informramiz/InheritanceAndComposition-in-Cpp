#ifndef DRIVERLICENSE_H
#define DRIVERLICENSE_H

#include "Card.h"
#include "Date.h"

class DriverLicense : public Card
{
	private:
		
		Date expirationDate;
		
		enum skill { SATISFACTORY = 1 , GOOD , BETTER , BEST };
		skill level;

	public:

		DriverLicense ( );
		DriverLicense (const CString & , int ,  const Date & , int );

		void setExpirationDate ( const Date & );
		Date getExpirationDate ( ) const;

		void setSkill ( int );
		skill getSkill ( ) const;

		virtual void print ( ) const;
};

#endif