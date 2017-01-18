#include <iostream>
using namespace std;

#define MAX 101

int r,c;
int a[MAX][MAX];


int main() {
	// your code goes here
	
	cin>>r>>c;
	
	int i,j;
	
	for ( i=0; i<r; i++ ) {
		for ( j=0; j<c; j++ )
			cin>>a[i][j];
	}
	
	cout << "The spiral ordering of the matrix is : " ;
	
	int rowLow = 0, rowHigh = r-1, colLow = 0 , colHigh = c-1;
	
	int cnt = 0;
	
	while( cnt <(r*c) ) {
		
		for ( i=colLow; i<=colHigh; i++ ) {
			cout << a[rowLow][i] <<" ";
			cnt++;
		}
			
		rowLow++;
		
		for ( i=rowLow; i<= rowHigh; i++ ) {
			cout << a[i][colHigh] <<" " ;
			cnt++;
		}
			
		colHigh--;
		
		if ( rowHigh >= rowLow ) {
			for ( i= colHigh ; i>= colLow; i-- ) {
				cout << a[rowHigh][i] <<" ";
				cnt++;
			}
			
			rowHigh--;
		}
		
		if ( colLow <= colHigh) {
			for ( i= rowHigh; i>= rowLow; i-- ) {
				cout << a[i][colLow] <<" " ;
				cnt++;
			}
			colLow++;
		}
	}
	
	return 0;
}