// Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.
// 
// Note: If the second largest element does not exist, return -1.
// 
// Examples:
// 
// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.
// 
// 
// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.
// 
// 
// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 there is no second largest element.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int findNLargest(vector<int>, int);

int main() {
	vector<int> test = {5, 11, 11, 5, 11, 11, 11, 1};

	cout << "Finding the 2nd largest element: " << findNLargest(test, 2) << endl;
	cout << "Finding the 3rd largest element: " << findNLargest(test, 3) << endl;
	cout << "Finding the 4th largest element: " << findNLargest(test, 4) << endl;

	return 0;
}


// Given Array of integers and N, e.g. when N = 1, the function finds
int findNLargest(vector<int> vect, int N) {

	set<int, greater<int>> s(vect.begin(), vect.end());
	if (N > s.size())
	{
		return -1;
	}

	int num;
	int count = 1;
	for (auto element : s)
	{
		if (count == N)
		{
			num = element;
			break;
		}
		count++;
	}

	return num;
}
