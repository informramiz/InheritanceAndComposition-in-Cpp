#include "Student.h"
#include <stdio.h>

class StudentDL
{
	private:

		fstream file;
		const char * name;

		bool isPresent ( int rNumber ) ;

	public:

		StudentDL ( );
		bool write ( const Student & );

		bool replace ( int , const Student & );
		bool deleteStudent ( int );
};