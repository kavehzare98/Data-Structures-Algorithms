// Practice 1: Here is where I will implement a Linked List Data Structure (with no tail)

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* CreateNewNode(int newData);
void DeallocateNode(Node* node);
//void PushFront(int newData, Node* &head);
//int TopFront(Node* head);
//void PushBack(int newData);
//int TopBack(Node* head);
//void PopBack(Node* &head);
//bool Find(int findVal, Node* head);
//void Erase(int deleteVal, Node* &head);
//bool isEmpty(Node* head);
//void AddBefore(Node* node, int val);
//void AddAfter(Node* node, int val);

int main() {
	
	Node* headPtr = nullptr;
	headPtr = CreateNewNode(1);

	cout << headPtr->data << endl;
	cout << headPtr->next << endl;

	DeallocateNode(headPtr);
	
	return 0;
}


Node* CreateNewNode(int newData) {
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;
	return newNode;
}

void DeallocateNode(Node* node) {
	delete node;
	node = nullptr;
}

