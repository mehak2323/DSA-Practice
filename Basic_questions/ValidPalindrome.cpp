/** VALID PALINDROME

Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Link: https://leetcode.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();
        char temp;

        for(int i=0, j=n-1 ; i<=j; )
        {
            //If left pointer not alphanumeric
            if(!isalnum(s[i]))
            {
                i++;
                continue;
            }
            //If right pointer not alphanumeric
            if(!isalnum(s[j]))
            {
                j--;
                continue;
            }

            //If left and right pointers not equal in lower or upper case
            //Not a palindrome
            temp = s[i];
            if( !(toupper(temp) == s[j] || tolower(temp)== s[j]))
            {
                return false;
            }

            //Only change pointers if first two conditions not executed
            i++; j--;
        }

        //All equal, palindrome
        return true;
    }

    //Note: Other functions- isalpha() for alphabet and isnum() for number.
};

/**
Test Cases:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

Time Complexity: O(n)
Space Complexity: O(1)
*/
