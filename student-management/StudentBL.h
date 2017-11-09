#include "StudentDL.h"

class StudentBL
{
	private:

		StudentDL student;

	public:

		StudentBL ( );

		bool addStudent ( const Student & );
		bool deleteStudent ( const Student & );

		bool editStudent ( const Student & );
};