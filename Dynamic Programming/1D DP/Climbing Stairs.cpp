/*70. Climbing Stairs
LeetCode link -> https://leetcode.com/problems/climbing-stairs
*/

// RECURSION ->
/*
Define climbStairs(n) as the number of ways to reach the nth stair.
Base cases:
  If n < 0, return 0 (invalid path).
  If n == 0, return 1 (one valid way to reach the top).
From the current stair, there are two choices:
  Take 1 step → climbStairs(n - 1)
  Take 2 steps → climbStairs(n - 2)
Return the sum of both choices:
  climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
The final answer is the total number of distinct ways.
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        int one = climbStairs(n-1);
        int two = climbStairs(n-2);

        return one + two;
    }
};




// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[n] stores the number of ways to reach the nth stair.
Base cases:
  If n < 0, return 0 (invalid path).
  If n == 0, return 1 (one valid way).
If dp[n] is already computed, return it.
From the current stair, there are two choices:
  Take 1 step → solve(n-1)
  Take 2 steps → solve(n-2)
Store and return:
  dp[n] = solve(n-1) + solve(n-2)
The answer is solve(n).
*/
class Solution {
public:

    int solve(int n, vector<int> &dp){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        if(n == 0) return 1;

        int one = solve(n-1, dp);
        int two = solve(n-2, dp);

        return dp[n] = one + two;

    }

    int climbStairs(int n) {
      
        vector<int> dp(n+1, -1);
        return solve(n, dp);
      
    }
};




// TABULATION / BOTTOM-UP ->
/*
Create a dp array where dp[i] stores the number of ways to reach stair i.
Initialize the base cases:
  dp[0] = 1
  dp[1] = 1
  dp[2] = 2
For every stair from 3 to n:
  Compute:
  dp[i] = dp[i-1] + dp[i-2]
Return dp[n].
*/
class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1);

        dp[0] = 1;

        if(n >= 1) dp[1] = 1;

        if(n >= 2) dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};




// SPACE OPTIMISED ->
/*
Handle the base cases:
  n = 0 → 1
  n = 1 → 1
  n = 2 → 2
Instead of a DP array, keep only the last two computed values.
Initialize:
  ways1 = 1 (ways for stair 1)
  ways2 = 2 (ways for stair 2)
For each stair from 3 to n:
  Compute:
  curr = ways1 + ways2
  Shift the values:
    ways1 = ways2
    ways2 = curr
Return ways2, which stores the number of ways to reach the nth stair.
*/
class Solution {
public:
    int climbStairs(int n) {

        if(n == 0) return 1;

        if(n == 1) return 1;

        if(n == 2) return 2;

        int ways0 = 1;
        int ways1 = 1;
        int ways2 = 2;

        for(int i = 3; i <= n; i++){

            int curr = ways1 + ways2;

            ways1 = ways2;
            ways2 = curr;
        }

        return ways2;

    }
};
