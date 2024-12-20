// Given an array, arr of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn’t exist.
// Input: arr[] = [1, 2, 3, 4], x = 3
// Output: 2
// Explanation: There is one test case with array as [1, 2, 3 4] and element to be searched as 3. Since 3 is present at index 2, the output is 2.
// 
// 
// Input: arr[] = [10, 8, 30, 4, 5], x = 5
// Output: 4
// Explanation: For array [1, 2, 3, 4, 5], the element to be searched is 5 and it is at index 4. So, the output is 4.
// 
// 
// Input: arr[] = [10, 8, 30], x = 6
// Output: -1
// Explanation: The element to be searched is 6 and its not present, so we return -1.
//
#include <vector>
#include <iostream>

using namespace std;

int linearSearch(vector<int> vect, int findVal);

int main() {

	vector<int> test;
	const int SIZE = 50;

	test.resize(SIZE);

	for (int i = 0; i < SIZE; i++) {
		test[i] = i + 1;
	}

	int find = 5;
	cout << find << " is located at index: " << linearSearch(test, find) << endl;
	find = 10;
	cout << find << " is located at index: " << linearSearch(test, find) << endl;	
	find = 100;
	cout << find << " is located at index: " << linearSearch(test, find) << endl;	
	
	return 0;
}



int linearSearch(vector<int> vect, int findVal)
{
	int found = -1;

	for (int i = 0; i < vect.size() && found == -1; i++) {
		if (vect.at(i) == findVal)
			found = i;
	}

	return found;
}

