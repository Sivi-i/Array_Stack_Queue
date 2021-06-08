#include "Array_Base.h"
#include "Array.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


void verifyArray() {

	cout << "\n<-Array Constructor Test Begin->";

	cout << "\n-Default Constructor-";
	Array<int> Arr; 
	cout << "\nInitial Array Size: " << Arr.size();
	cout << "\n-Size Constructor-";
	Array<int> Arr2(5);
	cout << "\nArray 2 Init Size: " << Arr2.size();
	cout << "\n-Size & Fill Constructor-";
	Array<int> Arr3(5, 1);
	cout << "\nArray Init Size: " << Arr3.size() << " \nArray Init Data: " << Arr3.get(0);
	cout << "\n<-Array Constructor Test Successful->\n";
}

void verifyCopyConstructor() {

	cout << "\n<-Copy Constructor Test Begin->";

	cout << "\n-Copy Default Constructor-";
	
	Array<float> Arr;
	Array<float> Arr2(Arr);

	cout << "\nCopied Array Init Size: " << Arr2.size();
	Arr.~Array();
	Arr2.~Array();

	cout << "\n-Copy Size Constructor-";
	Array<int> Arr3(10);
	Array<int> Arr4(Arr3);
	cout << "\nCopied Array Init Size: " << Arr4.size();
	Arr3.~Array();
	Arr4.~Array();

	cout << "\n-Copy Size~Fill Constructor-";
	Array<int> Arr5(10, 6);
	Array<int> Arr6(Arr5);
	cout << "\nCopied Array Init Size: " << Arr6.size() << "\nCopied Array Init Data: " << Arr6.get(0);
	cout << "\n<-Copy Constructor Test Successful->\n";
}

void verifyDestructor() {

	cout << "\n<-Destructor Test Begin->";

	cout << "\n-Size Constructor-";
	Array<int> Arr(10);
	cout << "\nInit Array Size: " << Arr.size();
	Arr.~Array();
	cout << "\nException Attempt:";
	try {
		cout << "\nDestructed Array Size: " << Arr.size() << "Post-Destructor Data: " << Arr.get(0);
	}
	catch (...) {
		cout << "\nException Thrown. Success";
	}
	cout << "\n-Size~Fill Constructor-";
	Array<int> Arr2(15, 5);
	cout << "\nInit Array Size: " << Arr2.size() << "\nInit Array Data: " << Arr2.get(0);
	

		Arr2.~Array();
		cout << "\nException Attempt: ";
		try {
			cout << "\nPost Destructor Size: " << Arr2.size() << "\nPost Destructor Data: " << Arr2.get(0);
			cout << "\nException not thrown. Test Failed";
		}
		catch (...) {
			cout << "\nException Thrown. Success";
		}

		cout << "\n<-Destructor Test Successful->\n";
}

void verifyAssignmentOp() {
	Array<int> Arr(10,1);

	cout << "\n<-Assignment Operation Test Begin->";
	cout << "\n-Size Constructor-";
	Array<int> Arr3(10);
	Array<int> Arr4 = Arr3;
	cout << "\nOriginal Array Size: " << Arr3.size() << "\nCopied Array Size: " << Arr4.size();
	cout << "\nOriginal Array Length: " << Arr.size() << "\nOriginal Array Data: " << Arr.get(0);
	Array<int> Arr2 = Arr;
	cout << "\nCopied Array Length: " << Arr2.size() << "\nCopied Array Data: " << Arr2.get(0);
	cout << "\n<-Assignment Operation Test Successful->\n";
}

void verifyIndexer() {
	Array<int> Arr(2, 1);

	cout << "\n<-Indexer Method Test Begin->";
	cout << "\nData At Index 0: " << Arr[0];
	cout << "\nFilling Array w/ Ints 2, 3, and 4...";
	Arr.fill(2);
	Arr.fill(3);
	Arr.fill(4);
	cout << "\nData At Index 2: " << Arr[1];
	cout << "\nException Attempt:";
	try {
		cout << "\nException Not Thrown. Test Failed. Data: " << Arr[2];
	}
	catch (...) {
		cout << "\nException Thrown Success";
	}

	cout << "\n-Const Indexer Test-";
	const int postMethodVal = Arr[1];
	
	
	cout << "\nValue Should Be 2: " << postMethodVal;

	cout << "\n<-Indexer Method Test Successful->\n";


}

