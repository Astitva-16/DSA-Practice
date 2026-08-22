/*322. Coin Change
LeetCode link -> https://leetcode.com/problems/coin-change/
*/

// RECUSRION ->
/*
solve(amount) → minimum number of coins needed to make the given amount.

Base case:

if(amount == 0) return 0;

Amount 0 requires 0 coins.

Try every coin:

for(auto coin : coins)

If coin <= amount, take the coin and solve the remaining amount:

res = solve(coins, amount - coin, n);

If the remaining amount is possible, add the current coin:

ans = min(ans, res + 1);

INT_MAX means amount cannot be formed. Finally:

if(ans == INT_MAX) return -1;
*/
class Solution {
public:

    int solve(vector<int>& coins, int amount, int n){

        if(amount == 0) return 0;

        int ans = INT_MAX;

        for(auto coin : coins){

            if(coin <= amount){
                int res = solve(coins, amount - coin, n);

                if(res != INT_MAX){
                    ans = min(ans, res + 1);
                }
            }
        }

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        int ans = solve(coins, amount, n);

        if(ans == INT_MAX) return -1;

        return ans;
    }
};




// MEMOIZATION ->
/*
State: dp[amount] = minimum coins required to make this amount.

Base case:

if(amount == 0) return 0;

If already calculated:

if(dp[amount] != -1) return dp[amount];

Try every coin. If coin <= amount, solve:

solve(amount - coin)

Add the current coin:

ans = min(ans, res + 1);

Store the answer:

dp[amount] = ans;
If final answer is INT_MAX, amount cannot be formed → return -1.
*/
class Solution {
public:

    int solve(vector<int>& coins, int amount, int n, vector<int>& dp){

        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for(auto coin : coins){

            if(coin <= amount){
                int res = solve(coins, amount - coin, n, dp);

                if(res != INT_MAX){
                    ans = min(ans, res + 1);
                }
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, n, dp);

        if(ans == INT_MAX) return -1;

        return ans;
    }
};




// TABULATION ->
/*
State: dp[i] = minimum number of coins needed to make amount i.

Initialization:

vector<int> dp(amount + 1, INT_MAX);
dp[0] = 0;

Amount 0 needs 0 coins; everything else is initially impossible.

Build the table from amount 1 → amount:

for(int i = 1; i <= amount; i++)

For every amount, try every coin:

for(auto coin : coins)

If the coin can be used:

if(coin <= i)

then remaining amount is:

i - coin

If remaining amount is possible, update:

dp[i] = min(dp[i], 1 + dp[i - coin]);

Finally:

dp[amount] == INT_MAX → -1

otherwise return dp[amount].
*/
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++){

            for(auto coin : coins){

                if(coin <= i){

                    if(dp[i - coin] != INT_MAX){
                        dp[i] = min(dp[i], 1 + dp[i - coin]);
                    }
                }
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
