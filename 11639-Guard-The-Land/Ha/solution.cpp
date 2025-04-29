#include<bits/stdc++.h>
using namespace std;

long long n, a1, a2, b1, b2, c1, c2, d1, d2, a[10001], b[10001], res, res2, res3, res4;
int main()
{
	cin >> n;
	for ( int i = 1; i <= n ; i ++ )
	{
		cin >> a1 >> a2 >> b1 >> b2; // a1, a2 ~ x1, y1 ; b1, b2 ~ x2, y2;
		cin >> c1 >> c2 >> d1 >> d2; // c1, c2 ~ x3, y3 ; d1, d2 ~ x4, y4;	
		if ( b1 < c1 || a1 > d1 || b2 < c2 || a2 > d2 ) // If no strong secured region 
		{
			res3 = ( b1 - a1 ) * ( b2 - a2 );
			res4 = ( d1 - c1 ) * ( d2 - c2 );
			cout << 0 << " " << res3 + res4 << " " << 10000 - ( res3 + res4 ) << endl;
		}
		else
		{
			// Put element into array to find max and min 
			a[1] = a1;
			a[2] = b1;
			a[3] = c1;
			a[4] = d1;
			b[1] = a2;
			b[2] = b2;
			b[3] = c2;
			b[4] = d2;
			sort ( a + 1 , a + 1 + 4 ); 	// If started in a[0] -> sort ( a, a + 4 ) 
			sort ( b + 1 , b + 1 + 4 );
			res = abs ( a[2] - a[3] );      // find distance of strong secured region of x
			res2 = abs ( b[2] - b[3] );     // find distance of strong secured region of y
			res3 = ( b1 - a1 ) * ( b2 - a2 );
			res4 = ( d1 - c1 ) * ( d2 - c2 );
			cout << res * res2 << " " << ( res3 + res4 ) - ( res * res2 ) * 2 << " " << 10000 - (( res3 + res4 ) - ( res * res2 ) * 2 + ( res * res2 )) << endl;
		}
	}
}
