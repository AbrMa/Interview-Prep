#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_permutation(string& s1, string& s2) {
	if (s1.size() != s2.size())
		return false;
	unordered_map<char,int> freq;
	for (int i = 0; i < s1.size(); i++)
		freq[s1[i]]++, freq[s2[i]]--;
	for (auto fr : freq)
		if (fr.second != 0)
			return false;
	return true;
}

int main () {
	string s1, s2;
	cin >> s1 >> s2;
	if (is_permutation(s1,s2))
			cout << "Is permutation" << endl;
	else cout << "Not permutation" << endl;
	return 0;
}
