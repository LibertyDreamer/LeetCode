/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

 

Follow up:

    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<int> down_moves;

        for (int m = 0; m < matrix.size(); ++m) {
            for (int n = 0; n < matrix[m].size(); ++n) {

                if (matrix[m][n] == 0) {
                    down_moves.push_back(n);
                    int pos = 0;
                    while(pos != n){
                        matrix[m][pos] = 0;
                        pos++;
                    }
                    for (; n < matrix[m].size(); ++n) {
                        if (matrix[m][n] == 0)
                            down_moves.push_back(n);
                        matrix[m][n] = 0;
                    }
                    break;
                }
            }
        }

        for (int m = 0; m < matrix.size(); ++m) {
            for (auto it : down_moves) {
                matrix[m][it] = 0;
            }
        }
    }
};

