/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.
*/


class Solution {
    struct Data {
        char value;
        char carry;
    };
    Data solving_table[2][2][2] = {
        {{{'0', '0'}, {'1', '0'}}, {{'1', '0'}, {'0', '1'}}},
        {{{'1', '0'}, {'0', '1'}}, {{'0', '1'}, {'1', '1'}}}};

public:
    string addBinary(string a, string b) {
        std::string answer;
        answer.reserve(std::max(a.size(), b.size()) + 1);

        char carry = '0';
        int a_index = a.size();
        int b_index = b.size();

        int a_val;
        int b_val;
        Data d;
        while (a_index > 0 or b_index > 0) {
            a_index--;
            b_index--;

            if (a_index > -1) {
                a_val = a[a_index] - '0';
            } else
                a_val = 0;

            if (b_index > -1) {
                b_val = b[b_index] - '0';
            } else
                b_val = 0;

            d = solving_table[a_val][b_val][carry - '0'];
            carry = d.carry;
            answer.push_back(d.value);
        }
        if (carry == '1')
            answer.push_back('1');

        std::reverse(answer.begin(), answer.end());

        return answer;
    }
};
