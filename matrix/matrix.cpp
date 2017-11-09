#include <stdlib.h>

#include "Matrix.h"

template < class T >
Matrix<T>::Matrix<T> ( )
{
	p = new T * [1];
	p[0] = new T [1];
}

template < class T >
Matrix<T>::Matrix<T> ( int r , int c )
{
	if ( r <= 0 || c <= 0 )
	{
		cerr << "Invalid number of rows or columns" <<endl;
		exit ( 0 );
	}
	
	p = new T* [ row ];
	for ( int i = 0 ; i < r ; i++ )
		p[i] = new T [ column ];
}

template < class T >
Matrix<T>::Matrix<T> ( Matrix<T> & m )
{
	row = m.row ;
	column = m.column ;

	p = new T* [ row ];
	for ( int i = 0 ; i < row ; i++ )
		p[i] = new T [ column ];

	for ( i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			p[i][j] = m.p[i][j];
	}
}

template < class T >
T& Matrix<T>::at ( int r , int c )
{
	if ( !p )
		exit ( 0 );

	if ( r < 0 || r >= row || c < 0 || c >= column )
	{
		cerr << "Invalid row or column" <<endl;
		exit ( 0 ) ;
	}
	
	return p[r][c];
}

template < class T >
int Matrix<T>::isIdentity ( ) const
{
	if ( !p )
		exit ( 0 );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			if ( ( p[i][j] == 0 && i == j ) || ( p[i][j] == 1 && i != j ) )
				return 0;
	}

	return 1;
}

template < class T >
int Matrix<T>::isRectangular ( ) const
{
	if ( row != column )
		return 1;
	return 0;
}

template < class T >
int Matrix<T>::isDiagonal ( ) const
{
	if ( !p )
		exit ( 0 );

	int counter = 0;
	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
		{
			if ( p[i][j] == 0 && i == j )
				return 0;

			if( p[i][j] != 0 && i == j )
				counter++ ;
		}
	}

	if ( counter < 1 )
		return 0;
	return 1;
}

template < class T >
int Matrix<T>::isNullMatrix ( ) const 
{
	for ( int i = 0 ; i < row ; i++ )
		for ( int j = 0 ; j < column ; j++ )
			if ( p[i] != 0 )
				return 0;

	return 1;
}

template < class T >
Matrix<T> Matrix<T>::transpose ( ) const
{
	if ( !p )
		exit ( 0 );

	Matrix<T> transpos ( row , column );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			transpos.p[i][j] = p[j][i];
	}

	return transpos;
}

template < class T >
bool Matrix<T>::isUpperTriangular ( ) const
{
	if ( !p )
		exit ( 0 );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			if ( p[i][j] == 0 && !( i > j ) )
				return false;
	}

	return true;
}

template < class T >
bool Matrix<T>::isLowerTriangular ( ) const
{
	if ( !p )
		exit ( 0 );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			if ( p[i][j] == 0 && !( i < j ) )
				return false;
	}

	return true;	
}

template < class T >
int Matrix<T>::isTriangular ( ) const
{
	if ( isUpperTriangular ( ) )
		return 1;
	else if ( isLowerTriangular ( ) )
		return 1;
	
	return 0;
}

template < class T >
int Matrix<T>::isSymmetric ( ) const
{
	if ( !p )
		exit ( 0 );

	Matrix<T> transpos ( transpose ( ) );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			if ( p[i][j] != transpos.p[i][j] )
				return 0;
	}

	return 1;
}

template < class T >
Matrix<T> Matrix<T>::add ( const Matrix<T> & m ) const
{
	if ( !p || !m.p )
		exit ( 0 );

	if ( row != m.row || column != m.column )
	{
		cout << "Not a valid order " << endl;
		exit ( 0 );
	}

	Matrix<T> sum ( row , column );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			sum.p[i][j] = p[i][j] + m.p[i][j];
	}
	
	return sum;
}

template < class T >
Matrix<T> Matrix<T>::minus ( const Matrix<T> & m ) const
{
	if ( !p || !m.p )
		exit ( 0 );

	if ( row != m.row || column != m.column )
	{
		cout << "Not a valid order " << endl;
		exit ( 0 );
	}

	Matrix<T> difference ( row , column );

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < column ; j++ )
			difference.p[i][j] = p[i][j] - m.p[i][j];
	}
	
	return difference;
}

template < class T >
Matrix<T> Matrix<T>::multiply ( const Matrix<T> & m ) const
{
	if ( !p || !m.p )
		exit ( 0 );

	if ( row != m.column )
	{
		cout << "Not a valid order " << endl;
		exit ( 0 );
	}

	Matrix<T> product ( row , m.column );
	T sum;

	for ( int i = 0 ; i < row ; i++ )
	{	
		for ( int j = 0 ; j < column ; j++ )
		{
			sum = 0;
			for ( int k = 0 ; k < column ; k++ )
			{
				sum = sum + ( p[i][k] * m.p[k][j] );
			}

			product.p[i][j] = sum;
		}
	}
	
	return product;
}

template < class T >
int Matrix<T>::isEqual ( const Matrix<T> & m ) const
{
	if ( !p || !m.p )
		exit ( 0 );

	if ( row != m.row || column != m.column )
		return 0;

	for ( int i = 0 ; i < row ; i++ )
	{
		for ( int j = 0 ; j < row ; j++ )
			if ( p[i][j] != m.p[i][j] )
				return 0;
	}

	return 1;
}
