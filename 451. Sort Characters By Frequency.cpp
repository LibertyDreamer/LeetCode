/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

 

Constraints:

    1 <= s.length <= 5 * 105
    s consists of uppercase and lowercase English letters and digits.

  */

class Solution {
public:
    string frequencySort(string s) {
        int hash[123] = {};
        int max = 0;
        for(char& c : s){
            hash[c]++;
            max = std::max(max, (int)hash[c]);
        }
        std::vector<std::vector<char>> v(max);


        for(char i = 'a'; i <= 'z'; ++i){
            if(hash[i] != 0)
                v[hash[i]-1].push_back(i);
        }
        for(char i = 'A'; i <= 'Z'; ++i){
            if(hash[i] != 0)
                v[hash[i]-1].push_back(i);
        }
        for(char i = '0'; i <= '9'; ++i){
            if(hash[i] != 0)
                v[hash[i]-1].push_back(i);
        }

        int string_index = 0;
        for(int i = max-1; i > -1; --i){
            for(int j = 0; j < v[i].size(); ++j)
                for(int k = 0; k < i+1; ++k)
                s[string_index++] = v[i][j];
        }


        return s;


    }
};
