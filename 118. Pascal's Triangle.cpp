/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    1 <= numRows <= 30
*/

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        std::vector<std::vector<int>> triangle = {{1}, {1, 1}};

        for (int i = 2; i < numRows; ++i) {
            triangle.push_back(std::vector<int>(triangle[i-1].size() + 1, 0));
            
            const std::vector<int>& prev_row = triangle[i-1];

            triangle[i][0] = prev_row[0];

            for (int j = 1; j < triangle[i].size()-1; ++j) {
                triangle[i][j] = prev_row[j] + prev_row[j - 1];
            }

            triangle[i][triangle.back().size()-1] = prev_row[prev_row.size() - 1];
        }

        return triangle;
    }
};
