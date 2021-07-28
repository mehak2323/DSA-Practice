/** GUESS NUMBER HIGHER OR LOWER

We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked.

Link: https://leetcode.com/problems/guess-number-higher-or-lower/
*/

/*
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        //N ranges to 2^31-1 so high+mid can go out of range, which makes
        //mid a negative value and an endless loop, so using unsigned
        //Or it can be fixed by using int mid = (left+(right-left)/2);
        unsigned int high=n, low=1, mid, action;

        //Implement Binary Search on result from API between 1 to n
        while(low<= high)
        {
            mid = (high + low)/2;
            action = guess(mid);

            if(action == -1)
                high = mid-1;
            else if(action == 1)
                low = mid+1;
            else
                return mid;
        }
        //Not needed but if elem not found
        return -1;
    }

    //Note: Another method is either loop for 1 to n to see which is mid,
    //OR using ternary search, which is faster than binary but,
    /*Ternary Search does more comparisons than Binary Search in the worst case. */
};

/**
Test Cases:
    Input: n = 10, pick = 6
    Output: 6

    Input: n = 1, pick = 1
    Output: 1

    Input: n = 2, pick = 1
    Output: 1

    Input: n = 2, pick = 2
    Output: 2

Time Complexity: O(log2 n)
Space Complexity: O(1)
*/
