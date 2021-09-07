#include <iostream>
#include <stack>
using namespace std;

class Queue { 
	private:
		stack <int> push_stack;
		stack <int> pop_stack;
	public:
		bool isempty() {
			if (push_stack.empty() && pop_stack.empty()) {
				return true;
			}
			return false;
		}

		void enqueue (int x) {
			push_stack.push(x);
		}

		int dequeue () {
			if (pop_stack.empty()) {
				while (push_stack.empty() == false) {
					pop_stack.push(push_stack.top());
					push_stack.pop();
				}
			}
			int top = pop_stack.top();
			pop_stack.pop();
			return top;	
		}
};

int main () {
	Queue q;

	for (int i = 1; i <= 5; i++) {
		q.enqueue(i*10);
	}

	while (!q.isempty()) {
		cout << q.dequeue() << endl;
	}
	return 0;
}
