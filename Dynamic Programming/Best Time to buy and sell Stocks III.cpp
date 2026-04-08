/*
Problem - Best Time to buy and sell Stocks
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

//APPROACH - 1 Brute Force -> Recursion take / not take, put a contraint that number of transactions can not be more than 2
//Time Complexity - O(2^n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int trans){

        if(i == prices.size()) return 0;

        if(trans == 0) return 0;

        int profit = 0;

        if(buy){
            int take = -prices[i] + solve(prices, i + 1, false, trans);

            int skip = solve(prices, i + 1, true, trans);

            profit = max(take, skip);
        }

        else{
            int take = prices[i] + solve(prices, i + 1, true, trans - 1);

            int skip = solve(prices, i + 1, false, trans);

            profit = max(take, skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return solve(prices, 0, true, 2);
    }
};



//APPROACH - 2 Better Way -> Memoization dp[i][buy][trans]
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int> &prices, int i, bool buy, int trans, vector<vector<vector<int>>> &dp){

        if(i == prices.size()) return 0;

        if(trans == 0) return 0;

        if(dp[i][buy][trans] != -1) return dp[i][buy][trans];

        int profit = 0;

        if(buy){
            int take = -prices[i] + solve(prices, i + 1, false, trans, dp);

            int skip = solve(prices, i + 1, true, trans, dp);

            profit = max(take, skip);
        }

        else{
            int take = prices[i] + solve(prices, i + 1, true, trans - 1, dp);

            int skip = solve(prices, i + 1, false, trans, dp);

            profit = max(take, skip);
        }

        return dp[i][buy][trans] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(prices, 0, true, 2, dp);
    }
};



//APPROACH - 3 Tabulation / Bottom-up
//Time Complexity - O(n)
//Space Complexity - O(n)

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
      
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n - 1; i >= 0; i--){

            for(int buy = 0; buy <= 1; buy++){
                
                for(int trans = 1; trans <= 2; trans++){

                    if(buy){
                        dp[i][1][trans] = max(-prices[i] + dp[i + 1][0][trans], dp[i + 1][1][trans]);
                    }

                    else{
                        dp[i][0][trans] = max(prices[i] + dp[i + 1][1][trans - 1], dp[i + 1][0][trans]);
                    }

                }
            }
        }

        return dp[0][1][2];
    }
};



//APPROACH - 4 Space Optimisation
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
  
        int buy1 = INT_MIN , sell1 = 0, buy2 = INT_MIN, sell2 = 0;

        for(auto price : prices){

            buy1 = max(buy1, -price); //profit after 1st buy

            sell1 = max(sell1, buy1 + price); //profit after 1st sell

            buy2 = max(buy2, sell1 - price); //profit after 2nd buy

            sell2 = max(sell2, buy2 + price); //profit after 2nd sell
        }

        return sell2;
    }
};
