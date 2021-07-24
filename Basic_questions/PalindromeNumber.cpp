/* PALINDROME NUMBER

Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is palindrome while 123 is not.

Link: https://leetcode.com/problems/palindrome-number/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        //Negative not palindrome
        if(x<0)
            return 0;

        int temp = x;
        //Long to avoid stack overflow as big int
        //value reversed can be bigger than int
        long int rev=0;
        //Get last digit and make rev number
        while(temp>0)
        {
            rev = (rev*10) + (temp%10);
            temp = temp/10;
        }
        //see if rev number is equal to original
        if(rev==x)
            return 1;

        return 0;
    }
};
/*
Test Cases:
    Input: x = 121
    Output: true

    Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

    Input: x = 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

    Input: x = -101
    Output: false

Time Complexity: O(log 10 n)
Space Complexity: O(1)
*/
