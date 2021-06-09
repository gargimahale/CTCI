#include <bits/stdc++.h>
using namespace std;

/*
Q. Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the
"true" length of the string. (Note: if implementing in Java, please use a character array so
that you can perform this operation in place.)

*/

void urlify(char *inp, int trueLen) {
    int num_spaces = 0;
    int first_space_idx = -1;
    bool checkAlpha = false;

    for (int i = 0; i < trueLen; ++i) {
        if (inp[i] == ' ') {
            if (num_spaces == 0) {
                first_space_idx = i;
            }
            ++num_spaces;
        }
        if (isalpha(inp[i])) {
            checkAlpha = true;
        }
    }

    // strings with spaces
    if (num_spaces == 0 || !checkAlpha) return;

    for (int i = trueLen - 1; i > first_space_idx; --i) {
        if (inp[i] == ' ') {
            --num_spaces;
            continue;
        }
        inp[i + 2 * num_spaces] = inp[i];
        inp[i] = ' ';
    }

    for (int i = 0; i < trueLen; ++i) {
        if (inp[i] == ' ') {
            inp[i] = '%';
            inp[i + 1] = '2';
            inp[i + 2] = '0';
        }
    }
    // return inp;
}

int main() {
    char str[] = "Mr John Smith   ";
    urlify(str, 13);
    cout << str << "\n";
    return 0;
}

// TC: O(len(inp)), SC: O(1)