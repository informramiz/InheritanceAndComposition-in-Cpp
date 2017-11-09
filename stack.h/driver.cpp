#include "Stack.cpp"
#include "Date.h"
#include "Time.h"
#include "Rational.h"
#include "String.h"

//template class Stack < CString >;
void main ( )
{
	Stack < CString > t ( 100 );
	
	CString str1 = "Ramiz";
	CString str2 = "Raja";

	t.push ( str1 );
	t.push ( str2 );
	cout << t.pop ( ) << ' ' << t.pop ( ) << endl;
}