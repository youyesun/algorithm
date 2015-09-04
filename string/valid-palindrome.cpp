/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !ifAlph(s[left]))
                left ++;
            while(left < right && !ifAlph(s[right]))
                right --;
            if((left<right)&&(s[left] != s[right]) && (abs(s[left] - s[right]) != 'a' - 'A'))
                return false;
            left ++;
            right --;
        }
        return true;
    }
    
    bool ifAlph(char ch){
        if(((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >='0')&&(ch<='9')))
            return true;
        return false;
    }
};
