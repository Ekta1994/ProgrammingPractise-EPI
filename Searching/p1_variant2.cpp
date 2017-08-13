/**
Problem: Find maximum element in the array which is first increasing and then decreasing

Method 1: Linearly scan the array till a[i] > a[i+1], then a[i] is the maximum element in the array O(n)
Method 2: Apply binary search on the middle element. O(logn)
**/

#include<iostream>
using namespace std;

int find_max_element ( int low, int high, int a[]) {
	int ans = -1;

	int mid;
	while(low<=high) {
		mid = low + (high-low)/2;
		if ( high == low ) {
			ans = a[low];
			break;
		}
		else if ( high == low+1 ) {
			if ( a[high] > a[low] )
				ans = a[high];
			else
				ans = a[low];
			break;
		} else {
			if ( a[mid] >= a[mid+1] && a[mid] >= a[mid-1] ) {
				ans = a[mid];
				break;
			} else if ( a[mid] >= a[mid+1] && a[mid] < a[mid-1]) {
				high = mid-1;
			} else
				low = mid+1;
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

	int max = find_max_element(0,n-1,a);

	cout << "Maximum element is " << max << endl;

	return 0;
}