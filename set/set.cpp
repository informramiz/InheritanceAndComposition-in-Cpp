#include "Set.h"

template < class T >
Set<T>::Set<T> ( int n )
{
	capacity = ( n > 0 ) ? n : 1 ;
	data = new T[capacity];

	numberOfElements = 0;
}

template < class T >
Set<T>::Set<T> ( Set<T> & s )
{
	capacity = s.capacity ;
	numberOfElements = s.numberOfElements ;

	data = new T[capacity];

	for ( int i = 0 ; i < capacity ; i++ )
		data[i] = s.data [i];
	
}

template < class T >
void Set<T>::insert ( T value )
{
	if ( !data )
		exit ( 0 );

	if ( !isFull ( ) )
	{
		if ( !isCommonElement ( value ) )
			data[ numberOfElements++ ] = value;
	}
	else
		cout << "\nThere is no free space\n";
}

template < class T >
void Set<T>::remove ( T value )
{
	if ( !data )
		exit ( 0 );
	
	if ( !isEmpty ( ) )
	{
		int location = findLocation ( value );

		shiftElementsToLeft ( location );
		numberOfElements --;
	}
	else
		cout << "\nThere are no elements to remove\n" ;
}

template < class T >
void Set<T>::input ( )
{
	if ( !data )
		exit ( 0 );

	T temp;
	for ( int i = 0 ; i < capacity ; i++ )
	{
		cin >> temp;
		insert ( temp );
	}
}

template < class T >
void Set<T>::print ( ) const
{
	if ( !data )
		exit ( 0 );

	if ( numberOfElements == 0 )
		cout << '{' << '}' << endl;
	else
	{
			cout << '{' ;
			for ( int i = 0 ; i < numberOfElements ; i++ )
			{
				cout << data[i] ;

				if ( i != numberOfElements - 1 )
					cout << ',' ;
			}
			cout << '}' << endl;
	}
}

template < class T >
bool Set<T>::isCommonElement ( T element ) const
{
	if ( !data )
		exit ( 0 );

	for ( int i = 0 ; i < numberOfElements ; i++ ) 
		if ( data[i] == element )
			return true;
	
	return false;
}

template < class T >
Set<T> Set<T>::unionOfSet (const Set<T> & s ) const
{
	if ( !data || !s.data )
		exit ( 0 );

	Set<T> unionSet ( numberOfElements + s.numberOfElements );


	for ( int i = 0 ; i < numberOfElements ; i++ )
		unionSet.insert( data[i] );

	for ( i = 0 ; i < s.numberOfElements ; i++ )
		if ( !isCommonElement ( s.data [i] ) )
			unionSet.insert ( s.data [i] );

	return unionSet;

}

template < class T >
Set<T> Set<T>::intersection ( const Set<T> & s ) const 
{
	if ( !data || !s.data )
		exit ( 0 );

	Set<T> intersectionSet ( s.numberOfElements  );

	for ( int i = 0 ; i < s.numberOfElements && i < numberOfElements ; i++ )
		if ( isCommonElement ( s.data [i] ) ) 
			intersectionSet.insert ( s.data[i] );
		
	return intersectionSet;
}

template < class T >
Set<T> Set<T>::difference ( const Set<T> & s ) const
{
	Set<T> difference ( numberOfElements + s.numberOfElements );

	for ( int i = 0 ; i < numberOfElements ; i++ )
	{
		if ( !s.isCommonElement ( data[i] ) )
			difference.insert ( data[i] );
	}

	return difference;
}

template < class T >
Set<T> Set<T>::crossProduct ( const Set<T> & s ) const
{

	Set<T> product ( numberOfElements * s.numberOfElements );

	for ( int i = 0 ; i < numberOfElements ; i++ )
	{
		for ( int j = 0 ; j < s.numberOfElements ; j++ )
			product.insert ( data[i] *  s.data[j] );
	}

	return product;
}

template < class T >
Set<T> Set<T>::symmetricDifference ( const Set<T> & s ) const
{
	Set<T> difference ( numberOfElements + s.numberOfElements );
	
	for ( int i = 0 ; i < numberOfElements ; i++ )
		if ( !s.isCommonElement ( data[i] ) )
			difference.insert ( data[i] );


	for ( i = 0 ; i < s.numberOfElements ; i++ )
		if ( !isCommonElement ( s.data[i] ) )
			difference.insert ( s.data[i] );


	return difference;
}

template < class T >
int Set<T>::getCapacity ( ) const
{
	return capacity;
}

template < class T >
int Set<T>::getCardinality ( ) const
{
	return numberOfElements ;
}

template < class T >
void Set<T>::shiftElementsToLeft ( int limit )
{

   for ( int i = limit ; i < numberOfElements - 1 ; i++ )
   	data[i] = data[i+1];
}

template < class T >
bool Set<T>::isEmpty ( ) const
{
	if ( numberOfElements == 0 ) 
		return true;

	return false;
}

template < class T >
bool Set<T>::isFull ( ) const
{
	if ( numberOfElements == capacity )
		return true;

	return false;
}

template < class T >
int Set<T>::findLocation ( T value ) const
{
	for ( int i = 0 ; i < numberOfElements ; i++ )
		if ( data[i] == value )
			return i;

	return -1;
}