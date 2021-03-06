#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
Q. Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*/


// Ask ASCII Set/ Extended ASCII Set (256 Characters) or
// Unicode (1,114,112 characters) -> from 0x000000 to 0x10FFFF

// In this case just assuming ASCII Set of 128 Chars
class Solution{
public:
    bool isUnique(string& str) {
        // if exceeds ASCII charset count, its guaranteed to be false
        if (str.size() > 128) return false;

        vector<bool> check(128, false);
        for (char ch : str) {
            if (check[ch]) return false;
            check[ch] = true;
        }
        return true;
    }   

    // Reduces space usage but in worst case gives a complexity of O(n^2)
    bool isUnique_2(string& str) {
        int n = str.size(), check = 0;
        for (char& ch: str){
            int val = ch - 'a';
            if ((check & (1 << val)) > 0){
                return false;
            }
            check |= (1 << val);
        }
        return true;
    }   
};

int32_t main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.isUnique(s) << "\n";
    return 0;
}
// TC: O(1) - As we will never iterate through more than 128 chars
// SC: O(1)


// If you didn't want to assume the character set is fixed,
// SC: O(c) TC: O(min(c, n)) or O(c)
// where c is the size of the character set.