#include <iostream>
using namespace std;

struct Node {
	int key;
	Node* next;
};

Node* createNewNode(int val);


int main() {

	Node* headPtr = nullptr;
	Node* newNode = nullptr;
	for (int i = 1; i <= 3; i++) {
		newNode = createNewNode(i);
		newNode->next = headPtr;
		headPtr = newNode;
	}

	for (int i = 4; i <= 6; i++) {
		Node* follow = headPtr;
		Node* lead = headPtr;
		lead = lead->next;

		newNode = createNewNode(i);

		while (lead != nullptr)
		{
			follow = lead;
			lead = lead->next;
		}
		
		follow->next = newNode;
	}

	// Print List
	Node* temp = headPtr;

	while (temp != nullptr)
	{
		cout << temp->key << " -> ";
		temp = temp->next;
	}
	
	while (headPtr != nullptr)
	{
		temp = headPtr;
		headPtr = headPtr->next;
		delete temp;
		temp = nullptr;
	}



	return 0;
}


Node* createNewNode(int val) {
	Node* newNode = new Node();
	newNode->key = val;
	newNode->next = nullptr;
	return newNode;
}
