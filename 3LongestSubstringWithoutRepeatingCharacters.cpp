/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
  */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        char hash[256] = {};

        int p1 = 0;
        int max = 1;
        hash[s[p1]] ++;
        int solution = 1;

        for(int p2 = 1; p2 < s.size(); ++p2){
            hash[s[p2]] ++;
            max++;
            while(hash[s[p2]] > 1){
                hash[s[p1++]] --;
                max -= 1;
            }
            if(solution < max) solution = max;
        }
        
    return solution;
    }
};
