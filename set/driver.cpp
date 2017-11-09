#include "set.cpp"

//template class Set < int >;

void main()
{
	Set<int> s1 ( 2 ) ;
	Set<int> s2 ( 2 );

	cout << "Enter the set1 elements : \n";
	s1.input ( );

  	cout << "\ns1 is : ";
	s1.print ( );
}