/*
Problem - Best Time to Buy and Sell Stock II
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

//APPRAOCH - 1 Brute Force -> Recursion Take / Not Take method
//Time Complexity - O(2^n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy){
        int n = prices.size();

        if(i == n) return 0;

        int prof = 0;

        if(buy){

            //buy
            int take = solve(prices, i + 1, false) - prices[i];

            //dont buy
            int skip = solve(prices, i + 1, true);

            prof = max(take, skip);
        }

        else{

            //sell
            int take = solve(prices, i + 1, true) + prices[i];

            //dont sell
            int skip = solve(prices, i + 1, false);

            prof = max(take, skip);
        }

        return prof;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(prices, 0, true);
    }
};



//APPRAOCH - 2 Better Way -> Memoize the recursion with dp[idx][buy]
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp){
        int n = prices.size();

        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int prof = 0;

        if(buy){

            //buy
            int take = solve(prices, i + 1, false, dp) - prices[i];

            //dont buy
            int skip = solve(prices, i + 1, true, dp);

            prof = max(take, skip);
        }

        else{

            //sell
            int take = solve(prices, i + 1, true, dp) + prices[i];

            //dont sell
            int skip = solve(prices, i + 1, false, dp);

            prof = max(take, skip);
        }

        return dp[i][buy] = prof;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n , vector<int>(2, -1));

        return solve(prices, 0, true, dp);
    }
};



//APPROACH - 3 Tabulation / Bottom - up Method -> Start filling the dp table from dp[n][0] / dp[n][1] till dp[0][1] / dp[0][0]
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n - 1; i >= 0; i--){

            dp[i][1] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);

            dp[i][0] = max(dp[i + 1][1] + prices[i], dp[i + 1][0]);

        }

        return dp[0][1];

    }
};



//APPROACH - 4 Space Optimisation -> Instead of using vectors, use variable and we only need to the next one to find the current state
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int nextSell = 0, nextBuy = 0, currBuy, currSell;

        for(int i = n - 1; i >= 0; i--){

            //buy state
            currBuy = max(-prices[i] + nextSell, nextBuy);

            //sell state
            currSell = max(prices[i] + nextBuy, nextSell);

            nextSell = currSell;
            nextBuy = currBuy;

        }

        return nextBuy;
    }
};
