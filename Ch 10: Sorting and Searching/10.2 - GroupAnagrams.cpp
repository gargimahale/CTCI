#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string countingSort(string& temp) {
        vector<int> cnt(28);
        for (char ch : temp) cnt[ch - 'a']++;

        string ans = "";
        for (int i = 0; i < 28; ++i) {
            ans += string(cnt[i], i + 'a');
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; ++i) {
            string temp = strs[i];
            temp = countingSort(temp);
            mp[temp].push_back(strs[i]);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};

// TC: O(n*k)
// SC: O(n*k)
// Where n is the size of strs and k is the length of the longest string in strs