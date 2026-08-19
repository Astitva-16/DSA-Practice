/*312. Burst Balloons
LeetCode link -> https://leetcode.com/problems/burst-balloons/
*/

// RECURSION ->
/*
Add 1 at both ends:

nums.insert(nums.begin(), 1);
nums.push_back(1);

These act as boundary balloons.

solve(i,j) = maximum coins obtained by bursting all balloons from index i to j.
Instead of thinking which balloon to burst first, think:
which balloon k will be burst LAST in the interval [i,j].

If k is the last balloon burst:

coins = nums[i-1] * nums[k] * nums[j+1];

Why? By the time k is burst, all balloons between i and j are already gone, so its remaining neighbors are i-1 and j+1.

Split the problem:

left  = solve(i, k-1)
right = solve(k+1, j)

Total:

total = left + coins + right;
Try every k as the last balloon and take the maximum.

Base case:

if(i > j) return 0;

No balloons left → 0 coins.
*/
class Solution {
public:

    int solve(int i, int j, vector<int>& nums) {

        if(i > j) return 0;

        int ans = 0;

        for(int k = i; k <= j; k++) {

            int coins = nums[i - 1] * nums[k] * nums[j + 1];

            int left = solve(i, k - 1, nums);

            int right = solve(k + 1, j, nums);

            int total = left + coins + right;

            ans = max(ans, total);
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        return solve(1, n - 2, nums);
    }
};




// MEMOIZATION ->
/*
Add 1 at both ends of nums as boundary balloons.

Define:

dp[i][j]

= maximum coins obtained by bursting all balloons from i to j.

Base case:

if(i > j) return 0;

No balloons remain → 0 coins.

If dp[i][j] is already calculated, return it.
Important idea: Choose the balloon k that will be burst LAST, not first.

When k is burst last, all balloons between i and j are already gone. Therefore its neighbors are:

nums[i-1] and nums[j+1]

So:

coins = nums[i-1] * nums[k] * nums[j+1];

Split the interval:

left  = solve(i, k-1)
right = solve(k+1, j)

Total:

total = left + coins + right;

Try every k as the last balloon and take the maximum:

dp[i][j] = max(dp[i][j], total);
Final answer:
solve(1, n-2)
*/
class Solution {
public:

    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        for(int k = i; k <= j; k++) {

            int coins = nums[i - 1] * nums[k] * nums[j + 1];

            int left = solve(i, k - 1, nums, dp);

            int right = solve(k + 1, j, nums, dp);

            int total = left + coins + right;

            ans = max(ans, total);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(1, n - 2, nums, dp);
    }
};




// TABULATION ->
/*
Add 1 at both ends of nums as boundary balloons.

Define:

dp[i][j]

= maximum coins obtained by bursting all balloons from i to j.

dp[i][i] represents bursting one balloon, and empty intervals are already 0.

Fill the DP table by increasing interval length:

len = 1 → n-2

because dp[i][j] depends on smaller intervals.

For every interval [i,j], try every balloon k as the last balloon to burst.

Since k is last, its neighbors are nums[i-1] and nums[j+1]:

coins = nums[i-1] * nums[k] * nums[j+1];

Add the two already-solved intervals:

total = dp[i][k-1] + coins + dp[k+1][j];

Take the maximum:

dp[i][j] = max(dp[i][j], total);

Finally:

dp[1][n-2]

gives the maximum coins.
*/
class Solution {
public:

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int len = 1; len <= n - 2; len++){

            for(int i = 1; i + len - 1 <= n - 2; i++){

                int j = i + len - 1;

                for(int k = i; k <= j; k++){

                    int coins = nums[i - 1] * nums[k] * nums[j + 1];

                    int total = dp[i][k - 1] + coins + dp[k + 1][j];

                    dp[i][j] = max(dp[i][j], total);
                }
            }
        }

        return dp[1][n - 2];
    }
};
