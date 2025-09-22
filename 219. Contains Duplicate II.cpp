/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    0 <= k <= 105
*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        int left = 0;
        std::unordered_set<int> s;
        s.insert(nums[left]);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (!s.insert(nums[i]).second) return true;

            if(i - left >= k){ 
                s.erase(nums[left]);
                left++;
            }
        }
       
        return false;
    }
};
