#include "StudentView.h"

void main ( )
{
	Student s ( "Ramiz" , 1 );
	Student s2 ( "Raja" , 2 );
	Student s3 ( "ahmad" , 3 );

	StudentView sv;
	//sv.add ( s );
	//sv.add ( s3 );
	sv.edit  ( s );
}