#include <iostream>
#include <string>

using namespace std;

bool has_all_unique(string& s) {
	int ascii[256] = {0};
	for (char c : s) {
		if (ascii[c])
			return false;
		ascii[c]++;
	}
	return true;
}

int main () {
	string s;
	cin >> s;
	if (has_all_unique(s))
		cout << "Unique" << endl;
	else cout << "Not unique" << endl;
	return 0;
}
