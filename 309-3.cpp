/*
309. Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/

/*
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        vector<int> local(n, 0);
        vector<int> global(n, 0);
        
        local[1] = prices[1] - prices[0];
        global[1] = max(global[0], local[1]);
        local[2] = prices[2] - min(prices[0], prices[1]);
        global[2] = max(global[1], local[2]);
        
        for(int i = 3; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            local[i] = max(local[i - 1], global[i - 3]) + diff;
            global[i] = max(global[i - 1], local[i]);
        }
        
        return global[n - 1];
    }
};
