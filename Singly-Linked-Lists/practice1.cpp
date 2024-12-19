// Practice 1: Here is where I will implement a Linked List Data Structure (with no tail)

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* CreateNewNode(int newData);
void DeallocateNode(Node* &node);
void PushFront(int newData, Node* &head);
int TopFront(Node* head);
//void PushBack(int newData);
//int TopBack(Node* head);
//void PopBack(Node* &head);
//bool Find(int findVal, Node* head);
//void Erase(int deleteVal, Node* &head);
//bool isEmpty(Node* head);
//void AddBefore(Node* node, int val);
//void AddAfter(Node* node, int val);
void printLeftToRight(Node* head);
void printRightToLeft(Node* head);
void DeallocateList(Node* &head);

int main() {
	
	Node* headPtr = nullptr;
	for (int i = 1; i <= 5; i++) {
		PushFront(i, headPtr);
	}

	printLeftToRight(headPtr);
	printRightToLeft(headPtr);
	cout << endl;

	cout << "Top Front Value: " << TopFront(headPtr) << endl;
	// Deallocate	
	DeallocateList(headPtr);

	return 0;
}


Node* CreateNewNode(int newData) {
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;
	return newNode;
}

void DeallocateNode(Node* &node) {
	delete node;
	node = nullptr;
}

void PushFront(int newVal, Node* &head) {
	Node* newNode = CreateNewNode(newVal);
	newNode->next = head;
	head = newNode;
}

void printLeftToRight(Node* head) {
	while (head->next != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
}


void printRightToLeft(Node* head) {
	
	if (head == nullptr) {
		return;
	}

	printRightToLeft(head->next);

	cout << head->data << " -> ";

}



void DeallocateList(Node* &head) {
	Node* temp;
	while(head != nullptr) {
		temp = head;
		head = head->next;
		DeallocateNode(temp);
	}
}

int TopFront(Node* head) {
	return head->data;
}
