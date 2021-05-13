#include <bits/stdc++.h>
using namespace std;

/*
Q. Write a method to replace all spaces in a string with '%20'. You may assume that the string 
has sufficient space at the end to hold the additional characters, and that you are given the 
"true" length of the string. (Note: if implementing in Java, please use a character array so 
that you can perform this operation in place.)
*/

void urlify(string& input, int trueLength) {
    string rep = "%20";
    int i;
    auto it = prev(input.end());
    while (*it == ' ') {
        input.erase(it);
        --it;
    }
    for (i = 0 ; i < input.length() ; i++) {
        if (input[i] == ' ')
            input.replace(i, 1, rep);
    }
    cout << input;
}

// OR

// void urlify(char *inp, int trueLen) {

//     int spaces = 0, i;

//     // Count number of spaces from the true length of the string
//     for (i = 0; i < trueLen; ++i) {
//         spaces += (inp[i] == ' ');
//     }

//     // Find the length of the new string
//     int idx = trueLen + spaces * 2 - 1;

//     // Replace the original string
//     for (int j = trueLen - 1; j >= 0; --j) {
//         if (inp[j] == ' ') {
//             inp[idx--] = '0';
//             inp[idx--] = '2';
//             inp[idx--] = '%';
//         }
//         else {
//             inp[idx--] = inp[j];
//         }
//     }
//     cout << inp << "\n";
// }

int main() {
    // char str[] = "Mr John Smith   ";
    string str = "Mr John Smith   ";
    urlify(str, 13);
    return 0;
}

// TC: O(len(inp)), SC: O(1)