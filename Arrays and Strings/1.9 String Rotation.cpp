#include <iostream>
#include <string>

using namespace std;

bool is_substring(string& str, string& sub_str) {
	if (str.find(sub_str) == -1) {
		return false;
	}	
	return true;
}

bool is_rotation(string& str, string& rotated_str) {
	if (str.size() != rotated_str.size()) {
		return false;
	}
	string appended_str = rotated_str + rotated_str;
	return is_substring(appended_str, str); 
}

int main() {
	string str = "waterbottle";
	string rotated_str = "erbottlewat";
	if (is_rotation(str, rotated_str)) {
		cout << "Is rotation" << endl;	
	}
	else {
		cout << "Not a rotation" << endl;
	}
	return 0;
}
