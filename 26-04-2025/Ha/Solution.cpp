#include<bits/stdc++.h>
using namespace std;

long long n, res;
int gcd ( int num1 , int num2 ) // khu de quy 
{
	int res1;
	while ( num2 != 0 )
	{
		res1 = num1 % num2;
		num1 = num2;
		num2 = res1;
	}
	return num1;
}
int main()
{
	while ( true )
	{
		cin >> n ;
		if ( n == 0 ) return 0 ;
		for ( int i = 1 ; i <= n - 1; i ++ )
		{
			for ( int j = i + 1 ; j <= n ; j ++ )
			{
				res += gcd( i , j );
				//cout << __gcd( i , j ) << " ";
			}
			//cout << endl;
		}
		cout << res << endl;
		res = 0;
	}
}
