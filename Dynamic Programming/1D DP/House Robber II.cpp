/*213. House Robber II
LeetCode link -> https://leetcode.com/problems/house-robber-ii
*/

// RECURSION ->
/*
Since the houses are circular, the first and last house cannot both be robbed.
Handle base cases:
  If n == 1, return nums[0].
  If n == 2, return max(nums[0], nums[1]).
Solve two separate cases:
  Case 1: Rob from houses 0 to n-2 (exclude the last house).
  Case 2: Rob from houses 1 to n-1 (exclude the first house).
For each case, use the House Robber recursion:
  Steal current house → nums[i] + solve(i+2)
  Skip current house → solve(i+1)
  Return the maximum of the two choices.
Return the maximum of the two cases.
*/
class Solution {
public:

    int solve(int i, int n, vector<int>& nums){
        if(i >= n) return 0;

        int steal = nums[i] + solve(i + 2, n, nums);
        int skip = solve(i + 1, n, nums);

        return max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        int take0 = solve(0, n - 1, nums);

        int not_take0 = solve(1, n, nums);

        return max(take0, not_take0);
    }
};




// MEMOIZATION ->
/*
Since the houses are circular, the first and last house cannot both be robbed.
Handle base cases:
  n == 1 → return nums[0]
  n == 2 → return max(nums[0], nums[1])
Solve two independent House Robber problems using memoization:
  Case 1: Rob houses from 0 to n-2 (exclude the last house).
  Case 2: Rob houses from 1 to n-1 (exclude the first house).
Use DFS + Memoization, where dp[i] stores the maximum money that can be robbed starting from house i.
At each house, choose:
  Steal: nums[i] + solve(i + 2)
  Skip: solve(i + 1)
  Store the maximum in dp[i].
Return the maximum of the two cases.
*/
class Solution {
public:

    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(i + 2, n, nums, dp);
        int skip = solve(i + 1, n, nums, dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n - 1, -1);

        int take0 = solve(0, n - 1, nums, dp1);

        vector<int> dp2(n, -1);

        int not_take0 = solve(1, n, nums, dp2);

        return max(take0, not_take0);
    }
};




// TABULATION / BOTTOM-UP
/*
Since the houses are circular, the first and last house cannot both be robbed.
Handle the base case:
  If n == 1, return nums[0].
Solve two linear House Robber problems:
  Case 1: Rob houses from 0 to n-2 (exclude the last house).
  Case 2: Rob houses from 1 to n-1 (exclude the first house).
For each range, create a dp array where dp[i] stores the maximum money that can be robbed up to that house.
At each house, choose:
  Steal: currentHouse + dp[i-2]
  Skip: dp[i-1]
  Store the maximum in dp[i].
Return the maximum of the two cases.
*/
class Solution {
public:
   
    int robRange(vector<int>& nums, int start, int end){

        int len = end - start + 1;

        if(len == 1) return nums[start];

        vector<int> dp(len);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for(int i = 2; i < len; i++){

            dp[i] = max(dp[i-1], nums[start+i] + dp[i-2]);

        }

        return dp[len-1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        return max(robRange(nums,0,n-2), robRange(nums,1,n-1));
    }
};
