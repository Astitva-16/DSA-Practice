/*198. House Robber
LeetCode link -> https://leetcode.com/problems/house-robber
*/

// RECURSION ->
/*
Start recursion from house 0.
If the current index i is beyond the last house (i >= n), return 0.
At every house, there are two choices:
  Steal the current house: nums[i] + solve(i + 2) (skip the adjacent house).
  Skip the current house: solve(i + 1).
Return the maximum of these two choices.
The answer is the maximum money that can be robbed starting from house 0.
*/

class Solution {
public:

    int solve(int i, int n, vector<int>& nums){
        if(i >= n) return 0;

        int steal = nums[i] + solve(i + 2, n, nums);
        int skip = solve(i + 1, n, nums);

        return max(skip, steal);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(0, n, nums);
    }
};



// MEMOIZATION ->
/*
Use DFS + Memoization, where dp[i] stores the maximum money that can be robbed starting from house i.
If i >= n, return 0 (no houses left).
If dp[i] is already computed, return it.
At each house, there are two choices:
  Steal the current house: nums[i] + solve(i + 2) (skip the adjacent house).
  Skip the current house: solve(i + 1).
Store and return:
  dp[i] = max(steal, skip).
The answer is solve(0).
*/

class Solution {
public:

    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(i + 2, n, nums, dp);
        int skip = solve(i + 1, n, nums, dp);

        return dp[i] = max(skip, steal);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, n, nums, dp);
    }
};



// TABULATION / BOTTOM-UP
/*
Create a dp array where dp[i] stores the maximum money that can be robbed from houses 0 to i.
Initialize the base cases:
  dp[0] = nums[0]
  dp[1] = max(nums[0], nums[1])
For each house from i = 2 to n-1:
  Steal the current house:
    nums[i] + dp[i-2]
  Skip the current house:
    dp[i-1]
  Store:
    dp[i] = max(steal, skip)
Return dp[n-1], which is the maximum money that can be robbed.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MIN);

        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int steal = nums[i] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }

        return dp[n - 1];
    }
};
