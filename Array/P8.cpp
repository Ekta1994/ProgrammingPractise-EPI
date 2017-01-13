/**
 * Minimum battery energy to complete the robot's path
 * Given array input as coordinates of the path along which robot moves, find the minimum battery energy required to complete the path
 * if it loses energy while going towards an increasing path (a[i+1]>a[i]) and gains energy otherwise ( a[i] > a[i+1] )
 **/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	// considering movement along altitude, thus only one of x, y or z coordinate input
	int i,a[n+1];
	
	for ( i=0; i<n; i++ ) 
		cin>>a[i];
	
	// dp[i] indicates what minimum energy is required to reach the end point from i.
	
	int dp[n];
	int minEnergy = 0;
	
	dp[n-1] = 0;
	
	for ( i=n-2; i>=0; i-- ) {
		if ( a[i] > a[i+1] ) {
			dp[i] = max(0, dp[i+1] - (a[i]-a[i+1]));  // energy gain while moving from a[i] to a[i+1]
		}
		else
			dp[i] = dp[i+1] + a[i+1] - a[i]; // energy loss here
	}
	
	cout << dp[0] << endl;
	
	return 0;
}