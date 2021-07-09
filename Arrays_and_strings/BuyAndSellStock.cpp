/* BEST TIME TO BUY AND SELL STOCK (ONCE)

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        //Keep track of max profit so far and min elem so far
        int maxprofit= 0;
        int minElem=INT_MAX;

        for(int i=0; i<n ; i++)
        {
            //update min elem if current is smaller
            if(prices[i]< minElem)
                minElem= prices[i];

            //update profit if current - min so far higher
            if(prices[i] - minElem > maxprofit)
                maxprofit = prices[i] - minElem;
        }

        return maxprofit;
    }
};
/*
Test Cases:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/
