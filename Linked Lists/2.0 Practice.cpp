#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* insert_node_beg(Node* head, int x) {
	Node* new_head = new Node();
	new_head -> data = x;
	new_head -> next = head;
	return new_head;
}

Node* insert_node_nth(Node *head, int x, int n) {
	if (n == 1) {
		head = insert_node_beg(head, x);
	}
	else {
		Node* nth_minus1_node = head;
		for (int i = 1; i <= n - 2 ; i++) {
			nth_minus1_node = nth_minus1_node -> next;	
		}
		Node* new_node = new Node();
		new_node -> data = x;
		new_node -> next = nth_minus1_node -> next;
		nth_minus1_node -> next = new_node;
	}
	return head;
}

Node* reverse_list(Node *head) {
	Node* prev; 
	Node* current;
	Node* next;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current -> next;	
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;	
}	

void print_list(Node* print_node) {
	while (print_node) {
		cout << print_node -> data << " ";
		print_node = print_node -> next;
	}
	cout << endl;
}

int main () {
	Node* head;	
	head = NULL;
	head = insert_node_beg(head, 1);
	head = insert_node_beg(head, 2);
	head = insert_node_beg(head, 3);
	head = insert_node_beg(head, 4);
	print_list(head);
	head = reverse_list(head);
	print_list(head);
//	head = insert_node_nth(head, 9, 4);
//	print_list(head);
}
