/*
Problem - Best Time to Buy and Sell Stock with Cooldown
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

//APPROACH - 1 Recursion Take / not Take
//Time Complexity - O(2^n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int n){
        
        if(i >= n) return 0;

        int profit = 0;

        if(buy){

            int take = -prices[i] + solve(prices, i + 1, false, n);

            int skip = solve(prices, i + 1, true, n);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 2, true, n);

            int skip = solve(prices, i + 1, false, n);

            profit = max(take, skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(prices, 0, true, n);
    }
};



//APPROACH - 2 Memoization dp[i][buy]
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int n, vector<vector<int>> &dp){
        
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){

            int take = -prices[i] + solve(prices, i + 1, false, n, dp);

            int skip = solve(prices, i + 1, true, n, dp);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 2, true, n, dp);

            int skip = solve(prices, i + 1, false, n, dp);

            profit = max(take, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, true, n, dp);
    }
};



//APPROACH - 3 Tabulation / Bottom up
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--){

            for(int buy = 0; buy <= 1; buy++){

                dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

                dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            }
        }

        return dp[0][1];
    }
};
