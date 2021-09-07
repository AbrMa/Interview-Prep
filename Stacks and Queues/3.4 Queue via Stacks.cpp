#include <iostream>
#include <stack>
using namespace std;

class Queue { // Only positive numbers
	private:
		stack <int> push_stack;
		stack <int> pop_stack;
		int size;
		int front;
		int back;

		void prepare_elements () {
			while (push_stack.empty() == false) {
				push_stack.push(pop_stack.top());
				push_stack.pop();
			}
		}
	public:
		bool isempty() {
			if (push_stack.empty() && pop_stack.empty()) {
				return true;
			}
			return false;
		}

		int get_back() {
			return back;
		}

		int get_front () {
			prepare_elements();
			front = pop_stack.top();
			return front;
		}

		void enqueue (int x) {
			back = x;
			push_stack.push(x);
		}

		int dequeue () {
			if (isempty()) {
				cout << "Error stack is empty" << endl;
				return -1;
			}
			if (pop_stack.empty()) {
				prepare_elements();
			}
			int x = pop_stack.top();
			pop_stack.pop();
			front = pop_stack.top();
			return x;	
		}
};

int main () {
	Queue q;
	if (q.isempty())
		cout << "concha de la madre\n";
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	if (!q.isempty())
		cout << "hola madre\n";

	cout << q.get_front() << endl;
	return 0;
}
