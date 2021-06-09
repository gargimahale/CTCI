#include <bits/stdc++.h>
using namespace std;

/*
Q. Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*/


// Ask ASCII Set/ Extended ASCII Set (256 Characters) or
// Unicode (1,114,112 characters) -> from 0x000000 to 0x10FFFF

// In this case just assuming ASCII Set of 128 Chars

bool isUnique(string& str) {
    if (str.size() > 128) return false;

    vector<bool> check(128, false);
    for (char ch : str) {
        if (check[ch]) return false;
        check[ch] = true;
    }
    return true;
}

// OR

// Reduces space usage but in worst case gives a complexity of O(n^2)

bool isUnique(string& str) {
    int n = str.size(), check = 0;
    for (int i = 0; i < n; ++i) {
        int val = str[i] - 'a';
        if ((check & (1 << val))) {
            return false;
        }
        check |= (1 << val);
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << isUnique(s) << "\n";
    return 0;
}
// TC: O(1) - As we will never iterate through more than 128 chars
// SC: O(1)


// If you didn't want to assume the character set is fixed,
// SC: O(c) TC: O(min(c, n)) or O(c)
// where c is the size of the character set.