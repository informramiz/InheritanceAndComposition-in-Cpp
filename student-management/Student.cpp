#include "Student.h"

Student::Student ( const CString & nm , int no )
{
	name = nm;
	rollNumber = no > 0 ? no : 1;
}

Student :: Student ( )
{
	name = '\0';
	rollNumber = 1;
}

void Student::setName ( const CString & nm )
{
	name = nm;
}

CString Student::getName ( ) const
{
	return name;
}

void Student::setRollNumber ( int value )
{
	rollNumber = value;
}

int Student::getRollNumber ( ) const
{
	return rollNumber;
}

bool Student::operator == ( const Student & ref ) const
{
	return ( name == ref.name && rollNumber == ref.rollNumber );
}

fstream & operator << ( fstream & output , const Student & value )
{
	output << value.rollNumber << ' ' << value.name << endl ;

	return output;
}

fstream & operator >> ( fstream & input , Student & value )
{
	input >> value.rollNumber >> value.name ;
	return input;
}