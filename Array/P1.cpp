/***
 * Given an array and an index, partition the array such that
 * all elements to the left of it are smaler than the pivot
 * and all to its right are greater than the given pivot
 * ***/

#include <iostream>
using namespace std;

void swap(int *a, int *b ) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	// your code goes here
	
	int n, pivot;
	cin>>n>> pivot;
	
	int a[n+1],i;
	
	for ( i=0; i<n; i++ ) {
		cin>>a[i];
	}
	
	int low=0,high=n-1,equal=0;
	
	/***
	 * Array should be such that a[low..mid-1] < a[index] and a[mid...k] = a[index]
	 * a[k+1...high] > a[index]
	 * */
	 
	 
	 while(equal<=high) {
	 	if ( a[equal] < pivot ) {
	 		swap(&a[low++], &a[equal++]);
	 	}
	 	else if ( a[equal] == pivot )
	 		equal++;
	 	else {
	 		swap(&a[high--], &a[equal]);
	 	}
	 }
	 
	 for ( i=0; i<n; i++ )
	 	cout<<a[i]<<" " ;
	 
	return 0;
}