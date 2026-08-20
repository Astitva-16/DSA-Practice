/*416. Partition Equal Subset Sum
LeetCode link -> https://leetcode.com/problems/partition-equal-subset-sum/
*/

// RECUSRION ->
/*
First calculate the total sum of the array:

int sum = 0;
for(int i = 0; i < n; i++){
    sum += nums[i];
}

For the array to be divided into two subsets with equal sum, total sum must be even.

if(sum % 2 != 0) return false;

If total sum is odd, it is impossible to divide it equally.

If total sum is even, each subset must have:

target = sum / 2;

Now the problem becomes a Subset Sum problem:

Can we find a subset whose sum is sum/2?

solve(i, target) means:

Can we make target using elements from index 0...i?

Base case:

if(target == 0) return true;

Target 0 can always be achieved by selecting nothing.

If only nums[0] is available:

if(i == 0)
    return target == nums[0];
For every number nums[i], we have two choices.

Don't take nums[i]:

bool not_take = solve(i - 1, target, nums, n);
Take nums[i] if it doesn't exceed the target:
if(target >= nums[i])
    take = solve(i - 1, target - nums[i], nums, n);
If either choice can form the target:
return take || not_take;
Start with:
solve(n - 1, sum / 2, nums, n)

because initially all elements are available.
*/
class Solution {
public:

    bool solve(int i, int target, vector<int>& nums, int n){

        if(target == 0) return true;

        if(i == 0) return (target == nums[0]);

        bool not_take = solve(i - 1, target, nums, n);

        bool take = false;

        if(target >= nums[i]){
            take = solve(i - 1, target - nums[i], nums, n);
        }

        return (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        return solve(n - 1, sum / 2, nums, n);
    }
};




// MEMOIZATION ->
/*
First calculate the total sum of the array.

int sum = 0;
for(int i = 0; i < n; i++){
    sum += nums[i];
}

If total sum is odd, equal partition is impossible:

if(sum % 2 != 0) return false;

If total sum is even, both subsets must have:

target = sum / 2;

Now it becomes a Subset Sum problem:

Can we select some elements whose sum is target?

DP state:

dp[i][target]

means:

Can we make target using elements from index 0 to i?

Base case:

if(target == 0) return true;

Sum 0 is always possible by taking nothing.

When only nums[0] is available:

if(i == 0)
    return target == nums[0];

Before calculating a state, check whether we already solved it:

if(dp[i][target] != -1)
    return dp[i][target];

Not take nums[i]:

bool not_take = solve(i - 1, target, nums, n, dp);

We move to the previous element, but target stays the same.

Take nums[i]:
if(target >= nums[i])
    take = solve(i - 1, target - nums[i], nums, n, dp);

After taking nums[i], remaining target becomes:

target - nums[i]
If either option works:
take || not_take
Store the result:
dp[i][target] = take || not_take;
DP table size:
vector<vector<int>> dp(
    n,
    vector<int>((sum / 2) + 1, -1)
);

Why sum/2 + 1?

Because target ranges from:

0 → sum/2
Finally:
return solve(n - 1, sum / 2, nums, n, dp);

We start with the last index and the required half-sum.
*/
class Solution {
public:

    bool solve(int i, int target, vector<int>& nums, int n, vector<vector<int>>& dp){

        if(target == 0) return true;

        if(i == 0) return (target == nums[0]);

        if(dp[i][target] != -1) return dp[i][target];

        bool not_take = solve(i - 1, target, nums, n, dp);

        bool take = false;

        if(target >= nums[i]){
            take = solve(i - 1, target - nums[i], nums, n, dp);
        }

        return dp[i][target] = (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));

        return solve(n - 1, sum / 2, nums, n, dp);
    }
};




// TABULATION ->
/*
Calculate total sum of the array:

int sum = 0;
for(int i = 0; i < n; i++){
    sum += nums[i];
}

Check if total sum is odd.

if(sum % 2 != 0) return false;

If sum is odd, it can never be divided into two equal integer sums.

Since both subsets must have equal sum:

target = sum / 2;

So now the problem becomes:

Can we make target using some elements of nums?

Create the DP table:

vector<vector<bool>> dp(
    n,
    vector<bool>(target + 1, false)
);

Meaning:

dp[i][j] = Can we make sum j using elements 0...i?

Initialize sum 0:

for(int i = 0; i < n; i++)
    dp[i][0] = true;

Every row has true for sum 0 because we can always choose nothing.

Initialize the first element:

if(nums[0] <= target)
    dp[0][nums[0]] = true;

With only nums[0], we can form exactly nums[0].

Start from the second element:

for(int i = 1; i < n; i++)
For every possible target j, there are two choices.

Take nums[i]:

Only possible when:

if(j >= nums[i])

If we take it, we need to previously form:

j - nums[i]

Therefore:

take = dp[i - 1][j - nums[i]];
Don't take nums[i]:
not_take = dp[i - 1][j];
If either choice works:
dp[i][j] = take || not_take;
Finally:
return dp[n - 1][target];
*/
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        vector<vector<bool>> dp(n, vector<bool>((sum / 2) + 1, false));

        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        if(nums[0] <= sum / 2) dp[0][nums[0]] = true;
        
        for(int i = 1; i < n; i++){
            
            for(int j = 1; j <= sum / 2; j++){
                
                bool take = false;
        
                if(j >= nums[i]){
                    take = dp[i - 1][j - nums[i]];
                }
                
                bool not_take = dp[i - 1][j];
                
                dp[i][j] = (take || not_take);
            }
        }

        return dp[n - 1][sum / 2];
    }
};
