/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7

Example 2:

Input: s = " 3/2 "
Output: 1

Example 3:

Input: s = " 3+5 / 2 "
Output: 5

 

Constraints:

    1 <= s.length <= 3 * 105
    s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    s represents a valid expression.
    All the integers in the expression are non-negative integers in the range [0, 231 - 1].
    The answer is guaranteed to fit in a 32-bit integer.
*/


class Solution {
    int get_number(const std::string& s, int& i) {
        int number = 0;
        while (std::isdigit(s[i])) {
            number = s[i] - '0' + number * 10;
            i++;
        }
        i--;
        return number;
    }

    int priority(char& c) {
        if (c == '*' or c == '/')
            return 1;
        if (c == '+' or c == '-')
            return 0;
        if (c == 'n')
            return -1;
        throw("WTF");
    }

    int compute(const char& op, const int& operand1, const int& operand2) {
        if (op == '*')
            return operand1 * operand2;
        else if (op == '/')
            return operand1 / operand2;
        else if (op == '+')
            return operand1 + operand2;
        else if (op == '-')
            return operand1 - operand2;

        throw("WTF");
    }

public:
    int calculate(std::string s) {

        std::stack<char> holding;
        std::stack<int> solving;

        for (int i = 0; i < s.size(); ++i) {
            if (std::isdigit(s[i])) {
                solving.push(get_number(s, i));
            } else if (s[i] == ' ')
                continue;

            else {
                while (!holding.empty() and priority(holding.top()) >= priority(s[i])) {
                        char op = holding.top();
                        holding.pop();
                        int op2 = solving.top();
                        solving.pop();
                        int op1 = solving.top();
                        solving.pop();
                        solving.push(compute(op, op1, op2));
                }
                holding.push(s[i]);
            }
        }

        while (!holding.empty()) {
            char op = holding.top();
            holding.pop();
            int op2 = solving.top();
            solving.pop();
            int op1 = solving.top();
            solving.pop();
            solving.push(compute(op, op1, op2));
        }
        return solving.top();
    }
};

