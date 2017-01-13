/***
 * Check if a board game is winnable
 * For any index i, you can move a[i] steps further. Find if you can recah the end point or not
 */

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	int i,a[n+1];
	
	for ( i=0; i<n; i++ )
		cin>>a[i];
		
	bool canReach = 0;
	int maxSteps=0;
	
	for (i=0; i<n && i<=maxSteps; i++ ) {
		maxSteps = max(maxSteps, i+a[i]);
		
		if ( maxSteps >= n-1 ){
			canReach = 1;
			break;
		}
	}
	
	if ( canReach == 1 ) 
		cout << "Can reach the last index";
	else
		cout << "Cannot reach the last index";
	
	return 0;
}