void verifyGet() {
	Array<int> Arr;
	Array<float> Arr2(5);
	Array<char> Arr3(10, 'a');

	
	cout << "\n<-Get Method Test Begin->";
	cout << "\n-Default Constructor-";
	cout << "\nException Attempt:";
	try {
		Arr.get(0);
	}
	catch (...) {
		cout << "\nException Thrown. Success";
	}

	cout << "\n-Size Constructor-";
	cout << "\nException Attempt: ";
	try {
		Arr2.get(0);
	}
	catch (...) {
		cout << "\nException Thrown. Success";
	}

	cout << "\n-Size~Fill Constructor-";
	cout << "\nData Should be 'a': " << Arr3.get(0);

	cout << "\n<-Get Method Test Successful->\n";
}

void verifySet() {
	Array<int> Arr(5);

	cout << "\n<-Set Method Test Begin->";
	cout << "\nException Attempt:";
	try {
		cout << "\nArray Isn't Empty. Test Failed. Value At Index 0: " << Arr.get(0);
	}
	catch (...) {
		cout << "\nCaught Exception. Array is Still Empty. Success";
	}
	
	cout << "\nArray Init Size: " << Arr.size();

	size_t size = 0;
	try {
		Arr.set(3, 1);
	}
	catch (...) {
		cout << "\nMethod Failed.";
	}

	cout << "\nAttempting to Grab Value 1 From Index 3: " << Arr.get(3);
	cout << "\nSuccess.";
	cout << "\n<-Set Method Test Successful->\n";
}

void verifyResize() {
	Array<char> Arr(3);

	cout << "\n<-Resize Method Test Begin->";
	cout << "\nArray Init Size: " << Arr.size();
	cout << "\nArray Init Data (Should be Blank): ";
	for (int i = 0; i < Arr.size(); i++) {
		cout << Arr[i];
	}
	Arr.resize(10);
	cout << "\nPost-Expansion Size: " <<  Arr.size();
	cout << "\nArray Init Data (Should be Blank): ";
	for (int j = 0; j < Arr.size(); j++) {
		cout << Arr[j];
	}
	Arr.resize(1);
	cout << "\nPost-Shrink Size: " << Arr.size();
	cout << "\nArray Init Data (Should be Blank): ";
	for (int k = 0; k < Arr.size(); k++) {
		cout << Arr[k];
	}
	
	cout << "\n<-Resize Method Test Success->\n";
	

}

void verifyFind() {

	Array<char> Arr(5, 'a');
	Arr.fill('b');
	Arr.fill('c');

	cout << "\n<-Find Method Test Begin->";
	cout << "\nArray Value 'c'. Index should be 2: " << Arr.find('c');

	int index = Arr.find('d');

	if (index == -1) {
		cout << "\nOut of Range Test Successful";
	}
	else {
		cout << "\nTest Failed.";
	}

	Arr.fill('e');
	Arr.fill('f');

	cout << "\nArray Val 'e' Starting at 2. Output Index should be 3: " << Arr.find('e');
	index = Arr.find('e', 4);
	if (index == -1) {
		cout << "\nOut of Range Test Successful";
	}else{
		cout << "\nTest Failed.";
	}

	cout << "\n<-Find Method Test Success->\n";
}

void verifyEquality() {
	Array<char> Arr(10, 'c');

	Array<char> Arr2(10, 'd');

	cout << "\n<-Equality Method Test Begin->";
	cout << "\n-Size~Fill Constructor-";
	if (Arr == Arr2) {
		cout << "\nArrays Equal. Success";
	}
	else {
		cout << "\nArrays Inequal. Failure";
	}

	Array<int> Arr3(10);
	Array<int> Arr4(10);

	cout << "\n-Size Constructor-";
	if (Arr3 == Arr4) {
		cout << "\nArrays Equal. Success";
	}
	else {
		cout << "\nArrays Inequal. Failure";
	}
	
	Arr4.set(1, 1);
	cout << "\nArray Data: ";
	for (int i = 0; i < Arr4.size(); i++) {
		cout << Arr4[i] << " ";
	}

	Array<float> Arr5;
	Array<float> Arr6;

	if (Arr5 == Arr6) {
		cout << "\nArrays Equal. Success";
	}
	else {
		cout << "\nArrays Inequal. Failure";
	}
	
	cout << "\n<-Equality Method Test Success->\n";
}

