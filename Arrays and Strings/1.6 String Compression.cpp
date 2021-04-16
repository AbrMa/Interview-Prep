#include <iostream>
#include <string>

using namespace std;

string string_compression (string& str) {
	string compressed_string = "";
	for (int i = 0, j; i < str.size(); i = j) {
		int repetitions = 0;	
		for (j = i ; j < str.size(); j++){
			if (str[i] == str[j])
				repetitions++;
			else break;
		}
		compressed_string.push_back(str[i]);
		string rep = to_string(repetitions);
		for (char c : rep)
			compressed_string.push_back(c);
	}
	if (compressed_string.size() < str.size())
		return compressed_string;
	return str;
}

int main () {
	string str;
	cout << "Input -> ";
	cin >> str;
	cout << string_compression(str) << endl;
	return 0;
}
