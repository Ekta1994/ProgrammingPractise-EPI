/**
 * Given a permutation, compute its next and the previous
 * 
 * For finding next:
 * 	- Scan from right till a[i]> a[i+1] i.e. find the longest decreasing suffix
 * 	- Let it break at index i, if it doesn't no other greater permutation exists
 * 	- Find the smallest number greater than a[i] in the suffix (lets say this number is ele )
 * 	- Swap a[i] and ele
 * 	- Sort the remaining suffix, or just reverse it as we know that it was a decreasing suffix
 * 
 * 
 * For finding previous
 * 	- Scan from right till a[i] < a[i+1] i.e. find the longest increasing suffix
 * 	- Let it break at index i, if it doesn't no other previous permutation exists
 * 	- Find the largest number smaller than a[i] in the suffix (lets say this number is ele )
 * 	- Swap a[i] and ele
 * 	- Sort the remaining suffix, or just reverse it as we know that it was a decreasing suffix
 * 
**/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	return 0;
}