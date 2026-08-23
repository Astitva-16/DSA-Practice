/*518. Coin Change II
LeetCode link -> https://leetcode.com/problems/coin-change-ii/
*/

// RECURSION ->
/*
coinChange(n, amount) → number of ways to make amount using the first n coins.

Base cases:

if(n == 0) return 0;
if(amount == 0) return 1;
No coins → 0 ways.
Amount 0 → 1 way: choose nothing.

If current coin is larger than amount, we cannot take it:

if(coins[n-1] > amount)
    return coinChange(coins, n-1, amount);
Otherwise, we have 2 choices:

Take coin: n stays same because coins can be reused.

coinChange(coins, n, amount-coins[n-1])

Don't take coin: move to previous coin.

coinChange(coins, n-1, amount)

Add both possibilities:

return take + not_take;

change() starts with all coins:

coinChange(coins, n, amount);
*/
class Solution {
public:
    
    int coinChange(vector<int>& coins, int n, int amount){

        if(n==0)  return 0;

        if(amount == 0) return 1;

        if(coins[n-1] > amount)
        {
            return coinChange(coins, n-1, amount);
        }
        return coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
    }
    
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        if(amount == 0) {
            return 1;
        }
        
        return coinChange(coins, n, amount);
        
    }
};




// MEMOISATION ->
/*
State:

dp[n][amount]

→ number of ways to make amount using the first n coins.

Base cases:

if(n == 0) return 0;
if(amount == 0) return 1;

amount = 0 has exactly 1 way: choose nothing.

Memoization check should be:

if(dp[n][amount] != -1)
    return dp[n][amount];

If coin is too large:

if(coins[n-1] > amount)
    return coinChange(coins, n-1, amount, dp);
Otherwise, 2 choices:

Take: n stays same because coin can be reused.

coinChange(coins, n, amount-coins[n-1], dp)

Not Take: move to previous coin.

coinChange(coins, n-1, amount, dp)

Add both ways and store:

dp[n][amount] = take + not_take;
*/
class Solution {
public:
    
    int coinChange(vector<int>& coins, int n, int amount, vector<vector<int>>& dp){

        if(n==0)  return 0;

        if(amount == 0) return 1;

        if(dp[n][amount] != -1) dp[n][amount];

        if(coins[n-1] > amount){ 

            return coinChange(coins, n-1, amount, dp);
        }
        return dp[n][amount] = coinChange(coins, n, amount-coins[n-1], dp) + coinChange(coins, n-1, amount, dp);
    }
    
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        if(amount == 0) {
            return 1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return coinChange(coins, n, amount, dp);
        
    }
};




// TABULATION ->
/*
State:
dp[i][j]
→ number of ways to make amount j using first i coins.

Base case:
dp[i][0] = 1;
Amount 0 has exactly one way: choose nothing.

Not Take:
notTake = dp[i - 1][j];
Don't use current coin.

Take:
take = dp[i][j - coins[i - 1]];
i remains same because coins can be used unlimited times.

Combine:
ways = take + notTake;

You're using long long internally to avoid overflow during addition, then capping:
if(ways > INT_MAX)
    dp[i][j] = INT_MAX;
So the DP value never exceeds the int range.

Final answer:
return dp[n][amount];
*/
class Solution {
public:
    
    typedef long long ll;

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<ll>> dp(n + 1, vector<ll>(amount + 1, 0));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= amount; j++) {

                ll notTake = dp[i - 1][j];

                ll take = 0;

                if(coins[i - 1] <= j) {

                    take = dp[i][j - coins[i - 1]];
                }

                ll ways = take + notTake;

                if(ways > INT_MAX) dp[i][j] = INT_MAX;

                else dp[i][j] = ways;
            }
        }

        return dp[n][amount];
        
    }
};
