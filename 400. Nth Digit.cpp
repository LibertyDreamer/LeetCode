/*
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

 

Example 1:

Input: n = 3
Output: 3

Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

 

Constraints:

    1 <= n <= 231 - 1


*/


class Solution {
    constexpr static int border[9] = {9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, INT_MAX};
public:
    int findNthDigit(int n) {
        if (n < 10) return n;

        int i = 1;
        while(n > border[i])
            i++;
        
        return std::to_string((n - (border[i-1]+1)) / (i+1) + std::pow(10,i))[(n-(border[i-1]+1)) % (i+1)] - '0';
        return 0;
    }
};
