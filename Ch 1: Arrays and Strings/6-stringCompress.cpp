#include <bits/stdc++.h>
using namespace std;

/*
Q. Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not
become smaller than the original string, your method should return the original string. You can
assume the string has only uppercase and lowercase letters (a - z).
*/

string stringCompressor(string s1) {
    string cpy = "";
    int i = 0;
    while (i < s1.size()) {
        int j = i;
        while (j < s1.size() && s1[i] == s1[j]) {
            ++j;
        }
        cpy += s1[i];
        if (j - i >= 1) {
            string temp = to_string(j - i);
            for (char ch : temp) {
                cpy += ch;
            }
        }
        i = j;
    }
    // cout << cpy;
    return cpy.size() < s1.size() ? cpy : s1;
}

int main() {
    string s1 = "aabcccccaaa";
    cout << stringCompressor(s1) << "\n";
    return 0;
}

// TC: O(n), SC: O(n)