void verifyInequality() {
	Array<int> Arr;
	Array<int> Arr2(10);

	cout << "\n<-Inequality Method Test Begin->";

	cout << "\n-Default vs. Size Constructor-";
	if (Arr != Arr2) {
		cout << "\nArray Inequal. Success";
	}
	else {
		cout << "\nArray Equal. Failure";
	}

	Arr2.fill(1);
	Array<int> Arr3(10, 2);

	cout << "\n-Arrays w/ Different Index 0 Values-";
	if (Arr2 != Arr3) {
		cout << "\nArray Inequal. Success";
	}
	else {
		cout << "\nArray Equal. Failure";
	}

	cout << "\n<-Inequality Method Test Success->\n";
}

void verifyFill() {
	Array<int> Arr(1, 1);

	cout << "\n<-Fill Method Test Begin->";
	Arr.fill(2);

	cout << "\nException Attempt (Grabbing Val outside of Indexes):";
	try {
		cout << "\nArray Data @ Index 2. Shouldn't exist: " << Arr.get(1);
	}
	catch (...) {
		cout << "\nException Thrown. Success.";
	}

	Arr.resize(2);
	Arr.fill(2);

	cout << "\nPost-Expansion. Index 2 Grab. Expected Val -> 2: " << Arr.get(1);
	cout << "\n<-Fill Method Test Successful->\n";
}

void verifyShrink() {
	Array<char> Arr(10, 'a');
	
	cout << "\n<-Shrink Method Test Begin->";
	Arr.fill('b');
	Arr.fill('c');
	cout << "\nInit Array Size: " << Arr.size();
	cout << "\nArray Init Test Data: ";
	for (int i = 0; i < Arr.size(); i++) {
		cout << Arr.get(i) << " ";
	}

	Arr.shrink();
	cout << "\nPost-Shrink Array Size: " << Arr.size();
	cout << "\n<-Shrink Method Test Successful->\n";
}

void verifyReverse() { 
	Array<int> Arr(10, 1);
	Arr[1] = 2;
	Arr[2] = 3;
	Arr[3] = 4;

	cout << "\n<-Reverse Method Test Begin->";
	cout << "\nInit Array Data: ";
	for (int i = 0; i < Arr.size(); i++) {
		cout << Arr[i] << " ";
	}

	Arr.reverse();
	cout << "\nPost-Reverse Array Data: ";
	for (int j = 0; j < Arr.size(); j++) {
		cout << Arr[j] << " ";
	}

	cout << "\n<-Reverse Method Test Successful->\n";

}

void verifySlice() {
	cout << "\n<-Slice Method Test Begin->";

	Array<int> Arr(10, 1);
	Arr.fill(2);
	Arr.fill(3);
	Arr.fill(4);
	Arr.fill(5);
	Arr.fill(6);

	cout << "\nArray Init Size: " << Arr.size();
	cout << "\nArray Init Data: ";
	for (int i = 0; i < Arr.size(); i++) {
		cout << Arr.get(i) << " ";
	}

	cout << "\n-Default Slice Method-";
	Array<int> Arr2 = Arr.slice(4);
	cout << "\nNew Array Init Size: " << Arr2.size();
	cout << "\nNew Array Init Data: ";
	for (int j = 0; j < Arr2.size(); j++) {
		cout << Arr2.get(j) << " ";
	}

	cout << "\n-Overloaded Slice Method-";
	Array<int> Arr3 = Arr2.slice(0, 3);
	cout << "\nNew Array Init Size: " << Arr3.size();
	cout << "\nNew Array Init Data: ";
	for (int k = 0; k < Arr3.size(); k++) {
		cout << Arr3.get(k) << " ";
	}
	cout << "\n<-Slice Method Test End->\n";
}

