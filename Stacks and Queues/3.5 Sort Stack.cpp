#include <iostream>
#include <stack>
using namespace std;

stack <int> reverse(stack <int> s1) {
	stack <int> s2;
	int ordered_numbers = 0;
	while (ordered_numbers < (s1.size() + s2.size())) {
		int current_number = s1.top();
		s1.pop();
		bool processed = false;
		int moved = 0;
		while (processed == false) {
			if (s2.empty()) {
				s2.push(current_number);
				processed = true;
			}
			else if (s2.top() >= current_number) {
				s2.push(current_number);
				processed = true;
			}
			else {
				moved++;
				s1.push(s2.top());
				s2.pop();	
			}
		}

		for (int i = 1; i <= moved; i++) {
			s2.push(s1.top());
			s1.pop();
		}
		ordered_numbers = s2.size();
	}
	return s2;
}

void print_stack (stack <int> s) {
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}

int main () {
	stack <int> s;
	s.push(5);
	s.push(3);
	s.push(-2);
	s.push(4);
	s.push(-1);
	s.push(-2);

	print_stack (s);
	
	s = reverse(s);

	print_stack(s);

	return 0;
}
