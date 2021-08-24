#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
Q. Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards.
A permutation is a rearrangement of letters. The palindrome does not need to
be limited to just dictionary words.
*/

bool checkPalindromePerm(string& str) {

	int odd = 0;
	vector<int> freq(128, 0);

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') continue;

		// converts all characters to lowercase
		str[i] = tolower(str[i]);
		freq[str[i]]++;
		if (freq[str[i]] % 2 == 1) {
			++odd;
		}
		else {
			--odd;
		}
	}

	return odd <= 1;
}

int main() {
	string str = "Tact Coa";
	cout << checkPalindromePerm(str) << "\n";
	return 0;
}

// TC: O(N), SC: O(128) -> O(c)
// Where N is the length of the string
// Where c is the character set