/*
Problem - Best Time to Buy and Sell Stock with Transaction Fee
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/

//APPRAOCH - 1 Recursion take / not take
//Time Complexity - O(2^n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int fee, int n){
        
        if(i == n) return 0;

        int profit = 0;

        if(buy){

            int take = -prices[i] + solve(prices, i + 1, false, fee, n);

            int skip = solve(prices, i + 1, true, fee, n);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 1, true, fee, n) - fee;

            int skip = solve(prices, i + 1, false, fee, n);

            profit = max(take, skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        return solve(prices, 0, true, fee, n);
    }
};



//APPROACH - 2 Memoization dp[i][buy]
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int fee, int n, vector<vector<int>> &dp){
        
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){

            int take = -prices[i] + solve(prices, i + 1, false, fee, n, dp);

            int skip = solve(prices, i + 1, true, fee, n, dp);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 1, true, fee, n, dp) - fee;

            int skip = solve(prices, i + 1, false, fee, n, dp);

            profit = max(take, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, true, fee, n, dp);
    }
};



//APPROACH - 3 Tabulation / Bottom Up
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
      
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        int profit = 0;

        for(int i = n - 1; i >= 0; i--){

            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

            dp[i][0] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
        }

        return dp[0][1];
    }
};



//APPROACH - 4 Space Optimised
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        int nextbuy = 0, nextsell = 0, currsell, currbuy;

        for(int i = n - 1; i >= 0; i--){

            currbuy = max(-prices[i] + nextsell, nextbuy);

            currsell = max(prices[i] - fee + nextbuy, nextsell);

            nextsell = currsell;

            nextbuy = currbuy;
        }

        return nextbuy;
    }
};
