#include<iostream>
using namespace std;

int find_first_occurrence ( int low, int high, int a[], int k) {
	int ans = -1;

	int mid;
	while(low<=high) {
		mid = low + (high-low)/2;
		if ( a[mid] < k )
			low = mid+1;
		else if ( a[mid] > k )
			high = mid-1;
		else {
			if (mid == 0 || (mid-1>=0 && a[mid-1]<k)) {
				ans = mid;
				break;
			} else
				high = mid-1;
		}
	}

	return ans;
}

int main() {

	int n,k;
	cin>>n>>k;

	int i,a[n+1];
	for ( i=0; i<n; i++ )
		cin>>a[i];

	int position = find_first_occurrence(0,n-1,a,k);

	if ( position == -1 )
		cout << "Element not found\n";
	else
		cout << "Element found at index " << position << endl;

	return 0;
}