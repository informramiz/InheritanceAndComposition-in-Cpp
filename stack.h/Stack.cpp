#include "Stack.h"

template < class T >

Stack < T >::Stack ( int s )
{
	if ( s <= 0 )
		exit ( 0 );

	size = s;
	top = -1;

	stackPtr = new T [ size ];
}

template < class T >
void Stack< T >::push ( const T & value )
{
	if ( !isFull ( ) )
		stackPtr[ ++ top ] = value;
	else
		cout << "Stack is Full" << endl;
}

template < class T >
T Stack<T>::pop ( )
{
	if ( !isEmpty ( ) )
		return stackPtr[top --];
	else
		cout << "Stack is empty" << endl;
}

template < class T >
T Stack<T>::stackTop ( ) const
{
	if ( !isEmpty ( ) )
		return stackPtr[top];
	else
		cout << "Stack is empty" << endl;
}

template < class T >
int Stack<T>::isEmpty ( ) const
{
	return top == -1;
}

template < class T >
int Stack<T>::isFull ( ) const
{
	return top == size - 1;
}

template < class T >
int Stack<T>::getCapacity ( ) const
{
	return size;
}