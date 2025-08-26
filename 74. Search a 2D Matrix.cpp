/*

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104


*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); ++i)
        {
            if( (matrix[i][0] <= target) and (matrix[i][matrix[i].size()-1] >= target))
            {
                int left = 0;
                int right = matrix[i].size()-1;
                int middle;

                while(left <= right)
                {
                    middle = (right-left)/2+left;

                    if(matrix[i][middle] == target) return true;
                    else if(matrix[i][middle] < target) left = middle+1;
                    else right = middle -1;
                }
            }
        }

        return false;
    }
};
