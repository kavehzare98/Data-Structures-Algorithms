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
void PushBack(int newData, Node* head);
int TopBack(Node* head);
int PopBack(Node* &head);
bool Find(int findVal, Node* head);
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

	for (int i = 6; i <= 10; i++) {
		PushBack(i, headPtr);
	}

	printLeftToRight(headPtr);

	cout << "Pop Back: " << PopBack(headPtr) << endl;

	printRightToLeft(headPtr);
	cout << endl;

	cout << "Top Front Value: " << TopFront(headPtr) << endl;
	cout << "Top Back Value: " << TopBack(headPtr) << endl;

	bool found_5 = Find(5, headPtr);
	bool found_11 = Find(11, headPtr);
	if (found_5) cout << "Found 5!" << endl;
	else cout << "5 NOT Found!" << endl;
	if (found_11) cout << "Found 11!" << endl;
	else cout << "11 NOT Found!" << endl;

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



void PushBack(int newData, Node* head) {

	Node* newNode = CreateNewNode(newData);

	while (head->next != nullptr) {
		head = head->next;
	}

	head->next = newNode;
}



int TopBack(Node* head) {
	while(head->next != nullptr) {
		head = head->next;
	}

	int top_back = head->data;
	return top_back;
}



int PopBack(Node* &head) {
	int ret_val = -1;

	if (head == nullptr)
		return ret_val;
	else if (head->next == nullptr) {
		ret_val = head->data;
		DeallocateNode(head);
		return ret_val;
	}
	else {
		Node* follow = head;
		Node* lead = head;
		lead = lead->next;

		while(lead->next != nullptr) {
			follow = lead;
			lead = lead->next;
		}
		ret_val = lead->data;
		DeallocateNode(lead);
		follow->next = lead;
	}

	return ret_val;

}



bool Find(int findVal, Node* head)
{
	bool found = false;

	while (head != nullptr && found == false) {
		if (head->data == findVal)
			found = true;
		head = head->next;
	}

	return found;
}
