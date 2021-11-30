#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
};

node* head = NULL;

void insert_node(int  value);
void insert_node_beg(int  value);
void delete_node(int  value);
void delete_node_beg();
void display_node();

int main() {

	insert_node(1);
	insert_node(3);
	insert_node(4);
	display_node();
	insert_node_beg(4);
	display_node();
	delete_node(3);
	display_node();
	delete_node_beg();
	display_node();
	return 0;
}

void insert_node(int  value) {
	node* new_node = new node;
	if (head == NULL) {
		cout << "The linked list is empty\nThe item will be the first item!" << endl;
		head = new_node;
		new_node->item = value;
		new_node->next = NULL;
		cout << "the item has been added sucssfuly!" << endl;
		return;
	}
	node* tail = new node;
	tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new_node;
	new_node->item = value;
	new_node->next = NULL;
	cout << "the item has been added sucssfuly!" << endl;
}

void insert_node_beg(int value) {
	node* new_node = new node;
	if (head == NULL) {
		cout << "The liked list is empty!" << endl;
		head = new_node;
		new_node->item = value;
		new_node->next = NULL;
		cout << "the item has been added sucssfuly!" << endl;
		return;
	}
	new_node->item = value;
	new_node->next = head;
	head = new_node;
}

void delete_node(int  value){
	if (head == NULL) {
		cout << "the linked list is empty!" << endl;
		return;
	}
	node* current_node, * before_node;
	current_node = before_node = head;

	while (current_node->item != value) {
		before_node = current_node;
		current_node = current_node->next;
	}
	before_node->next = current_node->next;
	delete(current_node);
}

void delete_node_beg(){
	if (head == NULL) {
		cout << "the linked list is empty!" << endl;
		return;
	}
	node* delete_this_node = new node;
	delete_this_node = head;
	head = delete_this_node->next;
	delete(delete_this_node);
}

void display_node() {
	if (head == NULL) {
		cout << "the linked list is empty!" << endl;
		cout << "there is no thing to show!" << endl;
		return;
	}
	node* current_node, * tail = new node;
	current_node = head;
	while (current_node != NULL) {
		cout << current_node->item << "\t";
		current_node = current_node->next;
	}
	cout << endl;
}
