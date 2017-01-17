#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define NUM_FILES 3

typedef int iType;

/** currently 3 files with 5 records each
    records in every file is sorted
	Stock name always of 1 character
	record in a file is of the form tradeTime,stockname
	1.) Create a heap of size NUM_FILES
	2.) Fill in the heap with the first entry of every file
	3.) Heapify it
	4.) Whichever file's record is on root of the heap, that is the current minimum, write that in the output file and read the next record of the file whose record was the root.
	5.) Keep doing until we have read all the records of this file
**/

struct heapNode{
	iType stockTime;
	char stockName;
	iType fileNumber;
};

iType heapSize;
heapNode heapAr[NUM_FILES];

iType stringToInt(string timeS) {

	iType num = 0;
	for (int i = 0; i < timeS.length(); i++)
		num = num * 10 + (timeS[i] - '0');

	return num;
}

void insertInHeap(int tradeTime, char sName, int index, int fNo) {
	struct heapNode tempNode;
	tempNode.stockTime = tradeTime;
	tempNode.stockName = sName;
	tempNode.fileNumber = fNo;

	heapAr[index] = tempNode;
}

void minHeapify(int i, int heapSize) {
	
	if (i> heapSize)
		return;

	int index = i;

	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < heapSize && heapAr[leftChild].stockTime < heapAr[i].stockTime) {
		index = leftChild;
	}

	if (rightChild < heapSize && heapAr[rightChild].stockTime < heapAr[index].stockTime)
		index = rightChild;

	if (index != i) {
		heapNode hn = heapAr[index];
		heapAr[index] = heapAr[i];
		heapAr[i] = hn;

		minHeapify(index, heapSize);
	}

}

int main(){

	ofstream fOut;
	ifstream fileObject[NUM_FILES];
	string record;
	string filePrefix = "f";
	string extension = ".txt";

	int i;

	for (i = 0; i < NUM_FILES; i++) {

		string fileName = filePrefix + (char)(i + 1 + '0') + extension;
		fileObject[i].open(fileName);

		if (fileObject[i].is_open()) {
			getline(fileObject[i], record);

			string stockTime = record.substr(0, record.length() - 2);
			iType st = stringToInt(stockTime);
			char sName = record[record.length() - 1];
			insertInHeap(st, sName,i,i+1);
		}
		else
			cout << "Couldn't open file : " << fileName << "\n";
	}
	
	/*cout << "The heap is : ";

	for (i = 0; i < NUM_FILES; i++) {
		cout << heapAr[i].stockName << " " << heapAr[i].stockTime << " " << heapAr[i].fileNumber << endl;
	}*/

	heapSize = NUM_FILES;
	minHeapify(0, heapSize);

	int fileReadCnt = 0; 
	int stocksRead = 0;

	//cout << "Stocks in sorted order are as follows \n";

	fOut.open("stocks.txt");

	while (fileReadCnt < NUM_FILES ) {

		//cout << "From file : " << heapAr[0].fileNumber << " stock Name : " << heapAr[0].stockName << " with trade time as : " << heapAr[0].stockTime << endl;
		stocksRead++;

		fOut << "Stock Name : " << heapAr[0].stockName << " with trade time as : " << heapAr[0].stockTime << endl;

		int currFnum = heapAr[0].fileNumber;

		// read the next record of this file

		if (!fileObject[currFnum-1].eof()) {
			getline(fileObject[currFnum-1], record);
			string stockTime = record.substr(0, record.length() - 2);
			iType st = stringToInt(stockTime);
			char sName = record[record.length() - 1];
			insertInHeap(st, sName, 0, currFnum);
		}
		else{
			// we have read all the records of this file
			fileReadCnt++;
			//cout << "File completely read: " << currFnum << endl;
			heapAr[0] = heapAr[heapSize - 1];
			heapSize--;
		}

		minHeapify(0, heapSize);

	}

	cout << "Total stocks read : " << stocksRead << endl;

	return 0;
}