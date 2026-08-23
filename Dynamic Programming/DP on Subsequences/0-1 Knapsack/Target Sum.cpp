/*494. Target Sum
LeetCode link -> https://leetcode.com/problems/target-sum/
*/

// RECURSION ->
/*
solve(i, sum) → number of ways to assign + / - to elements from index i onward to reach target.

Base case: when all elements are processed:

if(i == n)
    return sum == target;
For every number, we have 2 choices:

Add it:

sum + nums[i]

Subtract it:

sum - nums[i]

Recursively calculate both:

int add = solve(i + 1, sum + nums[i], ...);
int sub = solve(i + 1, sum - nums[i], ...);

Total number of valid ways:

return add + sub;

Start from:

solve(0, 0, target, nums, n);

Initially, sum is 0.
*/
class Solution {
public:

    int solve(int i, int sum, int target, vector<int>& nums, int n){
        
        if(i == n){

            if(sum == target){
                return 1;
            }

            return 0;
        }

        int add = solve(i + 1, sum + nums[i], target, nums, n);

        int sub = solve(i + 1, sum - nums[i], target, nums, n);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return solve(0, 0, target, nums, n);
    }
};




// MEMOIZATION ->
/*
State: dp[i][sum + total] → number of ways to reach target from index i with current sum.

Why + total?
sum can be negative, so we shift it:

index = sum + total;

This converts range [-total, total] → [0, 2*total].

Base case:

if(i == n)
    return sum == target;

If all elements are processed, this path is valid only if sum == target.

Memoization:
If (i, sum) was already calculated:

if(dp[i][index] != -1)
    return dp[i][index];

Every number has 2 choices:

add = solve(i+1, sum + nums[i], ...)
sub = solve(i+1, sum - nums[i], ...)

Store total ways:

dp[i][index] = add + sub;

Important optimization:

if(abs(target) > total) return 0;

If target is outside [-total, total], it's impossible.
*/
class Solution {
public:

    int solve(int i, int sum, int target, int total, vector<int>& nums, int n, vector<vector<int>>& dp){
        
        if(i == n){

            if(sum == target){
                return 1;
            }

            return 0;
        }

        int index = sum + total;

        if(dp[i][index] != -1) return dp[i][index];

        int add = solve(i + 1, sum + nums[i], target, total, nums, n, dp);

        int sub = solve(i + 1, sum - nums[i], target, total, nums, n, dp);

        return dp[i][index] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;

        for(int x : nums) total += x;

        // If target is outside possible range
        if(abs(target) > total) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(0, 0, target, total, nums, n, dp);
    
    }
};
