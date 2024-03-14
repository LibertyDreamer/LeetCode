/* 
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
  */

class Solution {
    void word_to_mask(string& word, vector<uint32_t>& masks)
    {
        uint32_t mask = 0;
        for (int i = 0; i < word.size(); ++i) 
        {
            const int& word_i = word[i] - 97;
            if(mask & (1 << word_i))
            {
                    return;
            }
            mask |= (1 << word_i);
        }
        masks.push_back(mask);
    }
public:
    int maxLength(vector<string>& arr) {

        //vector<uint32_t> masks;
        //for(int i = 0; i < arr.size(); ++i)
        //{
        //    word_to_mask(arr[i], masks);
        //}

        
        //return 0;


        

    vector<unordered_set<char>> dp = {unordered_set<char>()};

    int max_length = 0;

    for (const string& s : arr) {
        unordered_set<char> unique_chars(s.begin(), s.end());

        if (unique_chars.size() != s.length()) {
            continue;  // Skip strings with duplicate characters
        }

        vector<unordered_set<char>> new_subsequences;

        for (const unordered_set<char>& subseq : dp) {
            unordered_set<char> new_subseq = subseq;
            new_subseq.insert(unique_chars.begin(), unique_chars.end());

            if (new_subseq.size() == subseq.size() + unique_chars.size()) {
                new_subsequences.push_back(new_subseq);
                max_length = max(max_length, static_cast<int>(new_subseq.size()));
            }
        }

        dp.insert(dp.end(), new_subsequences.begin(), new_subsequences.end());
    }

    return max_length;

       
    }
};
