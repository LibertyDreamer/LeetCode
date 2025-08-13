/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you minimize the total number of operations done?

*/



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p2 = 0;

        for (int p1 = 0; p1 < nums.size(); ++p1)
            if (nums[p1] == 0) {
                if(p2 < p1) p2 = p1;
                while (nums[p2] == 0) {
                    p2++;
                    if (p2 == nums.size())
                        return;
                };
                nums[p1] = nums[p2];
                nums[p2] = 0;
            }
    }
};