void fixedConstructors() {
	Fixed_Array<char, 5> Arr('a');
	cout << "\n<-Fixed Array Constructor Test Begin->";
	cout << "\nFixed Array Init Size: " << Arr.size();
	cout << "\nFixed Array max_size_: " << Arr.max_size();
	//Arr.fill('c');
	cout << "\nException Attempt: ";
	try {
		cout << "Output should be Null: " << Arr.get(2);
	}catch(...){
	
	}
	cout << "\n<-Fixed Array Constructor Test End->\n";
}

void verifyStack() {
	cout << "\n<Stack Testing Begin->";
	Stack<char> stack1;
	cout << "\nTesting Stack Size: " << stack1.size();	
	stack1.~Stack();

	cout << "\nException Attempt: ";
	try {
		cout << "\nAttempt Failed. Data is: " << stack1.get(0);
	}
	catch (...) {
		cout << "\nAttempt Successful.";
	}

	Stack<int> stack2;
	cout << "\nPre Push";
	stack2.push(1);
	stack2.push(5);
	cout << "\nPost Push";
	//cout << "\nStack 2 Data @ Index 0: " << stack2.top();
	cout << "\nPre Assignment Operator";
	Stack<int> stack3 = stack2;
	cout << "\nPost Assignment Operator";
	//cout << "\nStack 3 Data @ Index 0: " << stack3.top();
	cout << "\nPre Pop";
	stack3.pop();
	cout << "\nPost Pop";
	//cout << "\nStack 3 Data @ Index 0: " << stack3.top();
	cout << "\nPre Clear";
	stack3.clear();
	cout << "\nPost Clear";
	bool isEmpty = stack3.is_empty();
	cout << "\nTesting is Empty Method (Should be true): " << isEmpty;
	cout << "\n<-Stack Testing End->\n";
}

void verifyQueue() {
	Queue<int> q;

	cout << "\n<-Queue Testing Begin->";
	cout << "\nOriginal Size: " << q.size();
	cout << "\nPre Enqueue";
	q.enqueue(1);
	cout << "\nPost Enqeue";
	cout << "\nPost Enqueue Size: " << q.size();
	cout << "\nPre Enqueue #2";
	q.enqueue(5);
	cout << "\nPost Enqueue #2";
	cout << "\nPost Enqueue #2 Size: " << q.size();
	cout << "\nPre Dequeue";
	q.dequeue();
	cout << "\nPost Dequeue Size: " << q.size();
	if (q.is_empty() == 0) {
		cout << "\nArray is_empty Test Success. Not Empty";
	}
	else {
		cout << "\nArray is_empty Test Failure. Array Empty.";
	}
	cout << "\nPre-Clear Size: " << q.size();
	q.clear();
	cout << "\nPost-Clear Size: " << q.size();
	q.enqueue(2);
	q.enqueue(3);
	cout << "\nSize: " << q.size();
	Queue<int> q2 = q;
	cout << "\nAssigned Queue Size: " << q2.size();
	cout << "\n-Copy Constructor Test-";
	Queue<int> q3(q2);
	cout << "\nCopied Queue Size: " << q3.size();

	q3.~Queue();
	cout << "\nException Attempt: ";

	try {
		q3.dequeue();
		cout << "\nException Not Thrown. Test Failure";
	}
	catch (...) {
		cout << "\nException Thrown. Test Success";
		}
}

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
	/*
	* Various Functions which tests the Methods of the Base Array Class as a Template Class
	*/

	verifyArray(); 
	verifyCopyConstructor(); 
	verifyDestructor(); 
	verifyAssignmentOp(); 
	verifyIndexer(); 
	verifyGet(); 
	verifySet(); 
	verifyResize(); 
	verifyFind();
	verifyEquality();
	verifyInequality();
	verifyFill();
	verifyShrink();
	verifyReverse();
	verifySlice();
	fixedConstructors();
	verifyStack();
	verifyQueue();


	

  return 0;
}
