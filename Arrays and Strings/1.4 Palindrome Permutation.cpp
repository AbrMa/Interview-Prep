#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

bool is_a_palindrome_permutation(string& sentence) {
	unordered_map<char,int> freq;
	for (char character : sentence)
		if (character != ' ')
			freq[tolower(character)]++;
	int odd_freq = 0;
	for (auto character : freq)
		odd_freq += character.second % 2;
	if (odd_freq > 1) 
		return false;
	return true;
}

int main()  {
	string sentence = "Tactrr CorAr";
	if (is_a_palindrome_permutation(sentence))
		cout << "True" << endl;
	else cout << "False" << endl;
	return 0;
}
