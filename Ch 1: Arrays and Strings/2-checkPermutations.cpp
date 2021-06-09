#include <bits/stdc++.h>
using namespace std;

// Ask regarding whitespace and case sensitivity

/*
Q. Given two strings, write a method to decide if one is a permutation of the other.
*/

bool isPermutation(string& a, string& b) {

    if (a.size() != b.size()) return false;

    vector<int> letters(128);

    for (int i = 0; i < a.size(); ++i) {
        letters[a[i] - 'a']++;
        letters[b[i] - 'a']--;
    }

    for (int i = 0; i < 128; ++i) {
        if (letters[i] < 0) return false;
    }
    return true;
}


int main() {
    string a, b;
    cin >> a >> b;
    cout << isPermutation(a, b) << "\n";
    return 0;
}

// TC: O(max(a, b)), SC: O(1)