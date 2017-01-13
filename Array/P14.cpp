/**
 * Find the first missing positive number.
 * Approach1: Use sorting
 * Approach2: Use hashing
 * Approach3: Coded below
 **/

#include <iostream>
using namespace std;

int eliminateNeg ( int *a, int low , int high ) {
	
	int idx = 0;
	
	for ( int i=low; i<high; i++ ) {
		if ( a[i] > 0 ) {
			a[idx++] = a[i];
		}
	}
	
	return idx;
}
 
int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	int a[n+1],i;
	
	for ( i=0; i<n; i++ ) {
		cin>>a[i]; // input can have both +ve and -ve numbers
	}
	
	// first eliminate all -ve numbers from the array
	
	n = eliminateNeg(a,0,n);
	
	if ( n == 0 ) {
		// input array had all -ve elements
		cout <<"First missing +ve number is 1";
	}
	else {
		
		int ans = -1;
		
		for ( int i=0; i<n; i++ ) {
			int ele = abs(a[i]);
		
			if ( ele <=n && a[ele-1] > 0 ) // the given array element should be in range, then only we can address it
				a[ele-1] *= -1;
		}
		
		for ( int i=0; i<n; i++ ) {
			if ( a[i] > 0 ) {
				ans = i+1;
				break;
			}
		}
		
		// all numbers from 1 to n are present in the array, thus ans is n+1
		if ( ans == -1 )
			ans = n+1;
			
		cout<< "First missing +ve number is : " << ans << endl;
		
	}
	
	return 0;
}