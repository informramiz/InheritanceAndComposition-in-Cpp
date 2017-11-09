#include "StudentBL.h"

class StudentView
{
	private:

		StudentBL student;

	public:

		StudentView ( );

		void add ( const Student & );
		void deleteStudent ( const Student & );

		void edit ( const Student & );
};