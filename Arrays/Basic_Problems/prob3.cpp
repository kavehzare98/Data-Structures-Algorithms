// Largest Element
// Given an array arr[] of size n, the task is to find the largest element in the given array. 
// 
// Examples: 
// 
// Input: arr[] = {10, 20, 4}
// Output: 20
// Explanation: Among 10, 20 and 4, 20 is the largest. 
// 
// 
// Input : arr[] = {20, 10, 20, 4, 100}
// Output : 100
//
#include <iostream>
#include <vector>

int findLargest(std::vector<int>);

int main() {

	std::vector<int> vect = {5, 10, 11, 2, 1};
	std::sort(vect.begin(), vect.end());

	std::cout << "Largest: " << findLargest(vect) << std::endl;

	return 0;
}

int findLargest(std::vector<int> vect) {

	std::sort(vect.begin(), vect.end());

	int val = *(vect.end() - 1);

	return val;
}

