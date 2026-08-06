/*
Problem - Best Time to Buy and Sell Stock IV
LeetCode - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

//APPRAOCH - 1 Recursion take / not take
//Time Complexity - O(2^n)
//Space Complexity - O(n)

class Solution {
public:

    int solve(vector<int>& prices, int i, bool buy, int trans, int n){
        if(i == n) return 0;

        if(trans == 0) return 0;

        int profit = 0;

        if(buy){
            
            int take = -prices[i] + solve(prices, i + 1, false, trans, n);

            int skip = solve(prices, i + 1, true, trans, n);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 1, true, trans - 1, n);

            int skip = solve(prices, i + 1, false, trans, n);

            profit = max(take, skip);
        }

        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        return solve(prices, 0, true, k, n, dp);
    }
};



//APPROACH - 2 Memoization dp[i][buy][trans]
//Time Complexity - O(n * k)
//Space Complexity - O(n * k)

class Solution {
public:

    int solve(vector<int>& prices, int i, bool buy, int trans, int n, vector<vector<vector<int>>> &dp){
        if(i == n) return 0;

        if(trans == 0) return 0;

        if(dp[i][buy][trans] != -1) return dp[i][buy][trans];

        int profit = 0;

        if(buy){
            
            int take = -prices[i] + solve(prices, i + 1, false, trans, n, dp);

            int skip = solve(prices, i + 1, true, trans, n, dp);

            profit = max(take, skip);
        }

        else{

            int take = prices[i] + solve(prices, i + 1, true, trans - 1, n, dp);

            int skip = solve(prices, i + 1, false, trans, n, dp);

            profit = max(take, skip);
        }

        return dp[i][buy][trans] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return solve(prices, 0, true, k, n, dp);
    }
};



//APPRAOCH - 3 Tabulation / Bottom up
//Time Complexity - O(n * k)
//Space Complexity - O(n * k)

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
      
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for(int i = n - 1; i >= 0; i--){
            
            for(int buy = 0; buy <= 1; buy++){

                for(int trans = 1; trans <= k; trans++){

                    if(buy){

                        dp[i][1][trans] = max(-prices[i] + dp[i + 1][0][trans], dp[i + 1][1][trans]);

                    }

                    else{

                        dp[i][0][trans] = max(prices[i] + dp[i + 1][1][trans - 1], dp[i + 1][0][trans]);

                    }
                }
            }
        }

        return dp[0][1][k];
    }
};



//APPRAOCH - 4 Space Optimised
//Time Complexity - O(n*k)
//Space Complexity - O(k)

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            
            for(int buy = 0; buy <= 1; buy++){

                for(int trans = 1; trans <= k; trans++){

                    if(buy){

                        curr[1][trans] = max(-prices[i] + ahead[0][trans], ahead[1][trans]);

                    }

                    else{

                        curr[0][trans] = max(prices[i] + ahead[1][trans - 1], ahead[0][trans]);

                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][k];
    }
};
