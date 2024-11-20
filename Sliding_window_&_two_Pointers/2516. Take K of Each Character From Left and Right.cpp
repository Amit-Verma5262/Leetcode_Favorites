#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        map<char, int> totalCount;

        for (char ch : s) {
            totalCount[ch]++;
        }

        if (totalCount['a'] < k || totalCount['b'] < k ||
         totalCount['c'] < k) {
            return -1;
        }

        int maxKeep = 0;
        map<char, int> windowCount;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            windowCount[s[r]]++;

            while (windowCount['a'] > totalCount['a'] - k ||
                   windowCount['b'] > totalCount['b'] - k ||
                   windowCount['c'] > totalCount['c'] - k) {
                windowCount[s[l]]--;
                l++;
            }

            maxKeep = max(maxKeep, r - l + 1);
        }

        return n - maxKeep;
    }
};
