/*2770. Maximum Number of Jumps to Reach the Last Index
LeetCode link -> https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
*/

// RECURSION
/*
Start recursion from index 0.
If the current index is the last index, return 0 (no more jumps needed).
Try jumping to every index j > i.
A jump is valid only if abs(nums[j] - nums[i]) <= target.
For every valid jump, recursively find the maximum jumps from j and update:
  ans = max(ans, 1 + solve(j)).
Return the maximum jumps possible from the current index.
If no valid path reaches the last index, return -1.
*/

class Solution {
public:

    int solve(int i, int n, vector<int>& nums, int target){
        if(i == n - 1) return 0;

        int ans = INT_MIN;

        for(int j = i + 1; j < n; j++){
            if(abs(nums[j] - nums[i]) <= target){
                ans = max(ans, 1 + solve(j, n, nums, target));
            }
        }

        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        int ans = solve(0, n, nums, target);

        return (ans < 0) ? -1 : ans;
    }
};



// MEMOIZATION
/*
Use DFS + Memoization, where dp[i] stores the maximum jumps possible from index i to the last index.
If the current index is the last index, return 0.
If dp[i] is already computed, return it.
Try jumping to every index j > i.
A jump is valid only if abs(nums[j] - nums[i]) <= target.
For every valid jump, compute:
  ans = max(ans, 1 + solve(j)).
Store the result in dp[i] and return it.
If the answer from index 0 is negative, return -1; otherwise return the maximum jumps.
*/

class Solution {
public:

    int solve(int i, int n, vector<int>& nums, int target, vector<int>& dp){
        if(i == n - 1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN;

        for(int j = i + 1; j < n; j++){
            if(abs(nums[j] - nums[i]) <= target){
                ans = max(ans, 1 + solve(j, n, nums, target, dp));
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = solve(0, n, nums, target, dp);

        return (ans < 0) ? -1 : ans;
    }
};



// TABULATION / BOTTOM-UP
/*
Create a dp array where dp[i] stores the maximum jumps needed to reach index i.
Initialize all values to -1 (unreachable) and set dp[0] = 0 since we start at index 0.
Traverse each index i:
  If dp[i] == -1, skip it because it cannot be reached.
For every j > i:
  If abs(nums[j] - nums[i]) <= target, a jump is valid.
  Update:
  dp[j] = max(dp[j], dp[i] + 1).
After filling the DP array, dp[n-1] stores the maximum jumps to reach the last index.
If dp[n-1] == -1, the last index is unreachable; otherwise return dp[n-1].
*/

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);

        dp[0] = 0;

        for(int i = 0; i < n; i++){
            if(dp[i] == -1) continue;

            for(int j = i + 1; j < n; j++){
                if(abs(nums[j] - nums[i]) <= target){
                    dp[j] = max(dp[j] , dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
