#include <iostream>
using namespace std;

struct Node {
	char data;
	Node* next;
};

Node* insert_node(Node* head, int x) {
	Node* new_node = new Node();
	new_node -> data = x;
	new_node -> next = head;
	return new_node;
}

void print_list(Node* print_node) {
	while (print_node) {
		cout << print_node -> data << " ";
		print_node = print_node -> next;
	}
	cout << endl;
}

void delete_middle_node(Node* &middle_node){
	Node* prev = middle_node;
	middle_node -> data = middle_node -> next -> data;
	middle_node -> next = middle_node -> next -> next;	
	delete prev;
}	

int main () {
	Node* head = NULL;
	head = insert_node(head, 'f');
	head = insert_node(head, 'e');
	head = insert_node(head, 'd');
	head = insert_node(head, 'c');
	head = insert_node(head, 'b');
	head = insert_node(head, 'a');
	print_list(head);
	Node* del = head;
	for (int i = 1; i <= 2; i++) {
		del = del -> next; // del -> data = c
	}
	delete_middle_node(del);
	print_list(head);
	return 0;
}
