#include <iostream>
#include <string>
using namespace std;

/*
Q. There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to
check if they are one edit (or zero edits) away.
*/

bool isOneEditDistance(string s, string t) {
    int a = s.size(), b = t.size();
    if ((a == 0 && b == 0) || abs(a - b) > 1) return false;

    if (b < a) swap(s, t);

    int i = 0, j = 0;
    bool foundDiff = false;

    while (i < s.size() && j < t.size()) {
        if (s[i] != t[j]) {

            if (foundDiff) return false;
            foundDiff = true;

            if (s.size() == t.size()) {
                // replace
                ++i;
            }
        }
        else {
            ++i;
        }
        ++j;
    }
    return (foundDiff == false && a == b) ? false : true;
}

int main() {
    string s1 = "rocky";
    string s2 = "rock";
    cout << isOneEditDistance(s1, s2) << "\n";
    return 0;
}

// TC: O(min(s1, s2)), SC: O(1)
// where s1 and s2 are the lengths of the two strings