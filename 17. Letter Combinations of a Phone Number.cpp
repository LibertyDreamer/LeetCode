/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

*/


class Solution {
    vector<string> solution;
    std::vector<std::string> number[10] = {{""},
                                           {""},
                                           {"a", "b", "c"},
                                           {"d", "e", "f"},
                                           {"g", "h", "i"},
                                           {"j", "k", "l"},
                                           {"m", "n", "o"},
                                           {"p", "q", "r", "s"},
                                           {"t", "u", "v"},
                                           {"w", "x", "y", "z"}};
    vector<string> one_number(const std::string& digits) {
        for (int i = 0; i < number[digits[0] - '0'].size(); ++i) 
            solution.push_back(std::string(number[digits[0] - '0'][i]));
        
        return solution;
    }

    vector<string> two_numbers(const std::string& digits) {
        for (int i = 0; i < number[digits[0] - '0'].size(); ++i) 
            for (int j = 0; j < number[digits[1] - '0'].size(); ++j)
                solution.push_back(std::string(number[digits[0] - '0'][i]) +
                                   std::string(number[digits[1] - '0'][j]));
        
        return solution;
    }
    vector<string> three_numbers(const std::string& digits) {
        for (int i = 0; i < number[digits[0] - '0'].size(); ++i)
            for (int j = 0; j < number[digits[1] - '0'].size(); ++j)
                for (int k = 0; k < number[digits[2] - '0'].size(); ++k)
                    solution.push_back(std::string(number[digits[0] - '0'][i]) +
                                       std::string(number[digits[1] - '0'][j]) +
                                       std::string(number[digits[2] - '0'][k]));

        return solution;
    }
    vector<string> four_numbers(const std::string& digits) {
        for (int i = 0; i < number[digits[0] - '0'].size(); ++i) 
            for (int j = 0; j < number[digits[1] - '0'].size(); ++j)
                for (int k = 0; k < number[digits[2] - '0'].size(); ++k)
                for (int q = 0; q < number[digits[3] - '0'].size(); ++q)
                    solution.push_back(std::string(number[digits[0] - '0'][i]) +
                                       std::string(number[digits[1] - '0'][j]) +
                                       std::string(number[digits[2] - '0'][k]) +
                                       std::string(number[digits[3] - '0'][q]));
        
        return solution;
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return vector<string>();
        else if (digits.size() == 1)
            return one_number(digits);
        else if (digits.size() == 2)
            return two_numbers(digits);
        else if (digits.size() == 3)
            return three_numbers(digits);
        return four_numbers(digits);
    }
};
