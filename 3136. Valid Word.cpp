/*
A word is considered valid if:

    It contains a minimum of 3 characters.
    It contains only digits (0-9), and English letters (uppercase and lowercase).
    It includes at least one vowel.
    It includes at least one consonant.

You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

    'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
    A consonant is an English letter that is not a vowel.

 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.

 

Constraints:

    1 <= word.length <= 20
    word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.



*/


class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        
        int vowels = 0;
        int numbers = 0;

        for(auto& it: word){
            if(it >= 48 and it <= 57){
                numbers++;
            }else {
                it = std::tolower (it);
            if(it >= 97 and it <= 122){
                if(it == 'a') vowels++;
                else if(it == 'e') vowels++;
                else if(it == 'o') vowels++;
                else if(it == 'u') vowels++;
                else if(it == 'i') vowels++;
            }else return false;
            }
        }
        if(vowels < 1) return false;

        return (word.size() - vowels - numbers) > 0;
    }
};
