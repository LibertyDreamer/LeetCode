/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x_size = matrix[0].size();
        int y_size = matrix.size();

        int x = -1, y = 0;

        std::vector<int> arr;
        arr.reserve(x_size * y_size);
        while(x_size != 0 and y_size!=0)
        {
            for(int i = 0; i < x_size; ++i){
                x++;
                arr.push_back(matrix[y][x]);
                
            }
            y_size--;
            for(int i = 0; i < y_size; ++i){
                y++;
                arr.push_back(matrix[y][x]);
                
            }
            x_size--;

            if (x_size == 0 or y_size == 0) break;

            for(int i = 0; i < x_size; ++i){
                x--;
                arr.push_back(matrix[y][x]);
                
            }
            y_size--;
            for(int i = 0; i < y_size; ++i){
                y--;
                arr.push_back(matrix[y][x]);
                
            }
            x_size--;
        }

        return arr;
    }
};
