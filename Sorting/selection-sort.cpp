#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>);
void swap(int &num1, int &num2);
void selectionSort(vector<int> &);

int main() {
	
	vector<int> vect = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	cout << "Before:\t";
	printArray(vect);

	selectionSort(vect);

	cout << "After:\t";
	printArray(vect);


	return 0;
}

void printArray(vector<int> vect) {
	for (auto element : vect)
		cout << element << "\t";

	cout << endl;
}

void swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void selectionSort(vector<int> &vect) {
	
	int len = vect.size();
	int min_index;

	for (int i = 0; i < len - 1; i++) {
		
		min_index = i;
		
		for (int j = i + 1; j < len; j++) {
			if (vect.at(j) < vect.at(min_index)) {
				min_index = j;
			}
		}

		swap(vect[i], vect[min_index]);
	}
}

