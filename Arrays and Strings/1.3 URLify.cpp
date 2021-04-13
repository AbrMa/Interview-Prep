#include <iostream>
#include <string>

using namespace std;

string URLify (string& str, int& n) {
	int copy = n - 1, write = str.size() - 1;
	while (copy >= 0) {
		if (str[copy] == ' ') {
			str[write - 2] = '%';
			str[write - 1] = '2';
			str[write] = '0';
			write -= 3;
		}
		else {
			str[write] = str[copy];
			write--;
		}
		copy--;
	}
	return str;
}

int main() {
	int n = 13;
	string str = "Mr John Smith    ";
	cout << URLify(str, n) << endl;
	return 0;
}
