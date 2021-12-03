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
		return head == NULL;
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
	void insertAtPos(int pos, int value) {
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
	void deleteBeg() {
		if (head == NULL) {
			cout << "LinkedList Is Empty!" << endl;
			return;
		}
		node* curr_node = head;
		head = curr_node->next;
		delete(curr_node);
		length--;
	}

	void deleteLast() {
		if (head == NULL) {
			cout << "LinkedList Is Empty!" << endl;
			return;
		}
		node* curr_node, * prev_node;
		curr_node = head->next;
		prev_node = head;
		while (curr_node != tail) {
			prev_node = curr_node;
			curr_node = curr_node->next;
		}
		prev_node->next = NULL;
		tail = prev_node;
		delete(curr_node);
		length--;
	}

	void deleteAtPos(int pos) {
		if (head == NULL)
			cout << "Linked List Is Empty!" << endl;
		else if (pos < 0 || pos > length)
			cout << "Error In Position!" << endl;
		else {
			if (pos == 0)
				deleteBeg();
			else if (pos == length)
				deleteLast();
			else {
				node* curr_node, * prev_node;
				curr_node = head->next;
				prev_node = head;
				for (int i = 1; i < pos; i++) {
					prev_node = curr_node;
					curr_node = curr_node->next;
				}
				prev_node->next = curr_node->next;
				delete (curr_node);
				length--;
			}
		}
	}
	void reverse() {
		if (head == NULL) {
			cout << "linkedLIst Is Null" << endl;
			return;
		}
		node* prv, * curr, * next;
		prv = NULL;
		curr = head;
		next = curr->next;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prv;
			prv = curr;
			curr = next;
		}
		head = prv;
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

	void printHead() {
		cout << head->item << endl;
	}
	void printTail() {
		cout << tail->item << endl;
	}
};
int main() {

	LinkedList node;
	node.insertFirst(3);
	node.insertFirst(4);
	node.insertLast(19);
	node.insertLast(18);
	node.insertLast(17);
	node.insertLast(16);
	node.display();
	node.reverse();
	node.display();
	node.sort();
	node.display();
	return 0;
}
