/* STRING PALINDROME OR NOT

Given a string S, check if it is palindrome or not.
Palindrome is a string read same when reversed.

Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
*/

class Solution{
public:

	int isPlaindrome(string S)
	{
	    //Compare elements at ends , if not equal not palindrome
	    for(int i=0, j=S.length()-1; i<=j; i++, j--)
	    {
	        if(S[i]!=S[j])
	            return 0;
	    }
	    //If all equal, palindrome
	    return 1;
	}

};

/*
Test Cases:
    Input: S = "abba"
    Output: 1
    Explanation: S is a palindrome

    Input: S = "abc"
    Output: 0
    Explanation: S is not a palindrome

Time Complexity: O(n)
Space Complexity: O(1)
*/
