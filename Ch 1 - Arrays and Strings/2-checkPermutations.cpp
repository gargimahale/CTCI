#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Ask regarding whitespace and case sensitivity

/*
Q. Given two strings, write a method to decide if one is a permutation
of the other.

*/

class Solution {
public:
    bool isPermutation(string& a, string& b) {
        int sizeA = a.size(), sizeB = b.size();
        if (sizeA != sizeB) return false;

        vector<int> letters(128);

        // O(a)
        for (int i = 0; i < sizeA; ++i) {
            letters[a[i] - 'a']++;
            letters[b[i] - 'a']--;
        }

        // O(1)
        for (int i = 0; i < 128; ++i) {
            if (letters[i] < 0) return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    string a, b;
    cin >> a >> b;
    cout << sol.isPermutation(a, b) << "\n";
    return 0;
}

// TC: O(a), SC: O(c)
// Where c is the character set
// Where a is the length of the original string