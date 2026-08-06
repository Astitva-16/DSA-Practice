/*746. Min Cost Climbing Stairs
LeetCode link -> https://leetcode.com/problems/min-cost-climbing-stairs/?envType=problem-list-v2&envId=ab27r7qc
*/

// RECURSION ->
/*
Start from step 0 or step 1, since both are valid starting points.
Define solve(i) as the minimum cost to reach the top starting from step i.
If i >= n, return 0 because the top has been reached.
From the current step, there are two choices:
  Climb 1 step: cost[i] + solve(i + 1)
  Climb 2 steps: cost[i] + solve(i + 2)
Return the minimum of these two choices.
The final answer is min(solve(0), solve(1)).
*/

class Solution {
public:

    int solve(vector<int>& cost, int i, int n){
        if(i >= n) return 0;

        int step1 = cost[i] + solve(cost, i + 1, n);
        int step2 = cost[i] + solve(cost, i + 2, n);

        return min(step1, step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return min(solve(cost, 0, n), solve(cost, 1, n));
    }
};



// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i] stores the minimum cost to reach the top starting from step i.
If i >= n, return 0 (top reached).
If dp[i] is already computed, return it.
From the current step, there are two choices:
  Take 1 step: cost[i] + solve(i + 1)
  Take 2 steps: cost[i] + solve(i + 2)
Store the minimum of these two costs in dp[i].
Since you can start from step 0 or 1, return:
min(solve(0), solve(1)).
*/

class Solution {
public:

    int solve(vector<int>& cost, int i, int n, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int step1 = cost[i] + solve(cost, i + 1, n, dp);
        int step2 = cost[i] + solve(cost, i + 2, n, dp);

        return dp[i] = min(step1, step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(cost, 0, n, dp), solve(cost, 1, n, dp));
    }
};



// TABULATION / BOTTOM-UP
/*
Create a dp array where dp[i] stores the minimum cost to reach step i.
Initialize:
  dp[0] = cost[0]
  dp[1] = cost[1]
Traverse all steps:
  From step i, update the cost to reach:
    i + 1
    i + 2
  Take the minimum cost if multiple paths reach the same step.
Since the top is just beyond the last step, you can reach it from either the last or second last step.
Return min(dp[n-1], dp[n-2]).
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n == 2) return min(cost[0], cost[1]);

        vector<int> dp(n, INT_MAX);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 0; i < n; i++){

            if(i + 1 < n){
                dp[i + 1] = min(dp[i + 1], dp[i] + cost[i + 1]);
            }

            if(i + 2 < n){
                dp[i + 2] = min(dp[i + 2], dp[i] + cost[i + 2]);
            }
        }

        return min(dp[n - 1], dp[n - 2]);

        
    }
};
