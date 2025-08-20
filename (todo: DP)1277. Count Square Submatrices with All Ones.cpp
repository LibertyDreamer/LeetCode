/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

 

Constraints:

    1 <= arr.length <= 300
    1 <= arr[0].length <= 300
    0 <= arr[i][j] <= 1


*/
class Solution {
    int count_ones(vector<vector<int>>& matrix, int i_min, int j_min) {
        int count = 0;
        for (int i = 0; i < matrix.size() - i_min; ++i) {
            for (int j = 0; j < matrix[i].size() - j_min; ++j) {
                count += matrix[i][j];
            }
        }

        return count;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {

        int count = 0;
        int i_minus = 1, j_minus = 1;

        while (matrix.size() - (i_minus - 1) > 0 and
               matrix[0].size() - (j_minus - 1) > 0) {
            count += count_ones(matrix, i_minus - 1, j_minus - 1);

            for (int i = 0; i < matrix.size() - i_minus; ++i) {
                for (int j = 0; j < matrix[0].size() - j_minus; ++j) {
                    if (matrix[i][j] == 1 and matrix[i][j + 1] == 1 and
                        matrix[i + 1][j] == 1 and matrix[i + 1][j + 1] == 1) {
                        matrix[i][j] = 1;
                    } else
                        matrix[i][j] = 0;
                }
            }
            i_minus++;
            j_minus++;
        }

        return count;
    }
};

