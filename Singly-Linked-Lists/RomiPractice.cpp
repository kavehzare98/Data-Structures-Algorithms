#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* createNewNode(int val);
bool Find(int data, Node* head);
void Erase(int delVal, Node* &head);


int main() {

	Node* headPtr = nullptr;
	Node* newNode = nullptr;
	for (int i = 1; i <= 5; i++) {
		newNode = createNewNode(i);
		newNode->next = headPtr;
		headPtr = newNode;
	}

	for (int i = 6; i <= 10; i++) {
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
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << endl;
	
	Erase(5, headPtr);

	Erase(1, headPtr);

	Erase(10, headPtr);

	// Print List again
	temp = headPtr;
	while (temp != nullptr)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << endl;

	bool found5 = Find(3, headPtr);
	bool found7 = Find(7, headPtr);

	if (found5)
		cout << "Found 5!" << endl;
	else
		cout << "5 NOT Found!" << endl;

	if (found7)
		cout << "Found 7!" << endl;
	else
		cout << "7 NOT Found!" << endl;


	// Deallocate all
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
	newNode->data = val;
	newNode->next = nullptr;
	return newNode;
}

bool Find(int findVal, Node* head) {
	bool found = false;

	while (head != nullptr)
	{
		if (head->data == findVal)
			found = true;
		head = head->next;
	}

	return found;
}


void Erase(int delVal, Node* &head) {
	if (head->data == delVal){
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	else {
		Node* follow = head;
		Node* lead = head;
		lead = lead->next;

		while(lead != nullptr && lead->data != delVal) {
			follow = lead;
			lead = lead->next;
		}

		if (lead->data == delVal)
		{
			Node* temp = lead;
			follow->next = lead->next;
			delete temp;
			temp = nullptr;
		}
	}
}

