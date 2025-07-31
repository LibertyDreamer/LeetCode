/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

 

Constraints:

    0 <= x <= 2^31 - 1

*/
class Solution {
public:
    int mySqrt(int x) {
        if(x > 2147395600) return 23170*2;
        int size = 23170;
        int i = 23170;

        while (size > 0) {
            unsigned long long square = i * i;
            if (square == x) {
                return i;
            } else if (square > x) {
                i -= size;
            } else {
                i += size;
            }
            size /= 2;
        }

        while (i * i > x) i--;
        while (((long long)i + 1) * ((long long)i + 1) < x) i++;
        return i;
    }
};

