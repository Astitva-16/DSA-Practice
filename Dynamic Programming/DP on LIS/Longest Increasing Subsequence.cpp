/*300. Longest Increasing Subsequence
LeetCode link -> https://leetcode.com/problems/longest-increasing-subsequence/
*/

// RECURSION ->
/*
solve(i, prev) = maximum length of an increasing subsequence from index i onward, where prev is the index of the previously selected element.
At every index, we have 2 choices:
  Take: if prev == -1 or nums[i] > nums[prev], include nums[i].
  Skip: don't include nums[i].
If we take:
take = 1 + solve(i + 1, i)
If we skip:
skip = solve(i + 1, prev)
Return max(take, skip).
Start with prev = -1 because initially no element has been selected.
*/
class Solution {
public:

    int solve(int i, int prev, vector<int>& nums, int n){
        if(i >= n) return 0;

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(i + 1, i, nums, n);
        }

        int skip = solve(i + 1, prev, nums, n);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        return solve(0, -1, nums, n);
    }
};




// MEMOIZATION ->
/*
solve(i, prev) = maximum LIS length from index i onward, where prev is the index of the previously selected element.
At every index, there are 2 choices:
  Take: if prev == -1 or nums[i] > nums[prev].
  Skip: don't take nums[i].
If we take:
take = 1 + solve(i + 1, i)
If we skip:
skip = solve(i + 1, prev)
Return:
max(take, skip).
dp[i][prev] stores the answer for the state (i, prev).
Since prev = -1 cannot be used as a vector index, you don't memoize that initial state. All subsequent states have prev >= 0.
*/
class Solution {
public:

    int solve(int i, int prev, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(i >= n) return 0;

        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(i + 1, i, nums, n, dp);
        }

        int skip = solve(i + 1, prev, nums, n, dp);

        if(prev != -1) return dp[i][prev] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, -1, nums, n, dp);
    }
};




// BOTTOM UP ->
/*
dp[i] = length of the longest increasing subsequence ending at index i.
Initialize every dp[i] = 1 because every individual element is an LIS of length 1.
For every i, check all previous indices j < i.
If nums[j] < nums[i], then nums[i] can be added after the LIS ending at j:
dp[i] = max(dp[i], dp[j] + 1).
Keep track of the overall maximum maxLIS.
Return maxLIS.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        int maxLIS = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        return maxLIS;
    }
};
