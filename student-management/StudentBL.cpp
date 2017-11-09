#include "StudentBL.h"

StudentBL::StudentBL ( )
{

}

bool StudentBL::addStudent ( const Student & s )
{
	return student.write ( s );
}

bool StudentBL::deleteStudent ( const Student & s )
{
	return student.deleteStudent ( s.getRollNumber ( ) );
}

bool StudentBL::editStudent ( const Student & s )
{
	CString name;
	int rollNumber;

	cout << "Enter new name : " ;
	cin >> name;

	cout << "Enter new Roll number : ";
	cin >> rollNumber;

	Student s2 ( name , rollNumber );

	return student.replace ( s.getRollNumber ( ) , s2 );
}