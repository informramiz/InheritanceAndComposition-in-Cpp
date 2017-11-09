#include "Person.h"

class Package 
{
	private:

		Person sender;
		Person receiver;

		float cost;
		float weight;

	public:

		Package ( const string & sName , const string & rName , const string & sAd , 
			const string & rAd , const string & scity , const string & rcity , 
			const string & sState , const string & rstate , int sZip , int rZip , float cst , float w ) ;

		void setCost ( int );
		double getCost ( ) const;

		void setWeight ( int );
		double getWeight ( ) const;

		double calculateCost ( ) const;
};