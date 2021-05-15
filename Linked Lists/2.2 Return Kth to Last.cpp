#include <iostream>
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

void print_list(Node* current) {
	while (current) {
		cout << current -> data << " ";
		current = current -> next;
	}
	cout << endl;
}

//assuming 0 < k <= n
//where n is the size of the list
int return_kth(Node* head, int k) {
	Node* last = head;
	Node* kth = head;
	int fixed_size = 0;
	while (last && fixed_size != k) {	
		fixed_size++;
		last = last -> next;
	}
	while (last) {
		kth = kth -> next;
		last = last -> next;
	}
	return kth -> data;
}

int main () {
	Node* head = NULL;
	head = insert_node(head, 1);
	head = insert_node(head, 2);
	head = insert_node(head, 3);
	head = insert_node(head, 4);
	print_list(head);
	cout << return_kth(head, 1) << endl;
	cout << return_kth(head, 2) << endl;
	cout << return_kth(head, 3) << endl;
	cout << return_kth(head, 4) << endl;
	return 0;
}
