#include <bits/stdc++.h>
using namespace std;

/*
Q. There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to
check if they are one edit (or zero edits) away.
*/

bool oneEditAway(string& s1, string& s2) {
    int a = s1.length(), b = s2.length();

    // can't be more than one edit
    if (abs(a - b) > 1) return false;

    // Get Shorter string
    if (b < a) {
        swap(s1, s2);
    }

    int idx1 = 0, idx2 = 0;
    bool foundDiff = false;

    while (idx1 < s1.size() && idx2 < s2.size()) {
        if (s1[idx1] != s2[idx2]) {

            // checks if one edit has already been encountered
            if (foundDiff) return false;
            foundDiff = true;

            // Move short pointer after one replace
            if (a == b) ++idx1;
        }
        else {
            ++idx1;
        }
        ++idx2;
    }
    return true;
}

int main() {
    string s1 = "rocky";
    string s2 = "rock";
    cout << oneEditAway(s1, s2) << "\n";
    return 0;
}

// TC: O(min(s1, s2)), SC: O(1)
// where s1 and s2 are the lengths of the two strings