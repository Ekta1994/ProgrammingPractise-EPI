/***
 * Given an array A that takes digits as input encoding the decimal digit D and updates A to represent D+1
 * Approach1: Start from least significant digit and propagate the carry
 * Approach2: Coded below
 ***/

#include <iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b ) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	// your code goes here
	
	vector<int> number;
	
	// input number is of 11 digits = 29959969999
	number.push_back(2);
	number.push_back(9);
	number.push_back(9);
	number.push_back(5);
	number.push_back(9);
	number.push_back(9);
	number.push_back(6);
	number.push_back(9);
	number.push_back(9);
	number.push_back(9);
	number.push_back(9);
	
	// increment the integer at last place
	number.back() += 1;
	
	for ( int i=number.size()-1; i>=0 && number[i] == 10; i-- ) {
		number[i] = 0;
		number[i-1]++;
	}
	
	if ( number[0] == 10 ) {
		number[0] = 0;
		number.insert(number.begin(),1);
	}
	
	cout << "The number +1 is : " ;
	
	for ( int i=0; i<number.size(); i++ )
		cout << number[i];
	 
	return 0;
}