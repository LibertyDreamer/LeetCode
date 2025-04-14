/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        int bestStart = 0, bestLength = 1;
        vector<int> positions[128];
        for (int i = 0; i < n; ++i)
            positions[s[i]].push_back(i);
        for (int ch = 0; ch < 128; ++ch) {
            vector<int>& indices = positions[ch];
            int sz = indices.size();
            if(sz < 2)
                continue;
            for (int j = sz - 1; j >= 0; --j) {
                if (indices[j] - indices[0] + 1 <= bestLength)
                    break;
                for (int i = 0; i < j; ++i) {
                    int startIndex = indices[i];
                    int endIndex = indices[j];
                    int candidateLen = endIndex - startIndex + 1;
                    if(candidateLen <= bestLength)
                        continue;
                    if(isPalindrome(s, startIndex, endIndex)) {
                        bestLength = candidateLen;
                        bestStart = startIndex;
                        break;
                    }
                }
            }
        }
        return s.substr(bestStart, bestLength);
    }
    
private:
    bool isPalindrome(const string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
