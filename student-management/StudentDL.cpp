#include "StudentDL.h"
#include <stdlib.h>

StudentDL::StudentDL ( )
{
	name = "file.txt";

	file.open ( name , ios::app );
	file.close ( );
}

bool StudentDL::write ( const Student & s )
{
	file.open ( name , ios::app );

	if ( !file )
	{
		cout << "Main file could not be opened" << endl;
		exit ( 1 );
	}

	if ( isPresent ( s.getRollNumber ( ) ) )
	{
			cout << "A student with this roll number already exist " << endl;
			return false;
	}

	file << s;

	file.close ( );

	return true;
}

bool StudentDL::deleteStudent ( int rollNumber )
{
	file.open ( name , ios::in );

	if ( !file )
	{
		cout << " file in delete could not be opened" << endl;
		exit ( 1 );
	}

	if ( !isPresent ( rollNumber ) )
	{
		file.close ( );
		cerr << "Unknown student" << endl;
		return false;
	}

	const char * nam = "file2.txt";

	fstream file2 ( nam , ios::out );

	if ( !file2 )
	{
		cout << "file in deleteStudent could not be opened" << endl;
		exit ( 1 );
	}

	Student s;

	file >> s;

	while ( !file.eof ( ) )
	{
		if ( s.getRollNumber ( ) != rollNumber )
		{
			file2 << s;
		}

		file >> s;
	}

	file2.close ( );
	file.close ( );

	remove ( name );
	rename ( nam , name );

	return true;
}

bool StudentDL::replace ( int rollNumber , const Student & s )
{
	file.open ( name , ios::in );

	if ( !file )
	{
		cout << " file in replace could not be opened" << endl;
		exit ( 1 );
	}

	if ( !isPresent ( rollNumber ) )
	{
		file.close ( );
		cerr << "Unknown student" << endl;
		return false;
	}

	const char * name1 = "file2.txt";

	fstream file2 ( name1 , ios::out );

	if ( !file2 )
	{
		cout << "file in replaceStudent could not be opened" << endl;
		exit ( 1 );
	}

	Student s2;

	file >> s2;
	while ( !file.eof ( ) )
	{
		if ( s2.getRollNumber ( ) == rollNumber )
			file2 << s;
		else
		{
			file2 << s2;
		}

		file >> s2; 
	}
	
	file.close ( );
	file2.close ( );

	remove ( name );
	rename ( name1 , name );
	
	return true;
}

bool StudentDL::isPresent ( int rNumber ) 
{
	Student s;

	int start = file.tellg ( );
	file.seekg ( 0 );
	file.seekp ( 0 );

	if ( !file.eof ( ) )
		file >> s;

	while ( s.getRollNumber ( ) != rNumber && !file.eof ( ) )
	{
		file >> s;
	}

	if ( s.getRollNumber ( ) == rNumber )
	{
		file.seekg ( start );
		file.seekp ( start );
		return true;
	}

	file.seekg ( start );
	file.seekp ( start );
	return false;
}



