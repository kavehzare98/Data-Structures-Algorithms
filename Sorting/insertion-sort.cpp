/*
Insertion Sort:
	Here's how insertion sort works. Essentially, it starts at the second element and performs a swap
	if the current value is less than its prior value. Then it will move on to the next value and
	perform comparisons and swaps all the way down to the first element.

Runtime Analysis:
	O(n^2) - worst case
	Best case: linear time
	Average case: O(n^2)
Spacetime Complexity:
	O(1) - constant

Best usecases:
	Useful for small lists and nearly sorted lsits as it is easy to implement.

*/


#include <iostream>
#include <vector>
using namespace std;

void swap(int &, int&);
void printList(vector<int>&);
void insertionSort(vector<int>&);

int main()
{
	vector<int> test0 = {10, 9, 7, 6, 4, 5, 3, 2, 1};
	vector<int> test1 = {3, 3, 3, 2, 2, 2, 0, 1, 0};

	cout << "Before Insertion Sort:\t";
	printList(test0);
	printList(test1);

	insertionSort(test0);
	insertionSort(test1);

	cout << "After Insertion Sort:\t";
	printList(test0);
	printList(test1);

	return 0;
}


void swap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void printList(vector<int> &nums) {
	for (auto num : nums)
		cout << num << " ";
	cout << endl;
}

void insertionSort(vector<int> &nums) {
	int len = nums.size();

	for (int i = 1; i < len; i++) {

		for (int j = i; j >= 0; j--) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
		}
	}

}
