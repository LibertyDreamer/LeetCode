/*
Given two integer arrays nums1 and nums2, return an array of their

. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int hash_table[1001] = {};

        for (int i = 0; i < nums1.size(); ++i) {
            hash_table[nums1[i]]++;
        }

        vector<int> solution;
        for (int i = 0; i < nums2.size(); ++i) {
            if (hash_table[nums2[i]] > 0 and hash_table[nums2[i]] != -1) {
                solution.push_back(nums2[i]);
                hash_table[nums2[i]] = -1;
            }
        }

        return solution;
    }
};
