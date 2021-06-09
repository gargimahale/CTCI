#include <bits/stdc++.h>
using namespace std;

/*
Assume you have a method is a Substring which checks if one word is a
substring of another. Given two strings, s1 and s2, write code to
check if s2 is a rotation of s1 using only one call to isSubstring
(e.g., "waterbottle" is a rotation of" erbottlewat").
*/

void isRotation(const string s1, const string s2) {
    int len = s1.length();
    if (len == s2.length() && len > 0) {
        string temp = s1 + s1;
        return isSubstring(temp, s2);
    }
    return false;
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << isRotation(s1, s2) << "\n";
    return 0;
}

// Here runtime varies as per isSubstring.
// But if you assume that isSubstring runs for O(A+B)
// then the overall runtime is O(n)