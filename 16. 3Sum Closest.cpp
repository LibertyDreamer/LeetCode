/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

 

Constraints:

    3 <= nums.length <= 500
    -1000 <= nums[i] <= 1000
    -104 <= target <= 104

*/


class Solution {
    void recalc_closer_number(int& closer_for_now, const int& sum, const int& target){
        if(std::abs(target - sum) < std::abs(target - closer_for_now)) closer_for_now = sum;
    }
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closer_number = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); ++i){
            int p1 = 0, p2 = nums.size()-1;
            int sum;
            while(p1 != p2)
            {
                if(p1 == i){p1++; continue;}
                else if(p2 == i){p2--; continue;}

                sum = nums[i] + nums[p1] + nums[p2];

                if(sum > target) p2--;
                else if(sum < target) p1++;
                else return sum;

                recalc_closer_number(closer_number, sum, target);
            }
        }

        return closer_number;
    }
};
