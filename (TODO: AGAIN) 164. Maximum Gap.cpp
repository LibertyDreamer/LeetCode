/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

 

Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 109

*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        {
            std::vector<int> buckets[65536];

            for (int i = 0; i < nums.size(); ++i) {
                buckets[nums[i] & 0b1111111111111111].push_back(nums[i]);
                //std::cout << "bucketN:" << (nums[i] & 0b1111111111111111)
                //          << " eq " << nums[i] << std::endl;
            }

            int nums_index = 0;
            for (auto& it : buckets) {
                for (int i = 0; i < it.size(); ++i) {
                    nums[nums_index++] = it[i];
                    //std::cout << it[i] << " ";
                }

                
            }
        }

        {
            std::vector<int> buckets[65536];

            for (int i = 0; i < nums.size(); ++i) {
                buckets[(nums[i] & 0b11111111111111110000000000000000) >> 16].push_back(nums[i]);
                //std::cout << "bucketN:" << (nums[i] & 0b11111111111111110000000000000000)
                //          << " eq " << nums[i] << std::endl;
            }

            int nums_index = 0;
            for (auto& it : buckets) {
                for (int i = 0; i < it.size(); ++i) {
                    nums[nums_index++] = it[i];
                    //std::cout << it[i] << " ";
                }

                
            }
        }



        int distance = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            distance = std::max(distance, nums[i + 1] - nums[i]);

            // std::cout << distance << std::endl;
        }

        return distance;
    }
};
