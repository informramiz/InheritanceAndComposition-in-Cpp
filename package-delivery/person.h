#include <iostream>
#include <string>
using namespace std;

class Person
{
	private:

		string name;
		string address;
		string city;
		string state;
		int zipCode;

	public:

		Person ( const string & n , const string & ad , const string & c , const string & s , int z );

		void setName ( const string & );
		string getName ( ) const;

		void setAddress ( const string & );
		string getAddress ( ) const;

		void setCity ( const string &  );
		string getCity ( ) const;

		void setState ( const string & );
		string getState ( ) const;

		void setZipCode ( int );
		int getZipCode ( ) const;

		void print ( ) const;
};
