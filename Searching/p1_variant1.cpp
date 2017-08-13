/**
Problem: Find any local minima in the array

Method 1: Linearly scan the array and check a[i] less than a[i-1] and a[i+1], then a[i] is the local minima. O(n)
Note, for first and last element one neighbour has to be considered.
Method 2: Apply binary search on the middle element. O(logn)
**/

#include<iostream>
using namespace std;

int find_local_minima ( int low, int high, int a[], int n) {
	int ans = -1;

	int mid;
	while(low <=high ) {
		mid = low + (high-low)/2;

		if ((mid==0 || a[mid-1]>= a[mid]) && (mid==n-1 || a[mid+1]>= a[mid])) {
			ans = mid;
			break;
		} else {
			if ( mid-1 >= 0 && a[mid]-1 < a[mid]) {
				// a local minima always exists on the left side
				high = mid-1;
			} else {
				low = mid+1;
			}
		}
	}

	return ans;
}

int main() {

	int n;
	cin>>n;

	int i,a[n+1];
	for ( i=0; i<n; i++ )
		cin>>a[i];

	int position = find_local_minima(0,n-1,a,n);

	cout << "Local minima is at index : " << position << endl;

	return 0;
}