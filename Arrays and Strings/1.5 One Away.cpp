#include <iostream>
#include <string>

using namespace std;

bool has_one_or_zero_edits(string word, string edited_word) {
	if (edited_word.size() > word.size())
		swap(word,edited_word);
	int unprocessed_characters = word.size(), word_index = 0, edited_word_index = 0;
	while (word_index < word.size() && edited_word_index < edited_word.size()) {
		if (word[word_index] == edited_word[edited_word_index])	
			edited_word_index++, unprocessed_characters--;	
		else if (word[word_index] != edited_word[edited_word_index] && word.size() == edited_word.size())
			edited_word_index++;	
		word_index++;	
	}
	if (unprocessed_characters > 1)
		return false;
	return true;
}

int main() {
	string str1 = "apple", str2 = "aple";
	if (has_one_or_zero_edits(str1,str2))
		cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
