#include <iostream.h>

template < class T >
class Matrix
{
	private:
		
		T ** p ;
		int row;
		int column;

		bool isUpperTriangular ( ) const;
		bool isLowerTriangular ( ) const;

	public:
		
		Matrix ( );
		Matrix ( int , int );
		Matrix ( Matrix & );

		~Matrix ( )
		{
			if(!p)
			{
				exit(0);
			}
			else if ( p )
			{
				for ( int i = 0 ; i < row ; i++ )
					delete [] p[i];
				delete [] p;
			}
		}

		T& at ( int , int );
		int isIdentity ( ) const;
		int isRectangular ( ) const;

		int isDiagonal ( ) const;
		int isNullMatrix ( ) const;
		Matrix transpose ( ) const;

		int isTriangular ( ) const;
		int isSymmetric ( ) const;

		Matrix add ( const Matrix & ) const;
		Matrix minus ( const Matrix & ) const;
		Matrix multiply ( const Matrix & ) const;

		int isEqual ( const Matrix & ) const;
};