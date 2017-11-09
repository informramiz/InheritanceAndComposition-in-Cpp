#include "StudentView.h"

StudentView::StudentView ( )
{
	
}

void StudentView::add ( const Student & s )
{
	student.addStudent ( s );
}

void StudentView::deleteStudent ( const Student & s )
{
	student.deleteStudent ( s );
}

void StudentView::edit ( const Student & s )
{
	student.editStudent ( s );
}