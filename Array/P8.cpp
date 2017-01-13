/**
 * Minimum battery energy to complete the robot's path
 * 
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
	
	int idx=-1;
	
	for ( i=n-1; i>=1; i-- ) {
		if ( a[i] > a[i-1]){
			idx = i;
			break;
		}
	}
	
	if ( idx == -1 ) {
		cout << "Robot doesn't need any battery to start with ";
		return 0;
	}
	
	int dp[n];
	int minEnergy = 0;
	
	dp[n-1] = 0;
	
	for ( i=n-2; i>=0; i-- ) {
		if ( a[i] > a[i+1] ) {
			dp[i] = max(0, dp[i+1] - (a[i]-a[i+1]));
		}
		else
			dp[i] = dp[i+1] + a[i+1] - a[i];
	}
	
	cout << dp[0] << endl;
	
	return 0;
}