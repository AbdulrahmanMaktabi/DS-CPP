#include <iostream>
using namespace std;

class LinkedList {
private:
	struct node {
		int item;
		node* next;
	};

	node* head, * tail;
	int length;
public: 

	LinkedList() {
		length = 0;
		head = NULL;
		tail = NULL;
	}

	void insertLast(int item) {
		node* new_node = new node;
		new_node->item = item;
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

	void display() {
		if (head == NULL)
			cout << "LikedList Is Empty!" << endl;
		else {
			node* curr_node = head;
			while (curr_node != NULL) {
				cout << curr_node->item << "-->";
				curr_node = curr_node->next;
			}
			cout << endl;
		}
	}

	void sort() {
		node* i, * j;
		int temp;
		for (i = head; i->next != NULL; i = i->next) {
			for (j = i->next; j != NULL; j = j->next) {
				if (i->item > j->item) {
					temp = i->item;
					i->item = j->item;
					j->item = temp;
				}
			}
		}
	}
};

int main() {
	
	LinkedList node;
	
	node.insertLast(2);
	node.insertLast(6);
	node.insertLast(5);
	node.display();
	node.sort();
	node.display();
	return 0;
}
