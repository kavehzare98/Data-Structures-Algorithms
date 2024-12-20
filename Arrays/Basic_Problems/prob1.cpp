#include <vector>
#include <iostream>
using namespace std;

void printAlternates(vector<int> vect);

int main() {
// Alternate elements of an array
// Given an array arr[], the task is to print every alternate element of the array starting from the first element.
// Examples:

// Input: arr[] = [10, 20, 30, 40, 50]
// Output: 10 30 50
//Explanation: Print the first element (10), skip the second element (20), print the third element (30), skip the fourth element(40) and print the fifth element(50).


// Input: arr[] = [-5, 1, 4, 2, 12]
// Output: -5 4 12
	vector<int> vect1;
//	vect1.resize(10);

	for (int i = 1; i <= 10; i++) {
      		vect1.push_back(i);
	}

	vector<int> vect2;
//	vect2.resize(5);
	for (int i = 10; i <= 50; i += 10) {
		vect2.push_back(i);
	}
	
	printAlternates(vect1);
	printAlternates(vect2);

	return 0;
}

void printAlternates(vector<int> vect) {
	for (int i = 0; i < vect.size(); i += 2)
	{
		cout << vect.at(i) << " ";
	}

	cout << endl;
}
