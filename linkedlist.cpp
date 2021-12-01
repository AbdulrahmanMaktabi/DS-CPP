#include <iostream>
using namespace std;

class LinkedList {
	struct node {
		int item;
		node* next;
	};
	node* head, * tail;
	int length;
public:
	LinkedList() {
		head = tail = NULL;
		length = 0;
	}
	void printLength() {
		cout << length << endl;
	}
	bool isEmpty() {
		return head == NULL ? true : false;
	}
	void insertFirst(int value) {
		node* new_node = new node;
		new_node->item = value;
		length++;
		if (head == NULL) {
			new_node->next = NULL;
			tail = head = new_node;
			return;
		}
		new_node->next = head;
		head = new_node;
	}
	void insertLast(int value) {
		node* new_node = new node;
		new_node->item = value;
		if (head == NULL) {
			head = tail = new_node;
			new_node->next = NULL;
			return;
		}
		tail->next = new_node;
		tail = new_node;
		new_node->next = NULL;
		length++;
	}
	void insertAtPos(int pos , int value) {
		if (pos < 0 || pos > length) {
			cout << "Error In Postition! " << endl;
		}
		else {
			node* new_node = new node;
			new_node->item = value;
			if (pos == 0)
				insertFirst(value);
			else if (pos == length)
				insertLast(value);
			else {
				node* curr_node = head;
				for (int i = 1; i < pos; i++) {
					curr_node = curr_node->next;
				}
				new_node->next = curr_node->next;
				curr_node->next = new_node;
				length++;
			}
		}
	}
	void display() {
		if (head == NULL)
			cout << "LikedList Is Empty!" << endl;
		else {
			node* curr_node = head;
			while (curr_node != NULL) {
				cout << curr_node->item << "\t";
				curr_node = curr_node->next;
			}
			cout << endl;
		}
	}
};
int main() {
	LinkedList test;
	test.insertFirst(3);
	test.insertFirst(4);
	test.insertLast(19);
	test.insertLast(18);
	test.insertLast(17);
	test.insertLast(16);
	test.display();
	test.insertFirst(1);
	test.display();
	test.insertLast(99);
	test.display();
	test.insertAtPos(4 , 222);
	test.display();

	return 0;
}
