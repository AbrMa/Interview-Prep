#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
	int data;
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

Node* remove_dups(Node* head) {
	unordered_map<int,bool> seen;
	Node* current = head;
	Node* prev = NULL;
	while (current) {
		if (seen[current -> data]) {
			prev -> next = current -> next;
			delete current;
		}
		else {
			seen[current -> data] = true;
			prev = current;
		}
		current = prev -> next;
	}
	return head;
}

int main () { 
	Node* head = NULL;
	head = insert_node(head, 5);
	head = insert_node(head, 2);
	head = insert_node(head, 5);
	head = insert_node(head, 1);
	head = insert_node(head, 1);
	head = insert_node(head, 2);
	head = insert_node(head, 2);
	print_list(head);
	head = remove_dups(head);
	print_list(head);
	return 0;
}
