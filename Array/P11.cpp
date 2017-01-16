/**
 * Getting the length of longest contingous increasing subarray
 * Approach1: Linearly iterate the array, keep track of what maximum subarray length we are getting. O(n)
 * Approach2: Involves a small heuristic in approach1. 
 * Lets say, we got current inc length as L till index i, then start iterating from i+L instead of i.
 * Note: Do proper backward checks also
 **/ 

#include <iostream>
using namespace std;

#define MAX 100

int n;
int a[MAX];

int main() {
	// your code goes here
	
	cin>>n;
	
	int i;
	
	for ( i=0; i<n; i++ )
		cin>>a[i];
	
	int prevIdx = 0;
	int currLen=1, maxLen=1;
	
	i=1;
	
	while(i<n) {
		
		if ( a[i] > a[i-1] ) {
			currLen++;
			prevIdx = i;
		}
		else {
			maxLen = max(maxLen, currLen);
			prevIdx = i;
			i = i + currLen; // next potential index from where our increasing subarray will start
			
			currLen = 1;
			
			/**
			 * For cases like 2,5,1,13,10,12
			 * First increasing subarray we get is (2,5) with length 2.
			 * Next subarray whose length>2 can exist after 10 only 
			 * i.e. we can skip elements (1,13) as the elements between [5...10] will not give any subarray whose length will be greater than 2.
			 * But it is possible that some subarray includes within itself the element 10.
			 * Ex: 2,5,3,8,10,12 and subarray is (3,8,10,12).
			 * Thus we do backward check from element 10
			 **/
			int j = i-1;
			
			while( j>=prevIdx && a[j] < a[j+1] ) {
				currLen++;
				j--;
			}
			
			maxLen = max(maxLen, currLen);
		}
		
		i++;
	}
	
	maxLen = max(maxLen, currLen);
	
	cout << "Maximum length is : " << maxLen << endl;
	
	return 0;
}