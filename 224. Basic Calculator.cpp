/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

 

Constraints:

    1 <= s.length <= 3 * 105
    s consists of digits, '+', '-', '(', ')', and ' '.
    s represents a valid expression.
    '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
    '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
    There will be no two consecutive operators in the input.
    Every number and running calculation will fit in a signed 32-bit integer.
*/

class Solution {
    enum Token {
        UNARY_MINUS,
        BINARY_MINUS,
        BINARY_PLUS,
        PARENTHESIS_OPEN,
        PARENTHESIS_CLOSED,
        NUMBER,
        NOTHING
    };

    int priority(Token tok) {
        if (tok == NOTHING)
            return -1;
        else if (tok == UNARY_MINUS)
            return 2;
        else if (tok == BINARY_MINUS)
            return 1;
        else if (tok == BINARY_PLUS)
            return 1;
        else if (tok == PARENTHESIS_OPEN)
            return 0;

        return -1;
    }

    std::vector<int> numbers;
    std::vector<Token> tokens;

    std::vector<Token> tokenize(const std::string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                tokens.push_back(PARENTHESIS_OPEN);
            else if (s[i] == ')')
                tokens.push_back(PARENTHESIS_CLOSED);
            else if (isdigit(s[i])) {
                int number = 0;
                number = s[i] - '0' + number * 10;
                while ((i + 1 < s.size()) and isdigit(s[i + 1])) {
                    i++;
                    number = s[i] - '0' + number * 10;
                }
                numbers.push_back(number);
                tokens.push_back(NUMBER);
            } else if (s[i] == '+')
                tokens.push_back(BINARY_PLUS);
            else if (s[i] == '-') {
                
                    if (i - 1 >= 0 and s[i - 1] == ')')
                        tokens.push_back(BINARY_MINUS);
                    else if (i - 1 >= 0 and isdigit(s[i - 1]))
                        tokens.push_back(BINARY_MINUS);
                 else
                    tokens.push_back(UNARY_MINUS);
            }
        }
        return tokens;
    }

    std::vector<Token> result;

    int priority_modifire = 0;
    void to_polish() {
        std::stack<Token> st;

        st.push(NOTHING);
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == NUMBER)
                result.push_back(NUMBER);
            else if (tokens[i] == PARENTHESIS_OPEN) {
                st.push(PARENTHESIS_OPEN);
            } else if (tokens[i] == PARENTHESIS_CLOSED) {
                while (st.top() != PARENTHESIS_OPEN) {
                    Token t = st.top();
                    result.push_back(t);
                    st.pop();
                }
                st.pop();
            } else if (priority(tokens[i]) > priority(st.top())) {
                st.push(tokens[i]);
            } else if (priority(tokens[i])) {
                while (st.size() != 1 and st.top() != PARENTHESIS_OPEN) {
                    result.push_back(st.top());
                    st.pop();
                }
                st.push(tokens[i]);
            }
        }
        while (st.size() != 1) {
            result.push_back(st.top());
            st.pop();
        }
    }

    std::string show_polish() {
        std::string polish;
        int numbers_index = 0;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] == NUMBER) {
                polish += std::to_string(numbers[numbers_index]) + " ";
                numbers_index++;
            } else if (result[i] == UNARY_MINUS) {
                polish += "_ ";
            } else if (result[i] == BINARY_MINUS) {
                polish += "- ";
            } else if (result[i] == BINARY_PLUS) {
                polish += "+ ";
            }
        }

        return polish;
    }

    int solve() {
        int number_index = 0;
        std::stack<int> st;
        for (int i = 0; i < result.size(); ++i) {
            Token t = result[i];
            if (t == NUMBER)
                st.push(numbers[number_index++]);
            else if (t == UNARY_MINUS) {
                int op1 = st.top() * -1;
                st.pop();
                st.push(op1);
            } else if (t == BINARY_MINUS) {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 - op1);
            } else if (t == BINARY_PLUS) {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 + op1);
            }
        }
        return st.top();
    }

public:
    int calculate(std::string s) {
        std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
        s.erase(end_pos, s.end());
        tokenize(s);
        to_polish();
        std::cout << show_polish() << std::endl;
        return solve();
    }
};
